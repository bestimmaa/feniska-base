// requested 400d7fc4 body [[400d7fc4, 400d802a] [400d802d, 400d803f]]
// callees: FUN_400eabd4 FUN_401892b0 FUN_400d7e80 FUN_400d7d50 
// callers: FUN_400d80b4 

undefined4 FUN_400d7fc4(undefined4 param_1,uint param_2)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float local_5c [23];
  
  param_2 = param_2 & 0xff;
  uVar3 = (uint)(param_2 < 3) * 3 + (param_2 >= 3) * param_2;
  uVar3 = (uVar3 < 0xf) * uVar3 + (uint)(uVar3 >= 0xf) * 0xf;
  uVar4 = 0;
  do {
    fVar1 = (float)FUN_400d7e80(param_1);
    local_5c[uVar4] = fVar1;
    FUN_400eabd4();
    uVar4 = uVar4 + 1;
  } while ((uVar4 & 0xff) < uVar3);
  FUN_400d7d50(param_1,local_5c,uVar3);
  uVar4 = uVar3 + 2 >> 2;
  fVar1 = DAT_400d0120;
  for (uVar6 = 0; uVar5 = uVar6 + uVar4 & 0xff, uVar5 <= ((uVar3 - 1) - uVar4 & 0xff);
      uVar6 = uVar6 + 1 & 0xff) {
    fVar1 = fVar1 + local_5c[uVar5];
  }
  uVar2 = (*(code *)PTR_FUN_400d00d0)(fVar1,(float)uVar6 / 1.0);
  return uVar2;
}


