// requested 400d476c body [[400d476c, 400d48ef] [400d492e, 400d492f]]
// callees: FUN_400e9554 FUN_400e9d40 FUN_40169fc0 FUN_400e9cbc FUN_400d46ac FUN_400ea0c4 FUN_400d5950 FUN_400f4a20 FUN_400e99ac FUN_400e956c FUN_400e9b38 FUN_400ea094 
// callers: FUN_400d7950 

void FUN_400d476c(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_54,PTR_s___deviceId____400d01f0);
  uVar2 = FUN_400ea094(auStack_54,DAT_400d01c8);
  uVar2 = FUN_400ea0c4(uVar2,PTR_DAT_400d01f4);
  uVar2 = FUN_400ea0c4(uVar2,PTR_s__logdate____400d01f8);
  FUN_400d5950(auStack_44);
  uVar2 = FUN_400ea094(uVar2,auStack_44);
  uVar2 = FUN_400ea0c4(uVar2,PTR_s____version____400d01fc);
  FUN_400e9d40(auStack_34,param_2,10);
  uVar2 = FUN_400ea094(uVar2,auStack_34);
  uVar2 = FUN_400ea0c4(uVar2,PTR_DAT_400d0200);
  FUN_400e9cbc(auStack_64,uVar2);
  FUN_400e99ac(auStack_34);
  FUN_400e99ac(auStack_44);
  FUN_400e99ac(auStack_54);
  uVar2 = DAT_400d00cc;
  FUN_400e956c(DAT_400d00cc,PTR_s_Sending_firmware_to_mqtt_broker__400d0204);
  FUN_400e9554(uVar2,auStack_64);
  FUN_400e9b38(auStack_34,PTR_s_base_data__400d0208);
  uVar2 = FUN_400ea094(auStack_34,DAT_400d020c);
  uVar2 = FUN_400ea0c4(uVar2,DAT_400d0210);
  FUN_400e9cbc(auStack_54,uVar2);
  FUN_400e99ac(auStack_34);
  iVar4 = 10;
  do {
    FUN_400e9cbc(auStack_44,auStack_54);
    FUN_400e9cbc(auStack_34,auStack_64);
    iVar3 = FUN_400d46ac(param_1,auStack_44,auStack_34);
    FUN_400e99ac(auStack_34);
    FUN_400e99ac(auStack_44);
    if (iVar3 != 0) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_400e99ac(auStack_54);
  FUN_400e99ac(auStack_64);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    do {
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(auStack_54);
      (*(code *)PTR_FUN_400d002c)(iVar3);
    } while( true );
  }
  return;
}


