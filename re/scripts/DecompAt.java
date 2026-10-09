// Decompile functions at given addresses; creates a function if none exists
// (walking back from the address to the nearest Xtensa `entry` instruction).
// Args: <outdir> <addr1> <addr2> ...   (hex, no 0x). Writes <outdir>/F_<addr>.c and prints callees.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class DecompAt extends GhidraScript {
    Address findEntry(Address a) throws Exception {
        Memory mem = currentProgram.getMemory();
        // Xtensa entry: byte0 = 0x36, byte1 low nibble: (imm12<<12 | as<<8 | 0x36) -> b0=0x36, b1&0x0f == 0x1 (as=a1)
        for (int back = 0; back < 0x4000; back++) {
            Address c = a.subtract(back);
            if ((c.getOffset() & 3) != 0) continue; // entries are 4-byte aligned in esp32 gcc output
            byte b0 = mem.getByte(c); byte b1 = mem.getByte(c.add(1));
            if ((b0 & 0xff) == 0x36 && (b1 & 0x0f) == 0x01) return c;
        }
        return null;
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args[0]);
        outDir.mkdirs();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (int i = 1; i < args.length; i++) {
            Address a = toAddr(args[i]);
            Function f = getFunctionAt(a);
            if (f == null) f = getFunctionContaining(a);
            if (f == null) {
                Address e = getInstructionAt(a) != null && getInstructionAt(a).getMnemonicString().equals("entry") ? a : findEntry(a);
                if (e == null) { println("NO ENTRY for " + a); continue; }
                new DisassembleCommand(e, null, true).applyTo(currentProgram, monitor);
                CreateFunctionCmd cmd = new CreateFunctionCmd(e);
                if (!cmd.applyTo(currentProgram, monitor)) { println("create failed at " + e + ": " + cmd.getStatusMsg()); }
                f = getFunctionAt(e);
                if (f == null) { println("NO FUNC for " + a + " entry " + e); continue; }
                println("CREATED " + f.getName() + " for " + a);
            }
            DecompileResults res = di.decompileFunction(f, 180, monitor);
            File out = new File(outDir, f.getName() + ".c");
            try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
                w.println("// requested " + a + " body " + f.getBody());
                StringBuilder sb = new StringBuilder();
                for (Function c : f.getCalledFunctions(monitor)) sb.append(c.getName()).append(' ');
                w.println("// callees: " + sb);
                StringBuilder sc = new StringBuilder();
                for (Function c : f.getCallingFunctions(monitor)) sc.append(c.getName()).append(' ');
                w.println("// callers: " + sc);
                w.println(res.decompileCompleted() ? res.getDecompiledFunction().getC() : "// decompile failed: " + res.getErrorMessage());
            }
            println("WROTE " + out);
        }
    }
}
