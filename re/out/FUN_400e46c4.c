// refs: calibFac:

void FUN_400e46c4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_7c [8];
  undefined1 auStack_74 [16];
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_74,PTR_DAT_400d1054);
  FUN_400e9b38(auStack_64,PTR_s_FNISKA_400d1058);
  (*(code *)PTR_FUN_400d02e0)(auStack_7c);
  FUN_400e3fac(auStack_7c,PTR_s_feniska_3f408196_6_400d105c,1,0);
  uVar3 = FUN_400e4640(auStack_7c,PTR_s_calibFac_400d1060,DAT_400d0120);
  uVar4 = FUN_400e43c0(auStack_7c,PTR_s_calibOff_400d1064,0);
  FUN_400e9cbc(auStack_34,auStack_64);
  FUN_400e43d0(auStack_54,auStack_7c,PTR_s_devId_400d1068,auStack_34);
  FUN_400e99ac(auStack_34);
  FUN_400ea884(auStack_54);
  FUN_400e9cbc(auStack_34,auStack_74);
  FUN_400e43d0(auStack_44,auStack_7c,PTR_s_devUuid_400d106c,auStack_34);
  FUN_400e99ac(auStack_34);
  FUN_400ea884(auStack_44);
  uVar2 = DAT_400d00cc;
  FUN_400e9514(DAT_400d00cc,PTR_s_Device_ID__400d1070);
  FUN_400e9554(uVar2,auStack_54);
  FUN_400e9514(uVar2,PTR_s_Device_UUID__400d1074);
  FUN_400e9554(uVar2,auStack_44);
  FUN_400e9514(uVar2,PTR_s_calibFac__400d1078);
  uVar8 = (*DAT_400d00d4)(uVar3);
  uVar6 = (undefined4)((ulonglong)uVar8 >> 0x20);
  FUN_400e9888(uVar2,uVar6,(int)uVar8,uVar6,2);
  FUN_400e9514(uVar2,PTR_s_calibOff__400d107c);
  FUN_400e9674(uVar2,uVar4,10);
  FUN_400e4090(auStack_7c);
  FUN_400e9c88(param_1 + 8,auStack_44);
  FUN_400e9c88(param_1 + 0x18,auStack_54);
  *(undefined4 *)(param_1 + 0x28) = uVar3;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  FUN_400e99ac(auStack_44);
  FUN_400e99ac(auStack_54);
  FUN_400e40a8(auStack_7c);
  FUN_400e99ac(auStack_64);
  FUN_400e99ac(auStack_74);
  memw();
  memw();
  iVar5 = *piVar1;
  if (iStack_24 != iVar5) {
    FUN_400f4a20();
    puVar7 = auStack_34;
    do {
      FUN_400e99ac(puVar7);
      FUN_400e40a8(auStack_7c);
      FUN_400e99ac(auStack_64);
      FUN_400e99ac(auStack_74);
      (*(code *)PTR_FUN_400d002c)(iVar5);
      FUN_400e99ac(auStack_34);
      puVar7 = auStack_54;
    } while( true );
  }
  return;
}


