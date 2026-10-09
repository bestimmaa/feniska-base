// refs: Update Attempt: 

void FUN_400d664c(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_94 [16];
  undefined1 auStack_84 [96];
  int iStack_24;
  
  uVar2 = DAT_400d00cc;
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e956c(DAT_400d00cc,PTR_s_Update_400d0440);
  iVar4 = 0;
  do {
    FUN_400e9b38(auStack_84,PTR_s_Update_Attempt__400d0444);
    iVar4 = iVar4 + 1;
    FUN_400e9d90(auStack_94,iVar4,10);
    uVar3 = FUN_400ea094(auStack_84,auStack_94);
    FUN_400e9554(uVar2,uVar3);
    FUN_400e99ac(auStack_94);
    FUN_400e99ac(auStack_84);
    FUN_400e9b38(auStack_94,PTR_s_esp32_fota_http_400d0448);
    FUN_400dc60c(auStack_84,auStack_94,0x10,0);
    FUN_400e99ac(auStack_94);
    FUN_400e9cbc(auStack_94,param_1);
    FUN_400dd16c(auStack_84,auStack_94,0);
    FUN_400e99ac(auStack_94);
    FUN_4009084c(1000);
    FUN_400dc6f4(auStack_84);
  } while (iVar4 != 5);
  FUN_400e956c(uVar2,PTR_s_force_updated_400d044c);
  memw();
  memw();
  iVar4 = *piVar1;
  if (iStack_24 == iVar4) {
    return;
  }
  FUN_400f4a20();
  FUN_400e99ac(auStack_94);
  do {
    FUN_400e99ac(auStack_84);
    (*(code *)PTR_FUN_400d002c)(iVar4);
  } while( true );
}


