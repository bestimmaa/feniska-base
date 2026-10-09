// requested 400d7f0c body [[400d7f0c, 400d7f56]]
// callees: FUN_401892b0 FUN_400eabd4 FUN_400d7e80 
// callers: FUN_400d7704 FUN_400d6188 FUN_400d80b4 FUN_400d7140 

undefined4 FUN_400d7f0c(undefined4 param_1,byte param_2)

{
  float fVar1;
  undefined4 uVar2;
  byte bVar3;
  float fVar4;
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  bVar3 = 0;
  fVar4 = DAT_400d0120;
  do {
    fVar1 = (float)FUN_400d7e80(param_1);
    fVar4 = fVar4 + fVar1;
    bVar3 = bVar3 + 1;
    FUN_400eabd4();
  } while (param_2 != bVar3);
  uVar2 = (*(code *)PTR_FUN_400d00d0)(fVar4,(float)param_2 / 1.0);
  return uVar2;
}


