// requested 400dc60c body [[400dc60c, 400dc6b6] [400dc6de, 400dc6f3]]
// callees: FUN_400dd248 FUN_40089a7c FUN_400e9b38 FUN_400f4a20 FUN_400e9c88 
// callers: FUN_400d664c 

void FUN_400dc60c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined1 auStack_124 [256];
  int iStack_24;
  
  puVar1 = PTR_DAT_400d09e4;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(param_1 + 4,PTR_DAT_400d09e4);
  FUN_400e9b38(param_1 + 0x14,puVar1);
  puVar2 = param_1 + 0x24;
  FUN_40089a7c(puVar2,0,0x14);
  FUN_40089a7c(param_1 + 0x38,0,0x14);
  FUN_400e9b38(param_1 + 0x4c,puVar1);
  FUN_400e9c88(param_1 + 0x14,param_2);
  FUN_40089a7c(puVar2,0,0x14);
  *(undefined4 *)(param_1 + 0x24) = param_3;
  param_1[0x5c] = param_4;
  *param_1 = 0;
  param_1[0x5d] = param_5;
  FUN_40089a7c(auStack_124,0,0x100);
  FUN_400dd248(puVar2,auStack_124);
  memw();
  memw();
  if (iStack_24 != *DAT_400d0060) {
    FUN_400f4a20();
  }
  return;
}


