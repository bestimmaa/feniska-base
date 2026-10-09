// For each call to the given functions, print caller and the most recent immediate loaded into a10/a11/a12 (call8 args).
// Args: <outfile> <funcaddr>...
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class CallArgs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(args[0]));
        for (int i = 1; i < args.length; i++) {
            Address t = toAddr(args[i]);
            w.println("==== calls to " + t);
            for (Reference r : getReferencesTo(t)) {
                if (!r.getReferenceType().isCall()) continue;
                Address from = r.getFromAddress();
                Function f = getFunctionContaining(from);
                Map<String, String> regs = new LinkedHashMap<>();
                Instruction ins = getInstructionAt(from);
                for (int k = 0; k < 12 && ins != null; k++) {
                    ins = ins.getPrevious();
                    if (ins == null) break;
                    String m = ins.getMnemonicString();
                    String s = ins.toString();
                    if (m.startsWith("call") || m.startsWith("ret") || m.equals("j")) break;
                    String[] p = s.split("[ ,]+");
                    if (p.length >= 2 && p[1].matches("a1[0-5]") && !regs.containsKey(p[1])) regs.put(p[1], s);
                }
                w.println(from + " in " + (f == null ? "?" : f.getName()) + " : " + regs.values());
            }
        }
        w.close();
    }
}
