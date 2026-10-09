// requested 400d5a00 body [[400d5a00, 400d5a6f]]
// callees: FUN_400dd430 FUN_40176cd8 FUN_400dd410 FUN_400e9b38 FUN_400dd450 FUN_400dd400 FUN_400dd420 FUN_400f4a20 FUN_400dd440 
// callers: FUN_400d4930 FUN_400d4b74 

void FUN_400d5a00(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_38 [20];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  uVar1 = FUN_400dd450(param_2);
  uVar2 = FUN_400dd440(param_2);
  uVar3 = FUN_400dd430(param_2);
  uVar4 = FUN_400dd400(param_2);
  uVar5 = FUN_400dd410(param_2);
  uVar6 = FUN_400dd420(param_2);
  (*(code *)PTR_FUN_400d00d8)
            (auStack_38,PTR_s__04d__02d__02d__02d__02d__02d_400d032c,uVar1,uVar2,uVar3,uVar4,uVar5,
             uVar6);
  FUN_400e9b38(param_1,auStack_38);
  memw();
  memw();
  if (iStack_24 != *DAT_400d0060) {
    FUN_400f4a20();
  }
  return;
}


