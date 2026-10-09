// requested 400d3834 body [[400d3834, 400d39a8] [400d39ac, 400d39ad]]
// callees: FUN_40117994 FUN_40176cd8 FUN_400e99ac FUN_40117ad8 FUN_400e9b38 FUN_4008eab8 FUN_400eac04 FUN_400ea1c4 FUN_400ea194 FUN_400e9c88 FUN_400e9554 FUN_400ea0c4 FUN_400d5b00 FUN_400f4a20 FUN_400e86e0 FUN_400ea094 FUN_40169fc0 FUN_401892b0 FUN_40117b50 
// callers: FUN_400d3a88 FUN_400d7950 

void FUN_400d3834(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined1 auStack_41c [16];
  undefined1 auStack_40c [1000];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400d5b00(param_1[7]);
  (**(code **)(*(int *)param_1[1] + 0x2c))((int *)param_1[1],0,0x78,0xf0,0xf);
  pcVar4 = DAT_400d00b4;
  memw();
  memw();
  if ((*DAT_400d00b4 == '\0') && (iVar2 = FUN_40117994(DAT_400d00b4), iVar2 != 0)) {
    uVar3 = FUN_400eac04();
    *DAT_400d00b8 = uVar3;
    FUN_40117ad8(pcVar4);
  }
  iVar2 = FUN_400ea1c4(param_2,PTR_DAT_400d0028);
  if (iVar2 == 0) {
    FUN_400e86e0(*param_1,param_2,2,0x78);
    pcVar4 = (char *)(param_1 + 8);
    iVar2 = FUN_400ea194(param_2,pcVar4);
    if (iVar2 == 0) {
      FUN_400e9c88(pcVar4,param_2);
      iVar2 = FUN_400eac04();
      pcVar4 = (char *)*DAT_400d00b8;
      (*(code *)PTR_FUN_400d00d0)((float)(uint)(iVar2 - (int)pcVar4) / 1.0,DAT_400d00bc);
      uVar5 = (*DAT_400d00d4)();
      (*(code *)PTR_FUN_400d00d8)
                (auStack_40c,PTR_s___1f_400d00c0,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      FUN_400e9b38(auStack_41c,auStack_40c);
      uVar3 = FUN_400ea094(auStack_41c,param_2);
      FUN_400e9c88(param_2,uVar3);
      FUN_400e99ac(auStack_41c);
      FUN_400e9b38(auStack_41c,PTR_DAT_400d00c4);
      uVar3 = FUN_400ea094(auStack_41c,param_2);
      uVar3 = FUN_400ea0c4(uVar3,PTR_DAT_400d00c8);
      FUN_400e9554(DAT_400d00cc,uVar3);
      FUN_400e99ac(auStack_41c);
    }
  }
  FUN_4008eab8(param_1[7],0,0);
  memw();
  memw();
  iVar2 = *piVar1;
  if (iStack_24 != iVar2) {
    FUN_400f4a20();
    FUN_40117b50(pcVar4);
    do {
      (*(code *)PTR_FUN_400d002c)(iVar2);
      FUN_400e99ac(auStack_41c);
    } while( true );
  }
  return;
}


