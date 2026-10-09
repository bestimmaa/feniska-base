// requested 400d7e80 body [[400d7e80, 400d7e91] [400d7e94, 400d7f09]]
// callees: FUN_400eaa30 FUN_400eabd4 FUN_400d7e40 FUN_400eaa20 FUN_400eac04 
// callers: FUN_400d80b4 FUN_400d8040 FUN_400d7fc4 FUN_400d7f58 FUN_400d7f0c 

undefined4 FUN_400d7e80(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  
  while (iVar2 = FUN_400eaa30(*param_1), iVar2 == 1) {
    FUN_400eabd4();
  }
  uVar3 = FUN_400d7e40(param_1);
  iVar2 = FUN_400d7e40(param_1);
  uVar4 = FUN_400d7e40(param_1);
  cVar1 = param_1[2];
  uVar4 = uVar3 << 0x10 | iVar2 << 8 | uVar4;
  cVar6 = '\x01';
  if (((cVar1 != -0x80) && (cVar6 = '\x03', cVar1 != '@')) && (cVar6 = '\x01', cVar1 == ' ')) {
    cVar6 = '\x02';
  }
  do {
    FUN_400eaa20(param_1[1],1);
    cVar6 = cVar6 + -1;
    FUN_400eaa20(param_1[1],0);
  } while (cVar6 != '\0');
  if ((uVar3 & 0x80) != 0) {
    uVar4 = uVar4 | DAT_400d05fc;
  }
  uVar5 = FUN_400eac04();
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  (*DAT_400d0600)(uVar4);
  uVar5 = (*DAT_400d0604)();
  return uVar5;
}


