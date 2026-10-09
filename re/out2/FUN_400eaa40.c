// requested 400eaa40 body [[400eaa40, 400eaaaa] [400eaaad, 400eaae9] [400eaaec, 400eab02]]
// callees: FUN_400ed744 FUN_400846a4 FUN_400eb510 FUN_40186f4c FUN_400ed21c 
// callers: FUN_400d7140 

undefined4 FUN_400eaa40(uint param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xff;
  uStack_30 = (uint)param_3;
  if ((param_1 < 0x10) && (uStack_30 < 0x15)) {
    uVar4 = param_1 >> 1 & 3;
    uStack_24 = 0;
    uStack_34 = param_1 >> 3;
    uStack_2c = uVar4;
    uStack_28 = param_2;
    iVar1 = FUN_400ed21c(&uStack_34);
    if (iVar1 == 0) {
      *(byte *)(DAT_400d12c4 + param_1) = param_3;
      uVar3 = FUN_400ed744(param_1 >> 3,uVar4);
    }
    else {
      uVar5 = FUN_400846a4();
      uVar3 = (*(code *)PTR_FUN_400d062c)(PTR_s__home_pc__platformio_packages_fr_400d12b4);
      uVar2 = (*DAT_400d0170)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_400d0624,DAT_400d0120);
      FUN_400eb510(PTR_s___6u__E___s__u___s____ledc_setup_400d12c0,uVar2,uVar3,0x4b,
                   PTR_s_ledcSetup_400d12b8);
      uVar3 = 0;
    }
  }
  else {
    uVar5 = FUN_400846a4();
    uVar3 = (*(code *)PTR_FUN_400d062c)(PTR_s__home_pc__platformio_packages_fr_400d12b4);
    uVar2 = (*DAT_400d0170)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_400d0624,DAT_400d0120);
    FUN_400eb510(PTR_s___6u__E___s__u___s____No_more_LE_400d12bc,uVar2,uVar3,0x3c,
                 PTR_s_ledcSetup_400d12b8,0x10,0x14);
    uVar3 = 0;
  }
  return uVar3;
}


