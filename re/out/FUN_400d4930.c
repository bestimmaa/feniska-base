// refs: rawValue

void FUN_400d4930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [24];
  undefined1 auStack_88 [20];
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
  FUN_400e9b38(auStack_34,PTR_s_base_data__400d0208);
  uVar2 = FUN_400ea094(auStack_34,DAT_400d020c);
  uVar2 = FUN_400ea0c4(uVar2,PTR_s__weight_400d0214);
  FUN_400e9cbc(auStack_74,uVar2);
  FUN_400e99ac(auStack_34);
  FUN_400e9b38(auStack_64,PTR_DAT_400d01d4);
  FUN_400d3b5c(auStack_a8,0x400,0);
  uVar2 = FUN_400d4410(auStack_88,PTR_s_devUuid_400d0218,auStack_a0);
  FUN_400d3b98(DAT_400d01c8,uVar2,auStack_a0);
  FUN_400d5a00(auStack_54,param_2);
  uVar2 = FUN_400d4410(auStack_88,PTR_s_logdate_400d021c,auStack_a0);
  FUN_400d3b98(auStack_54,uVar2,auStack_a0);
  FUN_400e99ac(auStack_54);
  FUN_400e9e08(auStack_44,param_3,2);
  uVar2 = FUN_400d4410(auStack_88,PTR_s_weight_3f407d17_1_400d0220,auStack_a0);
  FUN_400d3b98(auStack_44,uVar2,auStack_a0);
  FUN_400e99ac(auStack_44);
  FUN_400e9e08(auStack_34,param_4,2);
  uVar2 = FUN_400d4410(auStack_88,PTR_s_rawValue_400d0224,auStack_a0);
  FUN_400d3b98(auStack_34,uVar2,auStack_a0);
  FUN_400e99ac(auStack_34);
  FUN_400d4310(auStack_88,auStack_64);
  uVar2 = DAT_400d00cc;
  FUN_400e9554(DAT_400d00cc,auStack_64);
  iVar4 = 10;
  do {
    FUN_400e9cbc(auStack_44,auStack_74);
    FUN_400e9cbc(auStack_34,auStack_64);
    iVar3 = FUN_400d46ac(param_1,auStack_44,auStack_34);
    FUN_400e99ac(auStack_34);
    FUN_400e99ac(auStack_44);
    if (iVar3 != 0) break;
    FUN_400e956c(uVar2,PTR_s_can_not_send__400d0228);
    FUN_4009084c(DAT_400d022c);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_400d3b88(auStack_a8);
  FUN_400e99ac(auStack_64);
  FUN_400e99ac(auStack_74);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    do {
      (*(code *)PTR_FUN_400d002c)(iVar3);
      FUN_400e99ac(auStack_34);
      FUN_400e99ac(auStack_44);
      FUN_400d3b88(auStack_a8);
      FUN_400e99ac(auStack_64);
      FUN_400e99ac(auStack_74);
    } while( true );
  }
  return;
}


