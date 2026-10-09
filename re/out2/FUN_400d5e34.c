// requested 400d5e34 body [[400d5e34, 400d5eaa] [400d5eac, 400d5fab] [400d5fd4, 400d5fd5]]
// callees: FUN_400d30d0 FUN_400e99ac FUN_400e2e88 FUN_400eac1c FUN_400e2f4c FUN_400e9b38 FUN_400dde50 FUN_400df6c0 FUN_400d326c FUN_400f4a20 FUN_400e956c FUN_4008991c FUN_400e8cd0 FUN_4009084c FUN_400d6f90 
// callers: 

void FUN_400d5e34(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 ***pppuVar5;
  undefined4 in_a5;
  undefined *puVar6;
  undefined4 ***pppuVar7;
  undefined4 **local_54 [3];
  byte bStack_45;
  undefined4 **local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  piVar1 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  FUN_400e9b38(auStack_34,PTR_s_ssid_3f4296c5_4_400d0380);
  iVar4 = DAT_400d031c;
  FUN_400dde50(local_54,DAT_400d031c,auStack_34);
  FUN_400e99ac(auStack_34);
  FUN_400e9b38(auStack_34,PTR_s_password_3f40cd72_3_400d0384);
  FUN_400dde50(local_44,iVar4,auStack_34);
  FUN_400e99ac(auStack_34);
  iVar3 = DAT_400d037c;
  puVar6 = PTR_DAT_400d0370;
  uVar2 = DAT_400d01b0;
  if (*(int *)(DAT_400d037c + 0x278) - 1U < 2) {
    FUN_400d326c(DAT_400d01b0);
    in_a5 = uVar2;
    while( true ) {
      FUN_400df6c0(iVar4,200,puVar6,PTR_s_will_do_400d038c);
      uVar2 = DAT_400d00cc;
      pppuVar7 = local_54;
      if ((bStack_45 & 0x80) == 0) {
        pppuVar7 = (undefined4 ***)local_54[0];
      }
      FUN_400e956c(DAT_400d00cc,pppuVar7);
      pppuVar7 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        pppuVar7 = (undefined4 ***)local_44[0];
      }
      FUN_400e956c(uVar2,pppuVar7);
      FUN_4009084c(DAT_400d01c0);
      pppuVar7 = local_54;
      if ((bStack_45 & 0x80) == 0) {
        pppuVar7 = (undefined4 ***)local_54[0];
      }
      pppuVar5 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        pppuVar5 = (undefined4 ***)local_44[0];
      }
      puVar6 = (undefined *)(iVar3 + 0x100);
      *(undefined4 ****)(iVar3 + 0x310) = pppuVar7;
      *(undefined4 ****)(iVar3 + 0x314) = pppuVar5;
      FUN_4008991c(iVar3 + 0x138,pppuVar7,0x21);
      FUN_4008991c(iVar3 + 0x159,pppuVar5,0x21);
      FUN_400e2f4c(iVar3);
      FUN_4009084c(0x32);
      FUN_400e2e88(iVar3);
      FUN_4009084c(0x32);
      iVar4 = FUN_400d6f90();
      uVar2 = DAT_400d02fc;
      if (iVar4 != 0) {
        FUN_400d30d0(in_a5,1);
        FUN_400eac1c(500);
      }
      FUN_400e8cd0(uVar2);
LAB_400d5ebc:
      FUN_400e99ac(local_44);
      FUN_400e99ac(local_54);
      iVar4 = iStack_24;
      memw();
      memw();
      iVar3 = *piVar1;
      if (iStack_24 == iVar3) break;
      FUN_400f4a20();
    }
    return;
  }
  FUN_400df6c0(iVar4,200,PTR_DAT_400d0370,PTR_s_already_connected_but_I_return_a_400d0388);
  goto LAB_400d5ebc;
}


