// refs:  double pressed --> show Display Demo

void FUN_400d5510(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_54 [48];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  uVar2 = (*(code *)PTR_FUN_400d0300)(param_1);
  iVar3 = DAT_400d00cc;
  FUN_400e96b4(DAT_400d00cc,uVar2,10);
  if (param_2 == 1) {
    FUN_400e956c(iVar3,PTR_s_double_pressed___>_show_Display_D_400d02e8);
    FUN_400d2f94(auStack_54,DAT_400d02f0,DAT_400d02ec);
    FUN_400d39b0(auStack_54);
    FUN_400d2fe0(auStack_54);
  }
  else {
    if (param_2 == 0) goto LAB_400d5558;
    if (param_2 == 2) {
      FUN_400e956c(iVar3,PTR_s_long_pressed__Delete_WiFi_Creden_400d02f4);
      FUN_400d5300();
      FUN_400e956c(iVar3,PTR_s_done_3f426012_0x50_400d02f8);
      FUN_400eac1c(300);
      FUN_400eac1c(500);
      FUN_400e8cd0(DAT_400d02fc);
    }
  }
  while( true ) {
    memw();
    memw();
    iVar3 = *piVar1;
    if (iStack_24 == iVar3) break;
    FUN_400f4a20();
LAB_400d5558:
    FUN_400e956c(iVar3,PTR_s_pressed__3f40d234_0x4e_400d02e4);
  }
  return;
}


