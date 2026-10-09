// requested 400d5300 body [[400d5300, 400d540a] [400d540c, 400d54f6] [400d550c, 400d550d]]
// callees: FUN_400e418c FUN_40186be4 FUN_400e4284 FUN_400e4384 FUN_400e9b38 FUN_400f1a90 FUN_400e43c0 FUN_400e3fac FUN_400e9cd0 FUN_400e9cbc FUN_400e40a8 FUN_400e99ac FUN_400e4090 FUN_400f152c FUN_400e43d0 FUN_400e4640 FUN_40169fc0 FUN_400f4a20 
// callers: FUN_400d5510 FUN_400d7704 FUN_400d6138 

void FUN_400d5300(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  float fVar6;
  int iVar7;
  int *piVar8;
  undefined1 auStack_6c [8];
  int aiStack_64 [3];
  byte bStack_55;
  int aiStack_54 [3];
  byte bStack_45;
  undefined1 auStack_44 [16];
  int aiStack_34 [4];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  (*(code *)PTR_FUN_400d02e0)(auStack_6c);
  puVar1 = PTR_s_feniska_3f408196_6_400d02c4;
  FUN_400e3fac(auStack_6c,PTR_s_feniska_3f408196_6_400d02c4,1,0);
  puVar2 = PTR_s_calibFac_400d02c8;
  fVar6 = (float)FUN_400e4640(auStack_6c,PTR_s_calibFac_400d02c8,DAT_400d0120);
  puVar3 = PTR_s_calibOff_400d02cc;
  iVar7 = FUN_400e43c0(auStack_6c,PTR_s_calibOff_400d02cc,0);
  puVar4 = PTR_DAT_400d02d0;
  FUN_400e9b38(aiStack_34,PTR_DAT_400d02d0);
  puVar5 = PTR_s_devId_400d02d4;
  FUN_400e43d0(aiStack_64,auStack_6c,PTR_s_devId_400d02d4,aiStack_34);
  FUN_400e99ac(aiStack_34);
  FUN_400e9b38(aiStack_54,PTR_DAT_400d02d8);
  FUN_400e9b38(auStack_44,puVar4);
  FUN_400e43d0(aiStack_34,auStack_6c,PTR_s_devUuid_400d02dc,auStack_44);
  FUN_400e9cd0(aiStack_54,aiStack_34);
  FUN_400e99ac(aiStack_34);
  FUN_400e99ac(auStack_44);
  FUN_400e4090(auStack_6c);
  FUN_400f1a90();
  FUN_400f152c();
  FUN_400e3fac(auStack_6c,puVar1,0);
  if (fVar6 != DAT_400d0120) {
    FUN_400e4384(auStack_6c,puVar2,fVar6);
  }
  if (iVar7 != 0) {
    FUN_400e418c(auStack_6c,puVar3,iVar7);
  }
  if (((bStack_55 & 0x80) != 0) || (aiStack_64[0] != 0)) {
    FUN_400e9cbc(aiStack_34,aiStack_64);
    FUN_400e4284(auStack_6c,puVar5,aiStack_34);
    FUN_400e99ac(aiStack_34);
  }
  if (((bStack_45 & 0x80) != 0) || (aiStack_54[0] != 0)) {
    FUN_400e9cbc(aiStack_34,aiStack_54);
    FUN_400e4284(auStack_6c,PTR_s_devUuid_400d02dc,aiStack_34);
    FUN_400e99ac(aiStack_34);
  }
  FUN_400e4090(auStack_6c);
  FUN_400e99ac(aiStack_54);
  FUN_400e99ac(aiStack_64);
  FUN_400e40a8(auStack_6c);
  memw();
  memw();
  iVar7 = *DAT_400d0060;
  if (iStack_24 != iVar7) {
    FUN_400f4a20();
    piVar8 = aiStack_34;
    do {
      FUN_400e99ac(piVar8);
      FUN_400e40a8(auStack_6c);
      (*(code *)PTR_FUN_400d002c)(iVar7);
      FUN_400e99ac(aiStack_34);
      FUN_400e99ac(auStack_44);
      FUN_400e99ac(aiStack_54);
      piVar8 = aiStack_64;
    } while( true );
  }
  return;
}


