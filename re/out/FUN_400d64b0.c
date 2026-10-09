// refs: HANDLE OTA

void FUN_400d64b0(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  uint uStack_24;
  
  param_1 = param_1 & 0xff;
  memw();
  uStack_24 = *DAT_400d0060;
  memw();
  if (param_1 == 0) goto LAB_400d64f9;
  iVar6 = FUN_400d58b4();
  if (iVar6 != 0) goto LAB_400d64f9;
  FUN_400df6c0(DAT_400d031c,400,PTR_s_text_plain_400d0350,PTR_s_device_uuid_is_wrong__400d0390);
  while( true ) {
    param_2 = uStack_24;
    memw();
    memw();
    param_1 = *DAT_400d0060;
    if (uStack_24 == param_1) break;
    FUN_400f4a20();
LAB_400d64f9:
    uVar1 = DAT_400d00cc;
    FUN_400e956c(DAT_400d00cc,PTR_s_HANDLE_OTA_400d0424);
    FUN_400d3444(DAT_400d01b0);
    puVar3 = DAT_400d0428;
    puVar2 = DAT_400d0364;
    uVar7 = *DAT_400d0428;
    *DAT_400d0364 = 1;
    FUN_40090540(uVar7);
    puVar4 = DAT_400d042c;
    FUN_40090540(*DAT_400d042c);
    FUN_400e956c(uVar1,PTR_s_ready_to_check_400d0430);
    FUN_4009084c(10);
    uVar7 = DAT_400d031c;
    if (param_1 == 0) {
      FUN_400e9cbc(auStack_34,param_2);
      FUN_400d664c(auStack_34);
      puVar8 = auStack_34;
    }
    else {
      FUN_400df6c0(DAT_400d031c,200,PTR_s_text_plain_400d0350,PTR_s_update_starting_400d0434);
      FUN_400e9b38(auStack_44,PTR_DAT_400d0438);
      FUN_400dde50(auStack_34,uVar7,auStack_44);
      FUN_400d664c(auStack_34);
      FUN_400e99ac(auStack_34);
      puVar8 = auStack_44;
    }
    FUN_400e99ac(puVar8);
    FUN_4008fad4(*puVar3);
    FUN_4008fad4(*puVar4);
    puVar5 = PTR_s_HANDLE_OTA_DONE_400d043c;
    *puVar2 = 0;
    FUN_400e956c(uVar1,puVar5);
  }
  return;
}


