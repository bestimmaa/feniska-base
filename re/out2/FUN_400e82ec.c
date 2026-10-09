// requested 400e82ec body [[400e82ec, 400e83b2] [400e83b5, 400e8412] [400e8415, 400e8491] [400e8494, 400e84de] [400e84e0, 400e8511] [400e8514, 400e8519] [400e851c, 400e8527] [400e8529, 400e8607] [400e8609, 400e86df]]
// callees: FUN_4008b1f4 FUN_400e6e48 FUN_400e81a0 FUN_400e8114 FUN_400e6e0c 
// callers: FUN_400d34a4 FUN_400d34e8 FUN_400d3328 FUN_400e86e0 FUN_400e8740 

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_400e82ec(int *param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uStack_48;
  uint uStack_40;
  char cStack_3c;
  ushort local_22 [17];
  
  param_5 = param_5 & 0xff;
  uVar4 = FUN_400e81a0(param_1,param_2,param_5);
  uVar4 = uVar4 & 0xffff;
  uVar10 = (uint)*(byte *)((int)param_1 + 0x29);
  uVar9 = uVar10 << 3;
  if (((param_5 == 1) && (uStack_40 = 1, param_1[0x20] != 0)) && ((char)param_1[0x2d] == '\0')) {
    uVar9 = *(byte *)(param_1 + 0x1c) * uVar10;
    param_4 = param_4 + uVar9;
    uStack_48 = uVar9 & 0xff;
    cVar7 = 'e';
    if ((byte)(*(char *)((int)param_1 + 0x2a) - 6U) < 3) {
      uVar9 = uVar9 + *(byte *)((int)param_1 + 0x71) * uVar10 & 0xffff;
    }
  }
  else {
    uStack_40 = 0;
    cVar7 = '\x01';
    if ((char)param_1[0x2d] == '\0') {
      uStack_48 = uStack_40;
      if (param_5 == 1) goto LAB_400e8349;
      uStack_48 = (byte)PTR_PTR_400d1178[param_5 * 0xc + 9] * uVar10 & 0xff;
      uVar9 = FUN_400e6e0c(param_1,param_5);
    }
    else {
      uStack_48 = (uint)*(byte *)((int)param_1 + 0x92);
      uVar9 = FUN_400e6e48(param_1);
    }
    uVar9 = uVar9 & 0xffff;
  }
LAB_400e8349:
  bVar1 = *(byte *)((int)param_1 + 0x2a);
  if (bVar1 == 0) {
    if (param_1[5] != 0) goto LAB_400e8436;
  }
  else {
    if (bVar1 == 6) {
      param_4 = param_4 - uVar9;
    }
    else if (bVar1 < 7) {
      if (bVar1 == 3) {
        param_4 = param_4 - (uVar9 >> 1);
      }
      else if (bVar1 < 4) {
        if (bVar1 == 1) {
          param_3 = param_3 - (uVar4 >> 1);
          goto LAB_400e84d7;
        }
        if (bVar1 == 2) {
          param_3 = param_3 - uVar4;
          goto LAB_400e84e3;
        }
      }
      else {
        if (bVar1 == 4) {
          param_3 = param_3 - (uVar4 >> 1);
          param_4 = param_4 - (uVar9 >> 1);
          goto LAB_400e84d7;
        }
        if (bVar1 == 5) {
          param_3 = param_3 - uVar4;
          param_4 = param_4 - (uVar9 >> 1);
          goto LAB_400e84e3;
        }
      }
    }
    else if (bVar1 == 9) {
      param_4 = param_4 - uStack_48;
    }
    else if (bVar1 < 10) {
      if (bVar1 == 7) {
        param_3 = param_3 - (uVar4 >> 1);
        param_4 = param_4 - uVar9;
LAB_400e84d7:
        cVar7 = cVar7 + '\x01';
      }
      else if (bVar1 == 8) {
        param_3 = param_3 - uVar4;
        param_4 = param_4 - uVar9;
LAB_400e84e3:
        cVar7 = cVar7 + '\x02';
      }
    }
    else {
      if (bVar1 == 10) {
        param_3 = param_3 - (uVar4 >> 1);
        param_4 = param_4 - uStack_48;
        goto LAB_400e84d7;
      }
      if (bVar1 == 0xb) {
        param_3 = param_3 - uVar4;
        param_4 = param_4 - uStack_48;
        goto LAB_400e84e3;
      }
    }
LAB_400e8436:
    param_3 = (uint)(-1 < param_3) * param_3;
    iVar6 = (**(code **)(*param_1 + 0x3c))(param_1);
    if (iVar6 < (int)(uVar4 + param_3)) {
      param_3 = (**(code **)(*param_1 + 0x3c))(param_1);
      param_3 = param_3 - uVar4;
    }
    param_4 = (uint)(-1 < param_4) * param_4;
    iVar6 = (**(code **)(*param_1 + 0x38))(param_1);
    if (iVar6 < (int)((uVar9 + param_4) - uStack_48)) {
      param_4 = (**(code **)(*param_1 + 0x38))(param_1);
      param_4 = param_4 - uVar9;
    }
  }
  cStack_3c = '\0';
  if ((uStack_40 != 0) && (param_1[6] != param_1[7])) {
    uVar2 = FUN_4008b1f4(param_2);
    uVar10 = 0;
    uVar9 = (uint)*(byte *)((int)param_1 + 0x29) *
            ((uint)*(byte *)(param_1 + 0x1c) + (uint)*(byte *)((int)param_1 + 0x71)) & 0xffff;
    local_22[0] = 0;
    while ((uVar10 == 0 && (local_22[0] < uVar2))) {
      uVar10 = FUN_400e8114(param_1,param_2,local_22,uVar2 - local_22[0]);
    }
    iVar6 = param_1[0x20];
    cStack_3c = '\0';
    if ((*(ushort *)(iVar6 + 8) <= uVar10) && (uVar10 <= *(ushort *)(iVar6 + 10))) {
      cStack_3c = *(char *)((uVar10 - *(ushort *)(iVar6 + 8) & 0xffff) * 0xc + *(int *)(iVar6 + 4) +
                           7) * *(byte *)((int)param_1 + 0x29);
      if (cStack_3c < 1) {
        uVar4 = uVar4 - (int)cStack_3c & 0xffff;
      }
      else {
        cStack_3c = '\0';
      }
      (**(code **)(*param_1 + 0x2c))
                (param_1,cStack_3c + param_3,
                 param_4 - (uint)*(byte *)(param_1 + 0x1c) * (uint)*(byte *)((int)param_1 + 0x29),
                 uVar4,uVar9,param_1[7]);
    }
    cVar7 = cVar7 + -100;
  }
  uVar2 = FUN_4008b1f4(param_2);
  local_22[0] = 0;
  if ((char)param_1[0x2d] == '\0') {
    iVar6 = 0;
    while (local_22[0] < uVar2) {
      uVar5 = FUN_400e8114(param_1,param_2,local_22,uVar2 - local_22[0]);
      sVar3 = (**(code **)(*param_1 + 0x30))(param_1,uVar5,iVar6 + param_3,param_4,param_5);
      iVar6 = (int)(short)((short)iVar6 + sVar3);
    }
  }
  else {
    if (param_1[6] != param_1[7]) {
      (**(code **)(*param_1 + 0x2c))(param_1,param_3,param_4,uVar4,uVar9);
    }
    param_1[3] = (int)(short)param_3;
    param_1[4] = (int)(short)param_4;
    while (local_22[0] < uVar2) {
      uVar5 = FUN_400e8114(param_1,param_2,local_22,uVar2 - local_22[0]);
      (**(code **)(*param_1 + 0x40))(param_1,uVar5);
    }
    iVar6 = (int)(short)uVar4;
  }
  iVar12 = param_1[5];
  if (iVar12 <= (int)uVar4) {
    return iVar6;
  }
  iVar13 = param_1[7];
  if (param_1[6] == iVar13) {
    return iVar6;
  }
  iVar11 = (int)(short)((short)cStack_3c + (short)uVar4 + (short)param_3);
  if (uStack_40 != 0) {
    param_3 = param_3 + cStack_3c;
    iVar6 = (int)(short)((short)param_3 + (short)iVar6);
    param_4 = param_4 - (uint)*(byte *)(param_1 + 0x1c) * (uint)*(byte *)((int)param_1 + 0x29);
  }
  if (cVar7 == '\x02') {
    (**(code **)(*param_1 + 0x2c))(param_1,iVar11,param_4,(int)(iVar12 - uVar4) >> 1,uVar9);
    iVar12 = (int)(param_1[5] - uVar4) >> 1;
    iVar11 = (int)(short)iVar12;
    if (param_3 < iVar11) {
      iVar11 = (int)(short)param_3;
    }
    iVar13 = param_1[7];
    pcVar8 = *(code **)(*param_1 + 0x2c);
  }
  else {
    if (cVar7 != '\x03') {
      if (cVar7 != '\x01') {
        return iVar6;
      }
      pcVar8 = *(code **)(*param_1 + 0x2c);
      iVar12 = iVar12 - uVar4;
      goto LAB_400e8653;
    }
    if (iVar12 < iVar11) {
      iVar11 = (int)(short)iVar12;
    }
    param_3 = param_3 + uVar4;
    pcVar8 = *(code **)(*param_1 + 0x2c);
    iVar12 = iVar11 - uVar4;
  }
  iVar11 = param_3 - iVar11;
LAB_400e8653:
  (*pcVar8)(param_1,iVar11,param_4,iVar12,uVar9,iVar13);
  return iVar6;
}


