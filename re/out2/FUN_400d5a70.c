// requested 400d5a70 body [[400d5a70, 400d5a8b]]
// callees: FUN_4008bfa8 FUN_400eb018 
// callers: FUN_400d4b74 FUN_400d5190 

undefined4 FUN_400d5a70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [68];
  
  iVar1 = FUN_400eb018(auStack_44,DAT_400d01c0);
  uVar2 = 0;
  if (iVar1 != 0) {
    FUN_4008bfa8(&uStack_48);
    uVar2 = uStack_48;
  }
  return uVar2;
}


