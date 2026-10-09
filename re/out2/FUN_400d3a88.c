// requested 400d3a88 body [[400d3a88, 400d3ad9]]
// callees: FUN_40169fc0 FUN_400f4a20 FUN_400e99ac FUN_400d3834 FUN_400e9b38 
// callers: FUN_400d7950 FUN_400d7704 FUN_400d7140 FUN_400d4500 FUN_400d6188 

void FUN_400d3a88(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,param_2);
  FUN_400d3834(param_1,auStack_34);
  FUN_400e99ac(auStack_34);
  memw();
  memw();
  iVar2 = *piVar1;
  if (iStack_24 != iVar2) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    (*(code *)PTR_FUN_400d002c)(iVar2);
  }
  return;
}


