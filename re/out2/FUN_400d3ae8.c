// requested 400d3ae8 body [[400d3ae8, 400d3b5a]]
// callees: FUN_400e4cec FUN_400f4a20 FUN_40186950 FUN_400e4bd8 FUN_40186958 FUN_40186948 
// callers: FUN_400d5190 FUN_400d7140 

void FUN_400d3ae8(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_1214 [1684];
  int aiStack_b80 [736];
  
  piVar1 = DAT_400d0060;
  piVar3 = (int *)((int)aiStack_b80 + DAT_400d0104);
  memw();
  memw();
  *piVar3 = *DAT_400d0060;
  (*(code *)PTR_FUN_400d010c)(param_1,PTR_DAT_400d00e8);
  uVar2 = DAT_400d00f0;
  FUN_400e4bd8(DAT_400d00f0,(int)aiStack_b80 + DAT_400d00ec + DAT_400d0108);
  (*(code *)PTR_FUN_400d0110)(param_1,PTR_s______BEGIN_CERTIFICATE______MIID_400d00f4);
  FUN_400e4cec(uVar2,auStack_1214 + DAT_400d0108);
  (*(code *)PTR_FUN_400d0114)(param_1,PTR_DAT_400d00f8);
  memw();
  iVar4 = *piVar3;
  *(undefined4 *)(DAT_400d00fc + 0x10) = *DAT_400d0100;
  memw();
  if (iVar4 != *piVar1) {
    FUN_400f4a20();
  }
  return;
}


