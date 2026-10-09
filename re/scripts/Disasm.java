// Dump disassembly for address ranges. Args: <outfile> <start>:<end> ...
// For l32r, appends the literal value (and string if it points to one).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;

public class Disasm extends GhidraScript {
    String str(long v) {
        try {
            Address a = toAddr(v);
            Memory m = currentProgram.getMemory();
            if (!m.contains(a)) return "";
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 80; i++) { int b = m.getByte(a.add(i)) & 0xff; if (b == 0) break; if (b < 0x20 || b > 0x7e) return ""; sb.append((char) b); }
            return sb.length() >= 3 ? " \"" + sb + "\"" : "";
        } catch (Exception e) { return ""; }
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(args[0]));
        Memory m = currentProgram.getMemory();
        for (int i = 1; i < args.length; i++) {
            String[] p = args[i].split(":");
            Address s = toAddr(p[0]), e = toAddr(p[1]);
            w.println("==== " + s + " - " + e);
            Instruction ins = getInstructionAt(s);
            if (ins == null) ins = getInstructionAfter(s);
            while (ins != null && ins.getAddress().compareTo(e) <= 0) {
                String extra = "";
                if (ins.getMnemonicString().equals("l32r")) {
                    for (int k = 0; k < ins.getNumOperands(); k++) for (Object o : ins.getOpObjects(k)) if (o instanceof Address) {
                        Address la = (Address) o;
                        try { long v = m.getInt(la) & 0xffffffffL; extra = String.format("  ; [%s]=0x%08x (%g)%s", la, v, Float.intBitsToFloat((int) v), str(v)); } catch (Exception ex) {}
                    }
                }
                Function f = null;
                for (var r : ins.getReferencesFrom()) if (r.getReferenceType().isCall()) { f = getFunctionAt(r.getToAddress()); }
                if (f != null) extra += "  ; -> " + f.getName();
                w.println(ins.getAddress() + "  " + ins + extra);
                ins = ins.getNext();
            }
        }
        w.close();
    }
}
