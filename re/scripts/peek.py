#!/usr/bin/env python3
"""peek.py <elf> <addr>... : print 32-bit word at each address (from ELF PT_LOAD segments), plus float and string if any."""
import struct, sys
elf = open(sys.argv[1], 'rb').read()
phoff, = struct.unpack_from('<I', elf, 0x1c); phentsz, phnum = struct.unpack_from('<HH', elf, 0x2a)
segs = []
for i in range(phnum):
    t, off, va, pa, fsz, msz, fl, al = struct.unpack_from('<8I', elf, phoff + i * phentsz)
    if t == 1: segs.append((va, off, fsz))
def rd(a, n):
    for va, off, fsz in segs:
        if va <= a < va + fsz: return elf[off + a - va: off + a - va + n]
    return None
def s(a):
    b = rd(a, 120)
    if not b: return ''
    b = b.split(b'\0')[0]
    return repr(b.decode('latin1')) if len(b) >= 2 and all(32 <= c < 127 or c in (9, 10, 13) for c in b) else ''
for x in sys.argv[2:]:
    a = int(x, 16); b = rd(a, 4)
    if not b: print(x, 'unmapped'); continue
    v, = struct.unpack('<I', b); f, = struct.unpack('<f', b)
    print(f'{a:08x}: {v:08x}  f={f:g}  {s(v)}')
