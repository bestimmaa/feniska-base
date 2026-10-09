// requested 400d5049 body [[400d4ef8, 400d506b]]
// callees: FUN_4008f430 FUN_4008f404 FUN_4009084c FUN_400d467c FUN_400e99ac FUN_400e9dcc FUN_4008eec4 FUN_400e9b38 FUN_400e9554 FUN_400e9d40 FUN_400e9e08 FUN_400d4930 FUN_400ea094 FUN_400ea0c4 FUN_400e956c 
// callers: 

void FUN_400d4ef8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined1 auStack_74 [16];
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined4 uStack_24;
  
  memw();
  uStack_24 = *DAT_400d0060;
  memw();
  FUN_400d467c(auStack_74);
  puVar1 = DAT_400d026c;
  iVar2 = 1;
  do {
    if (iVar2 == 0) {
      FUN_400e956c(DAT_400d00cc,PTR_s_Retrying_Scale_transmission____400d0280);
      iVar2 = FUN_400d4930(auStack_74,uStack_80,uStack_7c,uStack_78);
      uVar3 = 500;
    }
    else {
      while (iVar2 = FUN_4008f404(*puVar1), iVar2 == 0) {
        FUN_4009084c(200);
      }
      uVar3 = FUN_4008f430(*puVar1);
      FUN_4008eec4(*puVar1,&uStack_80,0xffffffff);
      FUN_400e9b38(auStack_54,PTR_s_Worker_knows_measure___Available_400d0270);
      FUN_400e9d40(auStack_64,uVar3,10);
      uVar3 = FUN_400ea094(auStack_54,auStack_64);
      uVar3 = FUN_400ea0c4(uVar3,PTR_DAT_400d0274);
      FUN_400e9dcc(auStack_44,uStack_80,10);
      uVar3 = FUN_400ea094(uVar3,auStack_44);
      uVar3 = FUN_400ea0c4(uVar3,PTR_DAT_400d0278);
      FUN_400e9e08(auStack_34,uStack_7c,2);
      uVar4 = FUN_400ea094(uVar3,auStack_34);
      uVar3 = DAT_400d00cc;
      FUN_400e9554(DAT_400d00cc,uVar4);
      FUN_400e99ac(auStack_34);
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(auStack_64);
      FUN_400e99ac(auStack_54);
      iVar2 = FUN_400d4930(auStack_74,uStack_80,uStack_7c,uStack_78);
      puVar5 = PTR_DAT_400d0264;
      if (iVar2 == 0) {
        puVar5 = PTR_DAT_400d0268;
      }
      FUN_400e9b38(auStack_34,puVar5);
      FUN_400e9b38(auStack_44,PTR_DAT_400d027c);
      uVar4 = FUN_400ea094(auStack_34,auStack_44);
      FUN_400e9554(uVar3,uVar4);
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(auStack_34);
      uVar3 = 0x32;
    }
    FUN_4009084c(uVar3);
  } while( true );
}


