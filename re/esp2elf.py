"""Wrap an ESP32 app image's segments into a minimal Xtensa ELF so Ghidra can load it."""
import struct, sys

src, dst = sys.argv[1], sys.argv[2]
d = open(src, 'rb').read()
assert d[0] == 0xE9
nseg, entry = d[1], struct.unpack('<I', d[4:8])[0]
off, segs = 24, []
for _ in range(nseg):
    addr, ln = struct.unpack('<II', d[off:off + 8])
    segs.append((addr, d[off + 8:off + 8 + ln]))
    off += 8 + ln
for a, b in segs:
    print(f"seg 0x{a:08x} len 0x{len(b):06x}")

PF = {True: 5, False: 6}  # R+X for instruction buses, R+W otherwise
ehsize, phsize = 52, 32
data_off = ehsize + phsize * len(segs)
ph, blob = b'', b''
for a, b in segs:
    execu = 0x40000000 <= a < 0x40400000 or 0x400D0000 <= a < 0x40400000
    ph += struct.pack('<IIIIIIII', 1, data_off + len(blob), a, a, len(b), len(b), PF[execu], 4)
    blob += b
eh = b'\x7fELF\x01\x01\x01' + b'\0' * 9
eh += struct.pack('<HHIIIIIHHHHHH', 2, 94, 1, entry, ehsize, 0, 0, ehsize, phsize, len(segs), 40, 0, 0)
open(dst, 'wb').write(eh + ph + blob)
