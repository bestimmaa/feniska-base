// refs: /update

void FUN_400d61e0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined *apuStack_48 [2];
  undefined *puStack_40;
  undefined *puStack_3c;
  undefined1 auStack_38 [8];
  undefined *puStack_30;
  undefined *puStack_2c;
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400d6174(auStack_38,PTR_s___3f412326_0x3f_400d03b4);
  puVar4 = PTR_FUN_400d03c0;
  puVar3 = PTR_FUN_400d03bc;
  uVar2 = DAT_400d031c;
  apuStack_48[0] = PTR_FUN_400d03b8;
  puStack_3c = PTR_FUN_400d03bc;
  puStack_40 = PTR_FUN_400d03c0;
  FUN_400df90c(DAT_400d031c,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__portal_400d03c4);
  apuStack_48[0] = PTR_LAB_400d03c8;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__setwifi_400d03cc);
  apuStack_48[0] = PTR_FUN_400d03d0;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__hellofeniska_400d03d4);
  apuStack_48[0] = PTR_FUN_400d03d8;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__networks_400d03dc);
  apuStack_48[0] = PTR_FUN_400d03e0;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__close_400d03e4);
  apuStack_48[0] = PTR_FUN_400d03e8;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__update_400d03ec);
  puStack_3c = PTR_FUN_400d03f0;
  puStack_40 = PTR_LAB_400d03f4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__reset_400d03f8);
  apuStack_48[0] = PTR_FUN_400d03fc;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__tare_400d0400);
  apuStack_48[0] = PTR_FUN_400d0404;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_DAT_400d0408);
  apuStack_48[0] = PTR_FUN_400d040c;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  FUN_400d6174(auStack_38,PTR_s__continue_400d0410);
  apuStack_48[0] = PTR_FUN_400d0414;
  puStack_3c = puVar3;
  puStack_40 = puVar4;
  FUN_400df90c(uVar2,auStack_38,apuStack_48);
  (*(code *)PTR_FUN_400d0420)(apuStack_48);
  FUN_400d5b1c(auStack_38);
  puStack_2c = PTR_FUN_400d0418;
  puStack_30 = PTR_FUN_400d041c;
  FUN_400dffa4(uVar2,auStack_38);
  (*(code *)PTR_FUN_400d0420)(auStack_38);
  memw();
  memw();
  iVar5 = *piVar1;
  if (iStack_24 != iVar5) {
    FUN_400f4a20();
    do {
      (*(code *)PTR_FUN_400d0420)(apuStack_48);
      FUN_400d5b1c(auStack_38);
      (*(code *)PTR_FUN_400d002c)(iVar5);
    } while( true );
  }
  return;
}


