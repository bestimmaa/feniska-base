// requested 400d788f body [[400d7704, 400d7752] [400d7755, 400d77c3] [400d77c5, 400d77e2] [400d77e4, 400d7825] [400d7829, 400d78d6] [400d78d9, 400d793f] [400d794c, 400d794d]]
// callees: FUN_400ea1c4 FUN_400e8cd0 FUN_40186c1c FUN_400e99ac FUN_400ea908 FUN_40186c08 FUN_400e9554 FUN_400e9fe0 FUN_400d6c00 FUN_400d5300 FUN_400e9658 FUN_400d3a88 FUN_400ea0c4 FUN_4009084c FUN_400d64b0 FUN_40169fc0 FUN_400e5288 FUN_400eab04 FUN_400e9514 FUN_400e9b38 FUN_400d37e0 FUN_400d6ba8 FUN_400d7f0c FUN_400f4a20 FUN_400ea094 FUN_400e956c 
// callers: 

void FUN_400d7704(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  int iVar8;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  uVar5 = DAT_400d00fc;
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e5288(auStack_54,DAT_400d00fc);
  puVar2 = PTR_DAT_400d0454;
  FUN_400e9b38(auStack_44,PTR_DAT_400d0454);
  while (iVar4 = (*(code *)PTR_FUN_400d05ac)(uVar5), iVar4 != 0) {
    uVar3 = (*(code *)PTR_FUN_400d05b0)(uVar5);
    FUN_400e9fe0(auStack_44,uVar3);
  }
  FUN_400e9b38(auStack_34,PTR_s_incoming__400d0584);
  uVar5 = FUN_400ea094(auStack_34,auStack_54);
  uVar5 = FUN_400ea0c4(uVar5,PTR_DAT_400d0588);
  uVar6 = FUN_400ea094(uVar5,auStack_44);
  uVar5 = DAT_400d00cc;
  FUN_400e9554(DAT_400d00cc,uVar6);
  FUN_400e99ac(auStack_34);
  iVar4 = FUN_400ea1c4(auStack_44,DAT_400d058c);
  if (iVar4 != 0) {
    FUN_400e956c(uVar5,PTR_s_reset_triggered_400d0594);
    FUN_400d5300();
    FUN_400e8cd0(DAT_400d02fc);
  }
  iVar4 = FUN_400d6ba8(auStack_44,PTR_s_message__400d0590);
  if (iVar4 != 0) {
    FUN_400d6c00(auStack_34,auStack_44,8);
    FUN_400d37e0(DAT_400d01b0,auStack_34);
    FUN_400e99ac(auStack_34);
  }
  iVar4 = FUN_400ea1c4(auStack_44,DAT_400d0598);
  if (iVar4 != 0) {
    FUN_400e956c(uVar5,PTR_s_tare_triggered_400d05a0);
    uVar6 = DAT_400d01b0;
    FUN_400d3a88(DAT_400d01b0,PTR_s_Zeroing_the_base_400d051c);
    FUN_4009084c(300);
    iVar4 = DAT_400d02b0;
    fVar7 = (float)FUN_400d7f0c(DAT_400d02b0,10);
    if (NAN(fVar7 * 1.0)) {
      iVar8 = -0x80000000;
      if (0.0 <= fVar7) {
        iVar8 = 0x7fffffff;
      }
    }
    else {
      iVar8 = (int)(fVar7 * 1.4013e-45);
    }
    *(int *)(iVar4 + 4) = iVar8;
    FUN_4009084c(200);
    FUN_400d3a88(uVar6,puVar2);
  }
  iVar4 = FUN_400d6ba8(auStack_44,PTR_DAT_400d059c);
  if (iVar4 != 0) {
    FUN_400e9514(uVar5,PTR_s_Dim_Brightness_to__400d05a8);
    FUN_400d6c00(auStack_34,auStack_44,4);
    uVar6 = FUN_400ea908(auStack_34);
    FUN_400e99ac(auStack_34);
    FUN_400e9658(uVar5,uVar6,10);
    FUN_400eab04(1,uVar6);
  }
  iVar4 = FUN_400d6ba8(auStack_44,PTR_s_forceupdate__400d05a4);
  if (iVar4 != 0) {
    FUN_400d6c00(auStack_34,auStack_44,0xc);
    FUN_400d64b0(0,auStack_34);
    FUN_400e99ac(auStack_34);
  }
  FUN_400e99ac(auStack_44);
  FUN_400e99ac(auStack_54);
  memw();
  memw();
  iVar4 = *piVar1;
  if (iStack_24 != iVar4) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    do {
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(auStack_54);
      (*(code *)PTR_FUN_400d002c)(iVar4);
      FUN_400e99ac(auStack_34);
    } while( true );
  }
  return;
}


