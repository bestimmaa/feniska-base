// requested 400e8740 body [[400e8740, 400e87ee] [400e87f0, 400e8896]]
// callees: FUN_400eb8c4 FUN_400f4a20 FUN_4008a49c FUN_400e82ec FUN_401892b0 
// callers: FUN_400d34e8 

void FUN_400e8740(int param_1,float param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  ulonglong uVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  char acStack_32 [14];
  uint uStack_24;
  
  fVar3 = DAT_400d0608;
  memw();
  uStack_24 = *DAT_400d0060;
  memw();
  param_3 = param_3 & 0xff;
  *(undefined1 *)(param_1 + 0x72) = 1;
  param_6 = param_6 & 0xff;
  for (uVar4 = 0; (param_3 < 7) * param_3 + (uint)(param_3 >= 7) * 7 != uVar4;
      uVar4 = uVar4 + 1 & 0xff) {
    fVar3 = (float)(*(code *)PTR_FUN_400d00d0)(fVar3,DAT_400d1198);
  }
  if (0.0 - fVar3 <= param_2) goto LAB_400e87e8;
  acStack_32[0] = '-';
  acStack_32[1] = 0;
  param_2 = 0.0 - param_2;
  cVar9 = '\0';
  uVar7 = 1;
  while( true ) {
    param_2 = param_2 + fVar3;
    if (param_2 < DAT_400d119c) {
      uVar1 = (ulonglong)(param_2 * 1.0);
      bVar2 = uVar1 >> 0x10 != 0;
      uVar5 = ((uint)((longlong)uVar1 < 0) * -0x80000000 - (uint)(NAN(param_2) || bVar2)) +
              (uint)((!NAN(param_2) && !bVar2) && (longlong)uVar1 >= 0) * (int)uVar1;
      FUN_400eb8c4(uVar5,acStack_32 + uVar7,10);
      do {
        uVar8 = uVar7;
        uVar7 = uVar8 + 1 & 0xff;
      } while (acStack_32[uVar8] != '\0');
      fVar3 = (float)uVar5 / 1.0;
      param_2 = param_2 - fVar3;
      acStack_32[uVar8] = '.';
      acStack_32[uVar7] = '0';
      acStack_32[uVar7 + 1] = '\0';
      for (uVar5 = 0; ((char)((char)uVar8 + cVar9 + (char)uVar5) < '\t' && (uVar5 < uVar4));
          uVar5 = uVar5 + 1 & 0xff) {
        param_2 = param_2 * DAT_400d1198;
        uVar1 = (ulonglong)(param_2 * 1.0);
        bVar2 = uVar1 >> 0x10 != 0;
        uVar6 = ((uint)((longlong)uVar1 < 0) * -0x80000000 - (uint)(NAN(param_2) || bVar2)) +
                (uint)((!NAN(param_2) && !bVar2) && (longlong)uVar1 >= 0) * (int)uVar1;
        FUN_400eb8c4(uVar6,acStack_32 + (uVar5 + uVar7 & 0xff),10);
        fVar3 = (float)uVar6 / 1.0;
        param_2 = param_2 - fVar3;
      }
    }
    else {
      fVar3 = DAT_400d119c;
      FUN_4008a49c(acStack_32,PTR_s_____3f408082_4_400d11a0);
    }
    param_1 = FUN_400e82ec(param_1,acStack_32,param_4,param_5,param_6);
    param_6 = uStack_24;
    memw();
    memw();
    uVar4 = *DAT_400d0060;
    if (uStack_24 == uVar4) break;
    FUN_400f4a20();
LAB_400e87e8:
    cVar9 = '\x01';
    uVar7 = 0;
  }
  return;
}


