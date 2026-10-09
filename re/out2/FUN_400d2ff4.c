// requested 400d2ff4 body [[400d2ff4, 400d302a]]
// callees: FUN_400e6a08 FUN_400e68ec FUN_40186ce4 
// callers: FUN_400d7140 

void FUN_400d2ff4(int *param_1)

{
  int iVar1;
  
  FUN_400e6a08(param_1[1],0);
  FUN_400e68ec(param_1[1],1);
  FUN_400e68ec(*param_1,1);
  (*(code *)PTR_FUN_400d0030)(param_1[1],0);
  iVar1 = *param_1;
  *(int *)(iVar1 + 0xdc) = param_1[1];
  *(undefined1 *)(iVar1 + 0xe0) = 1;
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}


