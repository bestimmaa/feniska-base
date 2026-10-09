// requested 400d7950 body [[400d7950, 400d7b0b] [400d7b40, 400d7b41]]
// callees: FUN_400d4b74 FUN_400d34e8 FUN_400d31ac FUN_400d5a8c FUN_4008fad4 FUN_400d3adc FUN_400e9b38 FUN_400d3834 FUN_400e9cbc FUN_400d476c FUN_400dfbdc FUN_400e99ac FUN_400e56e8 FUN_4009084c FUN_400e3518 FUN_400eac04 FUN_400ea094 FUN_400d7d1c FUN_400d467c FUN_400e956c FUN_400f4a20 FUN_400d3a88 
// callers: FUN_400eb870 

void FUN_400d7950(void)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  pcVar3 = DAT_400d04ac;
  iVar6 = DAT_400d037c;
  uVar2 = DAT_400d031c;
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  if (*DAT_400d0364 == '\0') {
    if (*DAT_400d04ac == '\0') {
      FUN_400e3518(DAT_400d037c);
    }
    FUN_400d7d1c(DAT_400d04f0);
    if (*(int *)(iVar6 + 0x278) != 4) {
      FUN_400e9b38(auStack_44,PTR_s_Connectivity_State__400d05b4);
      FUN_400d5a8c(auStack_54,*(undefined4 *)(iVar6 + 0x278));
      uVar5 = FUN_400ea094(auStack_44,auStack_54);
      FUN_400e9cbc(auStack_34,uVar5);
      FUN_400d3834(DAT_400d01b0,auStack_34);
      FUN_400e99ac(auStack_34);
      FUN_400e99ac(auStack_54);
      FUN_400e99ac(auStack_44);
    }
    FUN_400e56e8(DAT_400d00fc);
    FUN_400dfbdc(uVar2);
    piVar4 = DAT_400d05b8;
    iVar7 = *(int *)(iVar6 + 0x278);
    if (iVar7 != 1) goto LAB_400d7a58;
    if (*DAT_400d05b8 == 1) goto LAB_400d7ae9;
    FUN_400d31ac(DAT_400d01b0);
    *piVar4 = *(int *)(iVar6 + 0x278);
    while( true ) {
      iVar7 = iStack_24;
      memw();
      memw();
      iVar6 = *piVar1;
      if (iStack_24 == iVar6) break;
      FUN_400f4a20();
LAB_400d7a58:
      piVar4 = DAT_400d05bc;
      uVar2 = DAT_400d01b0;
      if ((iVar7 == 4) && (*DAT_400d05bc == 0)) {
        FUN_400d3a88(DAT_400d01b0,PTR_s_Connecting_to_server_400d05c0);
        FUN_400d467c(auStack_34);
        FUN_400d3a88(uVar2,PTR_s_Testing_connection_400d05c4);
        FUN_400d476c(auStack_34,0x10);
        FUN_400d4b74(auStack_34);
        iVar7 = FUN_400eac04();
        uVar5 = DAT_400d0120;
        *piVar4 = iVar7;
        FUN_400d34e8(uVar2,uVar5);
        FUN_400e956c(DAT_400d00cc,PTR_s_Resume_tasks_400d05c8);
        FUN_4008fad4(*DAT_400d0428);
        FUN_4008fad4(*DAT_400d042c);
        FUN_400d3a88(uVar2,PTR_DAT_400d0454);
        FUN_400d3adc(auStack_34);
      }
LAB_400d7ae9:
      if (((*DAT_400d05cc == '\0') && (*(int *)(iVar6 + 0x278) == 4)) && (*DAT_400d05bc != 0)) {
        FUN_400eac04();
      }
LAB_400d797e:
      if (*pcVar3 == '\0') {
        *DAT_400d05b8 = *(int *)(DAT_400d037c + 0x278);
      }
      FUN_4009084c(10);
    }
    return;
  }
  FUN_4009084c(0x1e);
  FUN_400dfbdc(uVar2);
  goto LAB_400d797e;
}


