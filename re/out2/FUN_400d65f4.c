// requested 400d65f4 body [[400d65f4, 400d6649]]
// callees: FUN_400e9b38 FUN_400e99ac FUN_400f4a20 FUN_400d64b0 FUN_40169fc0 
// callers: 

void FUN_400d65f4(void)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,PTR_DAT_400d0358);
  FUN_400d64b0(1,auStack_34);
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


