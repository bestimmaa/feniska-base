// requested 400d50c0 body [[400d50c0, 400d518f]]
// callees: FUN_401892b0 FUN_4008f430 FUN_40186674 
// callers: FUN_400d5190 

undefined4 FUN_400d50c0(float param_1,float param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  
  puVar1 = DAT_400d026c;
  iVar2 = FUN_4008f430(*DAT_400d026c);
  if (iVar2 != 0) {
    uVar3 = FUN_4008f430(*puVar1);
    iVar2 = (*(code *)PTR_FUN_400d02a4)();
    fVar4 = (float)(*(code *)PTR_FUN_400d00d0)((float)uVar3 / 1.0,(float)iVar2 / 1.0);
    if ((DAT_400d028c < (DAT_400d0284 - fVar4) * DAT_400d0288) && (DAT_400d0290 < param_2)) {
      return 1;
    }
    if (DAT_400d0294 < param_1) {
      *DAT_400d0298 = 0;
      return 1;
    }
    if (param_1 <= DAT_400d0294) {
      if (*DAT_400d0298 == 0) {
        if (DAT_400d029c < param_2) {
          *DAT_400d0298 = 1;
          return 1;
        }
      }
      else if ((*DAT_400d0298 - 1U < 2) && (DAT_400d02a0 < param_2)) {
        *DAT_400d0298 = 2;
        return 1;
      }
    }
  }
  return 0;
}


