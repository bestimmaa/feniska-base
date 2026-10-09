// requested 400dca50 body [[400dca50, 400dcba6] [400dcba8, 400dcc8a] [400dcc8c, 400dccb9] [400dccbb, 400dcda2] [400dcda6, 400dce46] [400dce49, 400dcf66] [400dcf69, 400dcf94] [400dcf97, 400dd017] [400dd019, 400dd036] [400dd038, 400dd074] [400dd169, 400dd16a]]
// callees: FUN_400dc454 FUN_401693f8 FUN_40186f4c FUN_400dc480 FUN_400d4498 FUN_400e9d00 FUN_400dc5ec FUN_4016c83c FUN_400f4a20 FUN_4016e32c FUN_400ea1c4 FUN_4016bd70 FUN_400ea5c4 FUN_400846a4 FUN_4016bc70 FUN_4016ba00 FUN_4018692c FUN_400e9d40 FUN_400f017c FUN_400e9cbc FUN_4016de94 FUN_400e9b38 FUN_400db234 FUN_4016dd8c FUN_4016c13c FUN_400dc58c FUN_400ea094 FUN_400ea908 FUN_400e9554 FUN_400dc718 FUN_400e9d90 FUN_4016934c FUN_4016c9f4 FUN_4016c710 FUN_400e956c FUN_400e99ac FUN_4016e200 FUN_4016c048 FUN_400eb510 FUN_400dc5bc FUN_4016c904 FUN_400db358 FUN_400ea0c4 FUN_40186960 FUN_400f0220 FUN_400e8cd0 
// callers: FUN_400dd16c 

void FUN_400dca50(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined4 local_38c;
  undefined4 uStack_388;
  undefined1 auStack_374 [96];
  undefined1 auStack_314 [16];
  undefined1 auStack_304 [16];
  undefined1 auStack_2f4 [16];
  undefined1 auStack_2e4 [192];
  undefined4 auStack_224 [128];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  (*(code *)PTR_FUN_400d0a78)(auStack_2e4);
  FUN_400db358(auStack_374);
  puVar7 = (undefined1 *)(param_1 + 0x4c);
  FUN_400ea5c4(auStack_224,puVar7,0,5);
  iVar2 = FUN_400ea1c4(auStack_224,PTR_s_https_400d0a20);
  FUN_400e99ac(auStack_224);
  if (iVar2 == 0) {
    FUN_400e9cbc(auStack_224,puVar7);
    (*(code *)PTR_FUN_400d0a90)(auStack_2e4,auStack_224);
  }
  else {
    if (*(char *)(param_1 + 0x5d) == '\0') {
      FUN_400dc58c(&local_38c,DAT_400d09f4,PTR_s__root_ca_pem_400d0a24,PTR_DAT_400d09ec);
      iVar2 = (*(code *)PTR_FUN_400d09e0)(&local_38c);
      if (iVar2 != 0) goto LAB_400dcb6e;
      uVar9 = FUN_400846a4();
      uVar3 = (*DAT_400d0170)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_400d0624,DAT_400d0120);
      uVar4 = (*(code *)PTR_FUN_400d062c)(PTR_s__pio_libdeps_esp32dev_esp32FOTA__400d09f8);
      FUN_400eb510(PTR_s___6u__E___s__u___s____Could_not_o_400d0a2c,uVar3,uVar4,0xc2,
                   PTR_s_execOTA_400d0a28);
      FUN_400d4498(&local_38c);
      goto LAB_400dcb34;
    }
    (*(code *)PTR_FUN_400d0a88)(auStack_374);
    FUN_400e9cbc(auStack_224,puVar7);
    (*(code *)PTR_FUN_400d0a8c)(auStack_2e4,auStack_374,auStack_224);
  }
  FUN_400e99ac(auStack_224);
  do {
    local_38c = *(undefined4 *)PTR_PTR_400d0a30;
    uStack_388 = *(undefined4 *)(PTR_PTR_400d0a30 + 4);
    (*(code *)PTR_FUN_400d0a84)(auStack_2e4,&local_38c,2);
    iVar2 = (*(code *)PTR_FUN_400d0a94)(auStack_2e4);
    if ((iVar2 == 200) || (iVar2 == 0x12d)) {
      (*(code *)PTR_FUN_400d0a98)(auStack_224,auStack_2e4,PTR_s_Content_Length_400d0a34);
      iVar2 = FUN_400ea908(auStack_224);
      FUN_400e99ac(auStack_224);
      (*(code *)PTR_FUN_400d0a98)(auStack_224,auStack_2e4,PTR_s_Content_type_400d0a38);
      iVar5 = FUN_400ea1c4(auStack_224,PTR_s_application_octet_stream_400d0a3c);
      FUN_400e99ac(auStack_224);
      if ((iVar2 == 0) || (iVar5 == 0)) goto LAB_400dd038;
      piVar6 = (int *)(*(code *)PTR_FUN_400d0a9c)(auStack_2e4);
      puVar7 = DAT_400d0a40;
      if (*(char *)(param_1 + 0x5c) != '\0') {
        iVar2 = iVar2 + -0x200;
      }
      iVar5 = (*(code *)PTR_FUN_400d0aa0)(DAT_400d0a40,iVar2,0,0xffffffff,0);
      uVar3 = DAT_400d00cc;
      if (iVar5 == 0) {
        FUN_400e956c(DAT_400d00cc,PTR_s_Not_enough_space_to_begin_OTA_400d0a70);
        goto LAB_400dd02e;
      }
      if (*(char *)(param_1 + 0x5c) != '\0') {
        (**(code **)(*piVar6 + 0x28))(piVar6,auStack_224,0x200);
      }
      FUN_400e956c(uVar3,PTR_s_Begin_OTA__This_may_take_2___5_m_400d0a44);
      iVar5 = (*(code *)PTR_FUN_400d0aa4)(puVar7,piVar6);
      if (iVar2 == iVar5) {
        FUN_400e9b38(auStack_2f4,PTR_s_Written___400d0a48);
        FUN_400e9d90(auStack_304,iVar5,10);
        uVar4 = FUN_400ea094(auStack_2f4,auStack_304);
        uVar4 = FUN_400ea0c4(uVar4,PTR_s_successfully_400d0a4c);
        FUN_400e9554(uVar3,uVar4);
        FUN_400e99ac(auStack_304);
        puVar8 = auStack_2f4;
      }
      else {
        FUN_400e9b38(auStack_304,PTR_s_Written_only___400d0a50);
        FUN_400e9d90(auStack_314,iVar5,10);
        uVar4 = FUN_400ea094(auStack_304,auStack_314);
        uVar4 = FUN_400ea0c4(uVar4,PTR_s___3f412326_0x3f_400d0a54);
        FUN_400e9d40(auStack_2f4,iVar2,10);
        uVar4 = FUN_400ea094(uVar4,auStack_2f4);
        uVar4 = FUN_400ea0c4(uVar4,PTR_s___Retry__400d0a58);
        FUN_400e9554(uVar3,uVar4);
        FUN_400e99ac(auStack_2f4);
        FUN_400e99ac(auStack_314);
        puVar8 = auStack_304;
      }
      FUN_400e99ac(puVar8);
      iVar5 = (*(code *)PTR_FUN_400d0aa8)(puVar7,0);
      if (iVar5 == 0) {
        FUN_400e9b38(auStack_2f4,PTR_s_Error_Occurred__Error____400d0a6c);
        FUN_400e9d00(auStack_304,*puVar7,10);
        uVar4 = FUN_400ea094(auStack_2f4,auStack_304);
        FUN_400e9554(uVar3,uVar4);
        FUN_400e99ac(auStack_304);
        FUN_400e99ac(auStack_2f4);
      }
      else {
        if ((*(char *)(param_1 + 0x5c) == '\0') ||
           (iVar2 = FUN_400dc718(param_1,auStack_224,iVar2), iVar2 != 0)) {
          FUN_400e956c(uVar3,PTR_s_OTA_done__400d0a60);
          if (*(int *)(puVar7 + 0x24) != *(int *)(puVar7 + 0x10)) {
            FUN_400e956c(uVar3,PTR_s_Update_not_finished__Something_w_400d0a68);
            goto LAB_400dcb34;
          }
          FUN_400e956c(uVar3,PTR_s_Update_successfully_completed__R_400d0a64);
        }
        else {
          FUN_400f017c();
          FUN_400f0220();
          uVar9 = FUN_400846a4();
          uVar3 = (*DAT_400d0170)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_400d0624,
                                  DAT_400d0120);
          uVar4 = (*(code *)PTR_FUN_400d062c)(PTR_s__pio_libdeps_esp32dev_esp32FOTA__400d09f8);
          FUN_400eb510(PTR_s___6u__E___s__u___s____Signature_c_400d0a5c,uVar3,uVar4,0x117,
                       PTR_s_execOTA_400d0a28);
        }
        (*(code *)PTR_FUN_400d0aac)(auStack_2e4);
        FUN_400e8cd0(DAT_400d02fc);
      }
    }
    else {
LAB_400dd038:
      uVar9 = FUN_400846a4();
      uVar3 = (*DAT_400d0170)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_400d0624,DAT_400d0120);
      uVar4 = (*(code *)PTR_FUN_400d062c)(PTR_s__pio_libdeps_esp32dev_esp32FOTA__400d09f8);
      FUN_400eb510(PTR_s___6u__E___s__u___s____There_was_n_400d0a74,uVar3,uVar4,0x13b,
                   PTR_s_execOTA_400d0a28);
LAB_400dd02e:
      (*(code *)PTR_FUN_400d0aac)(auStack_2e4);
    }
LAB_400dcb34:
    puVar7 = auStack_20;
    FUN_400db234(auStack_374);
    (*(code *)PTR_FUN_400d0a7c)(auStack_2e4);
    memw();
    memw();
    param_1 = *DAT_400d0060;
    if (iStack_24 == param_1) {
      return;
    }
    FUN_400f4a20();
LAB_400dcb6e:
    FUN_400dc5ec(auStack_224);
    while (iVar2 = FUN_400dc454(&local_38c), iVar2 != 0) {
      uVar1 = FUN_400dc480(&local_38c);
      (*(code *)PTR_FUN_400d0a18)(auStack_224,uVar1);
    }
    FUN_400dc5bc(&local_38c);
    FUN_400e9cbc(auStack_2f4,puVar7);
    (*(code *)PTR_FUN_400d0a80)(auStack_2e4,auStack_2f4,auStack_224[0]);
    FUN_400e99ac(auStack_2f4);
    (*(code *)PTR_FUN_400d0a1c)(auStack_224);
    FUN_400d4498(&local_38c);
  } while( true );
}


