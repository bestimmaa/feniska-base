// requested 400d5ac4 body [[400d5ac4, 400d5afc]]
// callees: FUN_401892b0 
// callers: FUN_400d5190 

float FUN_400d5ac4(float param_1)

{
  float fVar1;
  int iVar2;
  
  param_1 = param_1 * DAT_400d00bc;
  iVar2 = *(int *)(DAT_400d02b0 + 4);
  fVar1 = (float)(*(code *)PTR_FUN_400d00d0)(DAT_400d0284,*(undefined4 *)(DAT_400d02b0 + 8));
  return (float)iVar2 / 1.0 + param_1 * fVar1;
}


