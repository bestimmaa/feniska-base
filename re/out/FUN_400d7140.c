// refs: init and start HX711 scale

void FUN_400d7140(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  float fVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 ***pppuVar14;
  undefined8 uVar15;
  undefined1 auStack_44 [16];
  undefined4 **local_34 [2];
  undefined *puStack_2c;
  undefined *puStack_28;
  int iStack_24;
  
  uVar2 = DAT_400d00cc;
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e8f88(DAT_400d00cc,DAT_400d04d8,DAT_400d04d4,0xffffffff,0xffffffff,0,DAT_400d04dc,0x70);
  FUN_400e9528(uVar2);
  FUN_400e9b38(local_34,PTR_s_Starting_up_Feniska_Base_V_400d04e0);
  FUN_400e9d40(auStack_44,0x10,10);
  uVar7 = FUN_400ea094(local_34,auStack_44);
  FUN_400e9554(uVar2,uVar7);
  FUN_400e99ac(auStack_44);
  FUN_400e99ac(local_34);
  FUN_400e9514(uVar2,PTR_s_WiFi_Name__400d04e4);
  FUN_400e956c(uVar2,PTR_s_FENISKA_BASE_400d04e8);
  uVar3 = DAT_400d01b0;
  FUN_400d2ff4(DAT_400d01b0);
  (*(code *)PTR_FUN_400d0550)(uVar3,1);
  FUN_400d3a88(uVar3,PTR_DAT_400d0454);
  (*(code *)PTR_FUN_400d0554)();
  FUN_400eab40(4,1);
  FUN_400eaa40(1,DAT_400d04a8,8);
  FUN_400eab04(1,0xff);
  puVar6 = PTR_FUN_400d04ec;
  uVar7 = (*(code *)PTR_FUN_400d0558)(DAT_400d04f0,PTR_FUN_400d04ec);
  uVar7 = (*(code *)PTR_FUN_400d055c)(uVar7,puVar6,300);
  (*(code *)PTR_FUN_400d0560)(uVar7,puVar6,DAT_400d01c0);
  uVar7 = DAT_400d00f0;
  FUN_400e48dc(local_34,DAT_400d00f0);
  uVar4 = DAT_400d020c;
  FUN_400e9cd0(DAT_400d020c,local_34);
  FUN_400e99ac(local_34);
  FUN_400e9514(uVar2,PTR_s_Device_ID_Key__400d04f4);
  FUN_400e9554(uVar2,uVar4);
  FUN_400e48c8(local_34,uVar7);
  FUN_400e9cd0(DAT_400d01c8,local_34);
  FUN_400e99ac(local_34);
  FUN_400e9514(uVar2,PTR_s_Device_UUID__400d04f8);
  FUN_400e9554(uVar2,DAT_400d01c8);
  uVar8 = FUN_400e48f0(uVar7);
  uVar9 = FUN_400e48fc(uVar7);
  FUN_400e9514(uVar2,PTR_s_calibFac__400d04fc);
  uVar15 = (*DAT_400d00d4)(uVar8);
  uVar12 = (undefined4)((ulonglong)uVar15 >> 0x20);
  FUN_400e9888(uVar2,uVar12,(int)uVar15,uVar12,2);
  FUN_400e9514(uVar2,PTR_s_calibOff__400d0500);
  FUN_400e9674(uVar2,uVar9,10);
  FUN_400e9cbc(local_34,uVar4);
  FUN_400d302c(uVar3,local_34);
  FUN_400e99ac(local_34);
  FUN_400d3064(uVar3,0x10);
  FUN_400d3ae8(*DAT_400d0100);
  (*(code *)PTR_FUN_400d0564)(DAT_400d00fc,PTR_LAB_400d0504);
  iVar10 = FUN_400e4908(uVar7);
  if (iVar10 != 0) {
    FUN_400d34a4(uVar3);
  }
  FUN_400d3a88(uVar3,PTR_s_Connecting_to_WiFi_400d0508);
  iVar10 = FUN_400d6f90();
  if (iVar10 == 0) {
    FUN_400e956c(uVar2,PTR_s_Not_connected_400d04c8);
  }
  else {
    FUN_400e956c(uVar2,PTR_s_Connected_3f407c48_6_400d04cc);
    FUN_400d5938();
  }
  iVar10 = FUN_400daa04();
  if (iVar10 != 3) {
    FUN_400d3a88(uVar3,PTR_s_Searching_for_networks_400d050c);
    FUN_400d55e4(local_34);
    uVar7 = DAT_400d0510;
    FUN_400e9cd0(DAT_400d0510,local_34);
    FUN_400e99ac(local_34);
    FUN_400e9c88(DAT_400d0514,uVar7);
    FUN_400d5774(local_34);
    FUN_400e9cd0(DAT_400d034c,local_34);
    FUN_400e99ac(local_34);
  }
  FUN_400e956c(uVar2,PTR_s_init_and_start_HX711_scale_400d0518);
  iVar10 = DAT_400d02b0;
  FUN_400d7e14(DAT_400d02b0,0xf,2);
  uVar7 = DAT_400d0284;
  *(undefined1 *)(iVar10 + 0x14) = 2;
  *(undefined4 *)(iVar10 + 4) = uVar9;
  uVar7 = (*(code *)PTR_FUN_400d00d0)(uVar7,uVar8);
  puVar6 = PTR_s_Zeroing_the_base_400d051c;
  *(undefined4 *)(iVar10 + 8) = uVar7;
  FUN_400d3a88(uVar3,puVar6);
  FUN_4009084c(300);
  fVar11 = (float)FUN_400d7f0c(iVar10,10);
  if (NAN(fVar11 * 1.0)) {
    iVar13 = -0x80000000;
    if (0.0 <= fVar11) {
      iVar13 = 0x7fffffff;
    }
  }
  else {
    iVar13 = (int)(fVar11 * 1.4013e-45);
  }
  *(int *)(iVar10 + 4) = iVar13;
  FUN_4009084c(200);
  iVar10 = DAT_400d037c;
  local_34[0] = (undefined4 **)PTR_FUN_400d0520;
  puStack_28 = PTR_FUN_400d03bc;
  puStack_2c = PTR_FUN_400d03c0;
  FUN_400e35c4(DAT_400d037c,local_34);
  (*(code *)PTR_FUN_400d0420)(local_34);
  *(undefined4 *)(iVar10 + 0x31c) = DAT_400d0524;
  FUN_400e27c0(iVar10);
  FUN_400da8d4(DAT_400d007c,PTR_FUN_400d0528,0x28);
  FUN_400d61e0();
  FUN_400e9b38(local_34,PTR_s_feniska__400d052c);
  FUN_400e9f18(local_34,uVar4);
  pppuVar14 = local_34;
  if (((uint)puStack_28 & 0x80000000) == 0) {
    pppuVar14 = (undefined4 ***)local_34[0];
  }
  iVar10 = FUN_400e1f20(DAT_400d0530,pppuVar14);
  if (iVar10 == 0) {
    FUN_400e9514(uVar2,PTR_s_Error_setting_up_MDNS_responder__400d0534);
  }
  else {
    FUN_400e9514(uVar2,PTR_s_mDNS_responder_started__400d0540);
    FUN_400e9554(uVar2,local_34);
  }
  uVar7 = DAT_400d04b4;
  puVar5 = DAT_400d0428;
  FUN_4008fa64(PTR_LAB_400d053c,PTR_s_sendMeasurementsTask_400d0538,DAT_400d04b4,0,0,DAT_400d0428,0)
  ;
  FUN_40090540(*puVar5);
  puVar5 = DAT_400d042c;
  FUN_4008fa64(PTR_LAB_400d0548,PTR_s_measureAndDisplayTask_400d0544,uVar7,0,0,DAT_400d042c,0);
  FUN_40090540(*puVar5);
  FUN_400e956c(uVar2,PTR_s_END_OF_SETUP___400d054c);
  FUN_400e99ac(local_34);
  memw();
  memw();
  iVar10 = *piVar1;
  if (iStack_24 != iVar10) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_44);
    do {
      FUN_400e99ac(local_34);
      (*(code *)PTR_FUN_400d002c)(iVar10);
    } while( true );
  }
  return;
}


