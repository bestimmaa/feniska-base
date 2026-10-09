// Decompile every function that references one of the given strings (via Xtensa l32r literal pools).
// Args: <outdir> <string1> <string2> ...
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class DumpByStrings extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args[0]);
        outDir.mkdirs();
        Memory mem = currentProgram.getMemory();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Set<Function> done = new HashSet<>();
        PrintWriter index = new PrintWriter(new FileWriter(new File(outDir, "index.txt")));
        for (int i = 1; i < args.length; i++) {
            String s = args[i];
            byte[] needle = (s + "\0").getBytes("UTF-8");
            Address a = mem.findBytes(mem.getMinAddress(), needle, null, true, monitor);
            if (a == null) { index.println("NOT FOUND: " + s); continue; }
            // also accept matches that are a suffix-free substring start: search pointer to string start
            long target = a.getOffset();
            byte[] ptr = new byte[]{(byte) target, (byte) (target >> 8), (byte) (target >> 16), (byte) (target >> 24)};
            Address p = mem.getMinAddress();
            while ((p = mem.findBytes(p, ptr, null, true, monitor)) != null) {
                for (Reference r : getReferencesTo(p)) {
                    Function f = getFunctionContaining(r.getFromAddress());
                    if (f == null) { index.println(s + " @ " + r.getFromAddress() + " (no function)"); continue; }
                    index.println(s + " -> " + f.getName() + " @ " + f.getEntryPoint());
                    if (done.add(f)) {
                        DecompileResults res = di.decompileFunction(f, 120, monitor);
                        try (PrintWriter w = new PrintWriter(new FileWriter(new File(outDir, f.getName() + ".c")))) {
                            w.println("// refs: " + s);
                            w.println(res.decompileCompleted() ? res.getDecompiledFunction().getC() : "// decompile failed: " + res.getErrorMessage());
                        }
                    }
                }
                p = p.add(1);
            }
        }
        index.close();
    }
}
