// requested 400da8d4 body [[400da8d4, 400da930] [400da942, 400da943]]
// callees: FUN_400d97fc FUN_400da8a8 FUN_40186818 FUN_400f4a20 FUN_401866c0 
// callers: FUN_400d7140 

int FUN_400da8d4(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack_44;
  int iStack_40;
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  iVar2 = 0;
  if (param_2 != 0) {
    FUN_400d97fc(&iStack_44);
    iStack_40 = param_2;
    (*(code *)PTR_FUN_400d0848)(auStack_3c);
    uStack_2c = 0;
    uStack_28 = param_3;
    FUN_400da8a8(DAT_400d0840,&iStack_44);
    (*(code *)PTR_FUN_400d0420)(auStack_3c);
    iVar2 = iStack_44;
  }
  while( true ) {
    memw();
    memw();
    iVar3 = *piVar1;
    if (iStack_24 == iVar3) break;
    FUN_400f4a20();
    iVar2 = iVar3;
  }
  return iVar2;
}


