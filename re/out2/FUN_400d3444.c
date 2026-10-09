// requested 400d3444 body [[400d3444, 400d34a3]]
// callees: FUN_400d313c FUN_40186d30 FUN_4008eab8 FUN_400d2e38 FUN_400e9514 FUN_400d5b00 FUN_40186d3c 
// callers: FUN_400d64b0 FUN_400d39b0 

void FUN_400d3444(int *param_1)

{
  undefined4 uVar1;
  
  FUN_400d313c(param_1,1);
  FUN_400d5b00(param_1[7]);
  uVar1 = DAT_400d003c;
  (*(code *)PTR_FUN_400d0040)(param_1[1],DAT_400d003c,0);
  *(undefined **)(*param_1 + 0xe4) = PTR_PTR_400d0044;
  (*(code *)PTR_FUN_400d0078)(*param_1,uVar1);
  FUN_400d2e38(*param_1,0xf,0x32);
  FUN_400e9514(*param_1,PTR_s_Update_in_progress_400d0090);
  FUN_400d2e38(*param_1,0xf,0x46);
  FUN_400e9514(*param_1,PTR_s_Don_t_turn_off_400d0094);
  FUN_4008eab8(param_1[7],0,0);
  return;
}


