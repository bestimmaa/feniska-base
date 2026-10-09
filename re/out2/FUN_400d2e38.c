// requested 400d2e38 body [[400d2e38, 400d2e4f]]
// callees: FUN_40186d00 
// callers: FUN_400d34e8 FUN_400d31ac FUN_400d3444 FUN_400d30a0 FUN_400d30d0 FUN_400d326c 

void FUN_400d2e38(int param_1,short param_2,short param_3)

{
  *(int *)(param_1 + 0xc) = (int)param_2;
  *(int *)(param_1 + 0x10) = (int)param_3;
  (*(code *)PTR_FUN_400d0020)(*(undefined4 *)(param_1 + 0xdc));
  return;
}


