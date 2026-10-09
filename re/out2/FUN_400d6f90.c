// requested 400d6f90 body [[400d6f90, 400d709b] [400d709d, 400d70f1] [400d70f5, 400d7113] [400d713c, 400d713d]]
// callees: FUN_400d98c0 FUN_40186ae0 FUN_400daa04 FUN_4009084c FUN_400eac04 FUN_400f4a20 FUN_400e2700 FUN_400e956c FUN_400daa20 FUN_400e9b38 FUN_400ea094 FUN_4008b1f4 FUN_400e3394 FUN_400e9554 FUN_400ea0c4 FUN_400e9514 FUN_400e99ac FUN_400e9d90 
// callers: FUN_400d5e34 FUN_400d7140 

void FUN_400d6f90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int in_a6;
  undefined4 uVar9;
  undefined4 in_a7;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar8 = DAT_400d04ac;
  uVar5 = DAT_400d037c;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  *(undefined1 *)DAT_400d04ac = 1;
  iVar1 = FUN_400e2700(uVar5);
  iVar6 = DAT_400d00cc;
  if (iVar1 == 0) goto LAB_400d70a0;
  FUN_400e956c(DAT_400d00cc,PTR_s_WiFi_Credentials_are_present__Tr_400d04b0);
  uVar2 = DAT_400d04b4;
  *(undefined1 *)(uVar5 + 0x4a) = 1;
  (*(code *)PTR_FUN_400d04d0)(uVar5,uVar2);
  uVar7 = *(undefined4 *)(uVar5 + 0x310);
  uVar9 = *(undefined4 *)(uVar5 + 0x314);
  FUN_400e9b38(auStack_44,PTR_s_Known_Network__400d04b8);
  FUN_400e9b38(auStack_54,uVar7);
  uVar2 = FUN_400ea094(auStack_44,auStack_54);
  uVar2 = FUN_400ea0c4(uVar2,PTR_s_Length__400d04bc);
  uVar3 = FUN_4008b1f4(uVar7);
  FUN_400e9d90(auStack_34,uVar3,10);
  uVar2 = FUN_400ea094(uVar2,auStack_34);
  FUN_400e9554(iVar6,uVar2);
  FUN_400e99ac(auStack_34);
  FUN_400e99ac(auStack_54);
  FUN_400e99ac(auStack_44);
  FUN_400d98c0(1);
  FUN_400daa20(DAT_400d007c,uVar7,uVar9,0,0,1);
  in_a6 = FUN_400eac04();
  FUN_400e9514(iVar6,PTR_s_start_connecting_400d04c0);
  in_a7 = 0x32;
  iVar1 = DAT_400d04a8;
  do {
    iVar4 = FUN_400daa04();
    if (iVar4 == 3) {
      if (iVar1 < 1) goto LAB_400d708e;
LAB_400d70a0:
      iVar4 = FUN_400daa04();
      if (iVar4 == 3) {
        FUN_400e956c(iVar6,PTR_s_Connected_3f407c48_6_400d04cc);
        FUN_400e3394(uVar5,4);
        *(undefined1 *)piVar8 = 0;
      }
      else {
        FUN_400e956c(iVar6,PTR_s_Not_connected_400d04c8);
        *(undefined1 *)piVar8 = 0;
      }
      iVar1 = iStack_24;
      piVar8 = DAT_400d0060;
      uVar5 = (uint)(iVar4 == 3);
      memw();
      memw();
      iVar6 = *DAT_400d0060;
      if (iStack_24 == iVar6) {
        return;
      }
      FUN_400f4a20();
    }
    else if (iVar1 < 1) {
LAB_400d708e:
      FUN_400e956c(iVar6,PTR_s_Could_not_connect_to_WiFi_400d04c4);
      goto LAB_400d70a0;
    }
    FUN_4009084c(in_a7);
    iVar4 = FUN_400eac04();
    iVar1 = (in_a6 + iVar1) - iVar4;
    in_a6 = FUN_400eac04();
  } while( true );
}


