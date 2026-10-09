// requested 400d34e8 body [[400d34e8, 400d35a6] [400d35a9, 400d36c4] [400d36c8, 400d378e] [400d37dc, 400d37dd]]
// callees: FUN_40186d30 FUN_40186d18 FUN_400e9b38 FUN_400e99ac FUN_400d5b00 FUN_400e9c88 FUN_400ea0c4 FUN_400e8740 FUN_400ea5c4 FUN_40186554 FUN_40186d3c FUN_4008eab8 FUN_400e82ec FUN_400ea094 FUN_400e9514 FUN_40186e74 FUN_400db004 FUN_400d2f50 FUN_400e9cbc FUN_400d313c FUN_400d2e38 FUN_400f4a20 FUN_400ea1c4 FUN_40186d10 
// callers: FUN_400d39b0 FUN_400d7950 FUN_400d5190 

void FUN_400d34e8(int *param_1,float param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 ****ppppuVar8;
  undefined4 ***local_74 [2];
  uint uStack_6c;
  uint uStack_68;
  undefined4 ***local_64 [3];
  byte bStack_55;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  piStack_24 = (int *)*DAT_400d0060;
  memw();
  if (DAT_400d009c <= param_2) goto LAB_400d3724;
  if (*(char *)((int)param_1 + 9) == '\0') {
    FUN_400d313c(param_1,1);
    FUN_400d5b00(param_1[7]);
    uVar2 = DAT_400d003c;
    *(undefined **)(*param_1 + 0xe4) = PTR_PTR_400d0044;
    (*(code *)PTR_FUN_400d0078)(*param_1,uVar2);
    FUN_400d2e38(*param_1,0xf,0x32);
    iVar6 = *param_1;
    FUN_400e9b38(auStack_34,PTR_s_BASE_ID__400d0064);
    uVar2 = FUN_400ea094(auStack_34,param_1 + 3);
    (*(code *)PTR_FUN_400d006c)(iVar6,uVar2);
    FUN_400e99ac(auStack_34);
    FUN_400d2e38(*param_1,0xf,0x5a);
    FUN_400db004(local_74,DAT_400d007c);
    iVar6 = FUN_400ea1c4(local_74,PTR_DAT_400d0028);
    if (iVar6 == 0) {
      FUN_400e9514(*param_1,PTR_s_WiFi__400d00a0);
      iVar6 = (*(code *)PTR_FUN_400d00ac)(*param_1);
      ppppuVar8 = local_74;
      if ((uStack_68 & 0x80000000) == 0) {
        ppppuVar8 = (undefined4 ****)local_74[0];
      }
      iVar3 = FUN_400d2f50(*param_1,ppppuVar8,DAT_400d003c);
      if (((int)(0xe1U - iVar6) < iVar3) &&
         (uVar4 = (*(code *)PTR_FUN_400d00b0)(local_74), 5 < uVar4)) {
        FUN_400e9cbc(local_64,local_74);
        uVar4 = 2;
        do {
          iVar3 = (*(code *)PTR_FUN_400d00b0)(local_74);
          if (iVar3 - 4U <= uVar4) break;
          uVar7 = iVar3 - uVar4 >> 1;
          FUN_400ea5c4(auStack_54,local_74,0,uVar7);
          FUN_400e9cbc(auStack_44,auStack_54);
          uVar2 = FUN_400ea0c4(auStack_44,PTR_s_____3f408082_4_400d00a4);
          iVar3 = (*(code *)PTR_FUN_400d00b0)(local_74);
          uVar5 = uStack_68 >> 0x18 & 0x7f;
          if ((uStack_68 & 0x80000000) == 0) {
            uVar5 = uStack_6c;
          }
          FUN_400ea5c4(auStack_34,local_74,iVar3 - uVar7,uVar5);
          uVar2 = FUN_400ea094(uVar2,auStack_34);
          FUN_400e9c88(local_64,uVar2);
          FUN_400e99ac(auStack_34);
          FUN_400e99ac(auStack_44);
          FUN_400e99ac(auStack_54);
          ppppuVar8 = local_64;
          if ((bStack_55 & 0x80) == 0) {
            ppppuVar8 = (undefined4 ****)local_64[0];
          }
          uVar4 = uVar4 + 1;
          uVar5 = FUN_400d2f50(*param_1,ppppuVar8,DAT_400d003c);
        } while (0xe1U - iVar6 < uVar5);
        FUN_400e9c88(local_74,local_64);
        FUN_400e99ac(local_64);
      }
      (*(code *)PTR_FUN_400d006c)(*param_1,local_74);
    }
    else {
      FUN_400e9514(*param_1,PTR_s_Waiting_for_connection____400d0068);
    }
    FUN_4008eab8(param_1[7],0,0);
    FUN_400e99ac(local_74);
  }
  while( true ) {
    *(bool *)((int)param_1 + 9) = param_2 < DAT_400d009c;
    memw();
    memw();
    param_1 = (int *)*piVar1;
    if (piStack_24 == param_1) break;
    FUN_400f4a20();
LAB_400d3724:
    FUN_400d313c(param_1,1);
    FUN_400d5b00(param_1[7]);
    (*(code *)PTR_FUN_400d0088)(param_1[1],3);
    (*(code *)PTR_FUN_400d0040)(param_1[1],DAT_400d003c,0);
    FUN_400e8740(param_1[1],param_2,2,0xf,0x32);
    (*(code *)PTR_FUN_400d0088)(param_1[1],2);
    FUN_400e82ec(param_1[1],PTR_DAT_400d00a8,0x82,0x3c,2);
    FUN_4008eab8(param_1[7],0,0);
  }
  return;
}


