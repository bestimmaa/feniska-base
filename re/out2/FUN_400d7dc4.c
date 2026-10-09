// requested 400d7dc4 body [[400d7dc4, 400d7de9]]
// callees: FUN_400d7db4 FUN_400d7da0 
// callers: FUN_400d7e14 FUN_400d7dec 

void FUN_400d7dc4(int param_1)

{
  FUN_400d7da0(param_1);
  FUN_400d7db4(param_1);
  *(undefined4 *)(param_1 + 8) = DAT_400d0284;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 2) = 0x80;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return;
}


