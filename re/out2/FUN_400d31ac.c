// requested 400d31ac body [[400d31ac, 400d3269]]
// callees: FUN_400d2e38 FUN_400f4a20 FUN_40186e74 FUN_400e9514 FUN_400d5b00 FUN_400e9b38 FUN_400e99ac FUN_400d313c FUN_400ea094 FUN_4008eab8 FUN_40169fc0 FUN_40186d3c 
// callers: FUN_400d39b0 FUN_400d7950 

void FUN_400d31ac(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400d313c(param_1,1);
  FUN_400d5b00(param_1[7]);
  uVar2 = DAT_400d003c;
  *(undefined **)(*param_1 + 0xe4) = PTR_PTR_400d0044;
  (*(code *)PTR_FUN_400d0040)(param_1[1],uVar2,0);
  FUN_400d2e38(*param_1,0xf,0x32);
  iVar3 = *param_1;
  FUN_400e9b38(auStack_34,PTR_s_BASE_ID__400d0064);
  uVar2 = FUN_400ea094(auStack_34,param_1 + 3);
  (*(code *)PTR_FUN_400d006c)(iVar3,uVar2);
  FUN_400e99ac(auStack_34);
  FUN_400d2e38(*param_1,0xf,0x5a);
  FUN_400e9514(*param_1,PTR_s_Waiting_for_connection____400d0068);
  FUN_4008eab8(param_1[7],0,0);
  memw();
  memw();
  iVar3 = *piVar1;
  if (iStack_24 != iVar3) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    (*(code *)PTR_FUN_400d002c)(iVar3);
  }
  return;
}


