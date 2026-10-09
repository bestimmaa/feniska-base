// requested 400d46ac body [[400d46ac, 400d476a]]
// callees: FUN_40169fc0 FUN_400e99ac FUN_4009084c FUN_400ea094 FUN_400e55a4 FUN_40186e74 FUN_400f4a20 FUN_400d4500 FUN_400e956c FUN_400e5e60 FUN_400e9b38 FUN_400ea0c4 FUN_400e9554 
// callers: FUN_400d476c FUN_400d4930 FUN_400d4b74 

void FUN_400d46ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,PTR_s__sendDataToMQTTServer__400d01dc);
  uVar2 = FUN_400ea094(auStack_34,param_2);
  uVar3 = FUN_400ea0c4(uVar2,PTR_s___3f41e5fb_0x74_400d01e0);
  uVar2 = DAT_400d00cc;
  FUN_400e9554(DAT_400d00cc,uVar3);
  FUN_400e99ac(auStack_34);
  iVar4 = FUN_400d4500(param_1);
  puVar5 = PTR_s_MQTT_not_connected_400d01e4;
  if (iVar4 != 0) {
    FUN_400e956c(uVar2,PTR_s_MQTT_is_connected_400d01e8);
    uVar3 = DAT_400d00fc;
    FUN_400e55a4(DAT_400d00fc,param_2,0,0);
    (*(code *)PTR_FUN_400d006c)(uVar3,param_3);
    FUN_400e5e60(uVar3);
    FUN_4009084c(100);
    puVar5 = PTR_s_MQTT_Message_sent_400d01ec;
  }
  FUN_400e956c(uVar2,puVar5);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    FUN_400f4a20();
    FUN_400e99ac(auStack_34);
    (*(code *)PTR_FUN_400d002c)(iVar4);
  }
  return;
}


