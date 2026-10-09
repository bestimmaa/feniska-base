// requested 400d4b74 body [[400d4b74, 400d4d1c] [400d4d1e, 400d4d5e] [400d4d61, 400d4e4e] [400d4e9f, 400d4ea0]]
// callees: FUN_4018662c FUN_400d46ac FUN_400d3b98 FUN_4009084c FUN_400f4a20 FUN_400e956c FUN_400d5a70 FUN_400e9b38 FUN_400ea094 FUN_400d3b5c FUN_400e48f0 FUN_400d5a00 FUN_400d4410 FUN_400e9cbc FUN_400d4310 FUN_400ea0c4 FUN_400e99ac FUN_400e92c8 FUN_400d3b88 FUN_400db048 FUN_400dafa4 
// callers: FUN_400d7950 

undefined4 FUN_400d4b74(undefined4 param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined1 auStack_c0 [8];
  int iStack_b8;
  uint uStack_b4;
  undefined *puStack_b0;
  undefined1 *puStack_ac;
  undefined1 *puStack_a8;
  uint uStack_a4;
  int iStack_a0;
  uint uStack_9c;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [4];
  int iStack_8c;
  int iStack_88;
  undefined1 uStack_80;
  undefined1 auStack_78 [20];
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,PTR_s_base_data__400d0208);
  uVar4 = FUN_400ea094(auStack_34,DAT_400d020c);
  uVar4 = FUN_400ea0c4(uVar4,PTR_s__meta_400d0230);
  FUN_400e9cbc(auStack_64,uVar4);
  FUN_400e99ac(auStack_34);
  FUN_400e9b38(auStack_54,PTR_DAT_400d01d4);
  FUN_400d3b5c(auStack_98,0x400,0);
  uVar4 = FUN_400d5a70();
  FUN_400d5a00(auStack_34,uVar4);
  puStack_b0 = (undefined *)FUN_400d4410(auStack_78,PTR_s_logtime_400d0234,auStack_90);
  puStack_ac = auStack_90;
  FUN_400d3b98(auStack_34,puStack_b0,auStack_90);
  FUN_400e99ac(auStack_34);
  puStack_b0 = (undefined *)FUN_400d4410(auStack_78,PTR_s_deviceUuid_400d0238,auStack_90);
  puStack_ac = auStack_90;
  FUN_400d3b98(DAT_400d01c8,puStack_b0,auStack_90);
  cVar3 = FUN_400db048(DAT_400d007c);
  piVar5 = (int *)FUN_400d4410(auStack_78,PTR_s_rssi_3f429769_7_400d023c,auStack_90);
  if (piVar5 != (int *)0x0) {
    *piVar5 = (int)cVar3;
    *(byte *)(piVar5 + 2) = *(byte *)(piVar5 + 2) & 0x80 | 10;
    piVar5[1] = (int)cVar3 >> 0x1f;
  }
  puVar6 = (undefined4 *)FUN_400d4410(auStack_78,PTR_s_firmware_400d0240,auStack_90);
  if (puVar6 != (undefined4 *)0x0) {
    *(byte *)(puVar6 + 2) = *(byte *)(puVar6 + 2) & 0x80 | 10;
    uVar4 = DAT_400d0244;
    puVar6[1] = DAT_400d0120;
    *puVar6 = uVar4;
  }
  FUN_400dafa4(auStack_c0,DAT_400d007c);
  piVar5 = (int *)FUN_400d4410(auStack_78,PTR_s_ip_3f418cc5_0x18_400d0248,auStack_90);
  if (piVar5 != (int *)0x0) {
    puStack_ac = (undefined1 *)0x0;
    puStack_b0 = PTR_PTR_400d024c;
    uStack_a4 = 0;
    uStack_9c = iStack_88 - iStack_8c;
    iStack_a0 = iStack_8c;
    puStack_a8 = auStack_90;
    FUN_400e92c8(auStack_c0,&puStack_b0);
    uVar2 = uStack_a4;
    puVar1 = puStack_a8;
    if (uStack_a4 < uStack_9c) {
      iVar9 = *(int *)(puStack_a8 + 4);
      uStack_b4 = uStack_a4;
      iStack_b8 = iVar9;
      iVar8 = (*(code *)PTR_FUN_400d011c)(puStack_a8,&iStack_b8);
      if (iVar8 == 0) {
        *(undefined1 **)(puVar1 + 4) = (undefined1 *)(iVar9 + uVar2) + 1;
        *(undefined1 *)(iVar9 + uVar2) = 0;
        iVar8 = iVar9;
      }
      *(byte *)(piVar5 + 2) = *(byte *)(piVar5 + 2) & 0x80 | 5;
      *piVar5 = iVar8;
      piVar5[1] = uStack_a4;
    }
    else {
      uStack_80 = 1;
      *(byte *)(piVar5 + 2) = *(byte *)(piVar5 + 2) & 0x80;
    }
  }
  uVar4 = FUN_400e48f0(DAT_400d00f0);
  puVar7 = (undefined8 *)FUN_400d4410(auStack_78,PTR_s_calibFac_400d0250,auStack_90);
  if (puVar7 != (undefined8 *)0x0) {
    *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0x80 | 0xc;
    uVar10 = (*DAT_400d00d4)(uVar4);
    *puVar7 = uVar10;
  }
  FUN_400d4310(auStack_78,auStack_54);
  FUN_400e9cbc(auStack_44,auStack_64);
  FUN_400e9cbc(auStack_34,auStack_54);
  iVar8 = FUN_400d46ac(param_1,auStack_44,auStack_34);
  FUN_400e99ac(auStack_34);
  FUN_400e99ac(auStack_44);
  if (iVar8 == 0) goto LAB_400d4e29;
  while( true ) {
    FUN_400d3b88(auStack_98);
    FUN_400e99ac(auStack_54);
    FUN_400e99ac(auStack_64);
    memw();
    memw();
    if (iStack_24 == *DAT_400d0060) break;
    FUN_400f4a20();
LAB_400d4e29:
    uVar4 = DAT_400d00cc;
    FUN_400e956c(DAT_400d00cc,PTR_s_can_not_send__400d0228);
    FUN_4009084c(DAT_400d022c);
    FUN_400e956c(uVar4,PTR_s_Metadata_sent_400d0254);
  }
  return 1;
}


