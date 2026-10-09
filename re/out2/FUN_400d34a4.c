// requested 400d34a4 body [[400d34a4, 400d34e5]]
// callees: FUN_400e82ec FUN_400d5b00 FUN_400d313c FUN_4008eab8 FUN_40186d18 FUN_40186d3c 
// callers: FUN_400d39b0 FUN_400d7140 

void FUN_400d34a4(int param_1)

{
  FUN_400d313c(param_1,1);
  FUN_400d5b00(*(undefined4 *)(param_1 + 0x1c));
  (*(code *)PTR_FUN_400d0088)(*(undefined4 *)(param_1 + 4),2);
  (*(code *)PTR_FUN_400d0040)(*(undefined4 *)(param_1 + 4),DAT_400d003c,0);
  FUN_400e82ec(*(undefined4 *)(param_1 + 4),PTR_s_Device_not_configured__400d0098,0x14,0x28,2);
  FUN_4008eab8(*(undefined4 *)(param_1 + 0x1c),0,0);
  return;
}


