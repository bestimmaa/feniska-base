// requested 400d5190 body [[400d5190, 400d52ee]]
// callees: FUN_400d4ea4 FUN_400e9514 FUN_400e5e00 FUN_400d50c0 FUN_400d5a70 FUN_4008f1f4 FUN_401689c4 FUN_400db358 FUN_400d34e8 FUN_4009084c FUN_401892b0 FUN_400d810c FUN_400d3ae8 FUN_4008eab8 FUN_400eac04 FUN_400d5ac4 
// callers: 

void FUN_400d5190(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined8 uVar11;
  float fStack_48;
  float fStack_44;
  int aiStack_38 [3];
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  
  iVar4 = 0;
  fStack_48 = DAT_400d02a8;
  fStack_44 = DAT_400d02a8;
  do {
    puVar2 = DAT_400d026c;
    iVar5 = FUN_4008f1f4(*DAT_400d026c,aiStack_38,0);
    if ((iVar5 == 1) && (iVar5 = FUN_400d5a70(), 0x78 < (uint)(iVar5 - aiStack_38[0]))) {
      uVar6 = (*(code *)PTR_FUN_400d02c0)(0x60);
      FUN_400db358();
      FUN_400d3ae8(uVar6);
      puVar3 = PTR_s_aunev1aoh3apb_ats_iot_eu_central_400d02ac;
      uVar1 = DAT_400d01b4;
      uVar7 = DAT_400d00fc;
      *DAT_400d0100 = uVar6;
      FUN_400e5e00(uVar7,puVar3,uVar1);
    }
    iVar5 = DAT_400d02b0;
    uVar7 = FUN_400d810c(DAT_400d02b0,10);
    fVar8 = (float)(*(code *)PTR_FUN_400d00d0)(uVar7,DAT_400d00bc);
    if (ABS(fVar8) < DAT_400d02b4) {
      fVar9 = (float)FUN_400d5ac4();
      if (NAN(fVar9 * 1.0)) {
        iVar10 = -0x80000000;
        if (0.0 <= fVar9) {
          iVar10 = 0x7fffffff;
        }
      }
      else {
        iVar10 = (int)(fVar9 * 1.4013e-45);
      }
      *(int *)(iVar5 + 4) = iVar10;
    }
    iVar5 = FUN_400eac04();
    iVar5 = FUN_400d50c0(ABS(fVar8 - fStack_44),(float)(uint)(iVar5 - iVar4) / 1.0,DAT_400d0120);
    if (iVar5 != 0) {
      uStack_2c = FUN_400d5a70();
      fStack_28 = fVar8;
      uStack_24 = FUN_400d5ac4(fVar8);
      FUN_4008eab8(*puVar2,&uStack_2c,0xffffffff,0);
      iVar4 = FUN_400eac04();
      fStack_44 = fVar8;
    }
    fVar8 = (float)FUN_400d4ea4(fVar8);
    uVar11 = (*DAT_400d00d4)(ABS(fVar8 - fStack_48));
    iVar5 = (*DAT_400d0144)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_400d0258,DAT_400d0260);
    uVar7 = DAT_400d01b0;
    if (0 < iVar5) {
      *DAT_400d02b8 = fVar8;
      FUN_400d34e8(uVar7,fVar8);
      fStack_48 = fVar8;
    }
    FUN_4009084c(0x32);
    FUN_400e9514(DAT_400d00cc,PTR_DAT_400d02bc);
  } while( true );
}


