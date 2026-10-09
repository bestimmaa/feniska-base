// requested 400d4ea4 body [[400d4ea4, 400d4ef4]]
// callees: 
// callers: FUN_400d5190 

float FUN_400d4ea4(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*DAT_400d00d4)(param_1);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  iVar1 = (*DAT_400d0144)((int)uVar3,uVar2,DAT_400d0258,DAT_400d025c);
  if (((iVar1 < 1) ||
      (iVar1 = (*DAT_400d014c)((int)uVar3,uVar2,DAT_400d0258,DAT_400d0260), -1 < iVar1)) &&
     (DAT_400d0120 <= param_1)) {
    return param_1;
  }
  return DAT_400d0120;
}


