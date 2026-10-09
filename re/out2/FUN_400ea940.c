// requested 400ea940 body [[400ea940, 400ea992] [400ea994, 400eaa1d]]
// callees: FUN_400846a4 FUN_400ec9e0 FUN_400eb510 FUN_40186f4c 
// callers: FUN_4016e32c FUN_400e27c0 FUN_400d7e14 FUN_400e8b54 FUN_4016f068 FUN_4016ef94 FUN_4016efd0 FUN_400d7bfc FUN_4016eec8 FUN_4016ef3c FUN_400e6a08 FUN_4016f02c FUN_4016f0e4 FUN_4016ee70 

void FUN_400ea940(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uStack_38;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  param_1 = param_1 & 0xff;
  uVar1 = (*DAT_400d12ac)(DAT_400d1290,DAT_400d1294,param_1);
  if ((uVar1 & 1) == 0) {
    uVar7 = FUN_400846a4();
    uVar2 = (*(code *)PTR_FUN_400d062c)(PTR_s__home_pc__platformio_packages_fr_400d1298);
    uVar3 = (*DAT_400d0170)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_400d0624,DAT_400d0120);
    uVar6 = 0x66;
    puVar5 = PTR_s___6u__E___s__u___s____Invalid_pi_400d12a0;
  }
  else {
    uStack_38 = (*DAT_400d12b0)(DAT_400d12a4,DAT_400d0120,param_1);
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    memw();
    uStack_24 = *(uint *)(DAT_400d1100 + (param_1 + 0x20) * 4 + 8) >> 7 & 7;
    if ((param_2 & 0xff) < 0x20) {
      uStack_30 = param_2 & 3;
      if ((param_2 & 0x10) != 0) {
        uStack_30 = uStack_30 | 4;
      }
      uStack_2c = (uint)((param_2 & 4) != 0);
      if ((param_2 & 8) != 0) {
        uStack_28 = 1;
      }
    }
    iVar4 = FUN_400ec9e0(&uStack_38);
    if (iVar4 == 0) {
      return;
    }
    uVar7 = FUN_400846a4();
    uVar2 = (*(code *)PTR_FUN_400d062c)(PTR_s__home_pc__platformio_packages_fr_400d1298);
    uVar3 = (*DAT_400d0170)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_400d0624,DAT_400d0120);
    uVar6 = 0x82;
    puVar5 = PTR_s___6u__E___s__u___s____GPIO_confi_400d12a8;
  }
  FUN_400eb510(puVar5,uVar3,uVar2,uVar6,PTR_s___pinMode_400d129c);
  return;
}


