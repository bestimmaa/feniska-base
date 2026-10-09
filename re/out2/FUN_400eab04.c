// requested 400eab04 body [[400eab04, 400eab3f]]
// callees: FUN_400ed694 FUN_400ed32c 
// callers: FUN_400d7140 FUN_400d7704 FUN_400d5fd8 

void FUN_400eab04(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 & 0xff;
  if (uVar1 < 0x10) {
    iVar2 = 1 << 0x20 - (0x20 - (*(byte *)(DAT_400d12c4 + uVar1) & 0x1f));
    if (param_2 == iVar2 + -1) {
      param_2 = iVar2;
    }
    FUN_400ed694(uVar1 >> 3,param_1 & 7,param_2);
    FUN_400ed32c(uVar1 >> 3,param_1 & 7);
  }
  return;
}


