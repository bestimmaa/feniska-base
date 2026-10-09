// requested 400d7e14 body [[400d7e14, 400d7e3d]]
// callees: FUN_400d7dc4 FUN_400ea940 FUN_400eaa20 
// callers: FUN_400d7140 

void FUN_400d7e14(undefined1 *param_1,undefined1 param_2,undefined1 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_400ea940(param_2,1);
  FUN_400ea940(param_1[1],3);
  FUN_400eaa20(param_1[1],0);
  FUN_400d7dc4(param_1);
  return;
}


