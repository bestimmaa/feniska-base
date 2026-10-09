// requested 400d58b4 body [[400d58b4, 400d5935]]
// callees: FUN_400e9b38 FUN_400dde50 FUN_400ea194 FUN_400e99ac FUN_400f4a20 FUN_40169fc0 
// callers: FUN_400d5fd8 FUN_400d6188 FUN_400d64b0 FUN_400d6138 

void FUN_400d58b4(void)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_44,PTR_s_deviceuuid_400d0318);
  FUN_400dde50(auStack_34,DAT_400d031c,auStack_44);
  iVar2 = FUN_400ea194(auStack_34,DAT_400d01c8);
  FUN_400e99ac(auStack_34);
  FUN_400e99ac(auStack_44);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    do {
      FUN_400e99ac(auStack_44);
      (*(code *)PTR_FUN_400d002c)(iVar2 != 0);
    } while( true );
  }
  return;
}


