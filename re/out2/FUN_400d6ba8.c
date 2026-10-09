// requested 400d6ba8 body [[400d6ba8, 400d6bfd]]
// callees: FUN_400e99ac FUN_400f4a20 FUN_40169fc0 FUN_400ea330 FUN_400e9b38 
// callers: FUN_4016d658 FUN_4016cefc FUN_400d7704 

void FUN_400d6ba8(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,param_2);
  uVar2 = FUN_400ea330(param_1,auStack_34);
  FUN_400e99ac(auStack_34);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    (*(code *)PTR_FUN_400d002c)(uVar2);
  }
  return;
}


