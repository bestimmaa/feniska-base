// requested 400d4500 body [[400d4500, 400d45a5] [400d45a8, 400d4656] [400d4678, 400d4679]]
// callees: FUN_400e9d40 FUN_400daa04 FUN_4009084c FUN_400f4a20 FUN_400e956c FUN_400d4500 FUN_400e5e00 FUN_400e9b38 FUN_400e5374 FUN_40186c50 FUN_400ea094 FUN_400e9554 FUN_400e9658 FUN_400ea0c4 FUN_400e5b4c FUN_400e9514 FUN_400d3a88 FUN_400e99ac 
// callers: FUN_400d46ac FUN_400d467c FUN_400d4500 

void FUN_400d4500(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  iVar3 = FUN_400daa04();
  iVar6 = DAT_400d00cc;
  if (iVar3 == 3) goto LAB_400d4541;
  FUN_400e956c(DAT_400d00cc,PTR_s__FeniskaApiHandler_cpp__no_Wifi_400d019c);
  param_1 = 0;
  do {
    while( true ) {
      memw();
      memw();
      iVar6 = *piVar1;
      if (iStack_24 == iVar6) {
        return;
      }
      FUN_400f4a20();
LAB_400d4541:
      FUN_400e9b38(auStack_34,PTR_s__FeniskaApiHandler_cpp__400d01a0);
      FUN_400e9d40(auStack_44,0x3d,10);
      uVar4 = FUN_400ea094(auStack_34,auStack_44);
      uVar4 = FUN_400ea0c4(uVar4,PTR_s___FeniskaApiHandler_connect_400d01a4);
      FUN_400e9554(iVar6,uVar4);
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(auStack_34);
      uVar4 = DAT_400d00fc;
      iVar3 = FUN_400e5374(DAT_400d00fc);
      uVar2 = DAT_400d01b0;
      if (iVar3 == 0) break;
      FUN_400e956c(iVar6,PTR_s__FeniskaApiHandler_cpp__already_c_400d01a8);
LAB_400d45a1:
      param_1 = 1;
    }
    FUN_400d3a88(DAT_400d01b0,PTR_s_Waiting_for_connection_400d01ac);
    iVar3 = FUN_400e5e00(uVar4,PTR_s_aunev1aoh3apb_ats_iot_eu_central_400d01b8,DAT_400d01b4);
    if (iVar3 != 0) {
      FUN_400e9514(iVar6,PTR_s_Subscribe_to_400d01c4);
      uVar5 = DAT_400d01c8;
      FUN_400e9554(iVar6,DAT_400d01c8);
      FUN_400e9b38(auStack_34,PTR_s_base_action__400d01cc);
      uVar5 = FUN_400ea094(auStack_34,uVar5);
      FUN_400e5b4c(uVar4,uVar5,0);
      FUN_400e99ac(auStack_34);
      FUN_400e956c(iVar6,PTR_s_MQTT_Connected_400d01d0);
      FUN_400d3a88(uVar2,PTR_DAT_400d01d4);
      goto LAB_400d45a1;
    }
    FUN_400e9514(iVar6,PTR_s_MQTT_connection_failed__Error_co_400d01bc);
    uVar4 = (*(code *)PTR_FUN_400d01d8)(uVar4);
    FUN_400e9658(iVar6,uVar4,10);
    FUN_4009084c(DAT_400d01c0);
    param_1 = FUN_400d4500(param_1);
  } while( true );
}


