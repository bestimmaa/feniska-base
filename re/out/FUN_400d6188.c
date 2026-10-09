// refs: Zeroing the base

void FUN_400d6188(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  
  iVar4 = FUN_400d58b4();
  puVar3 = PTR_s_text_plain_400d0350;
  uVar2 = DAT_400d031c;
  uVar1 = DAT_400d01b0;
  uVar7 = 400;
  puVar8 = PTR_s_device_uuid_is_wrong__400d0390;
  if (iVar4 != 0) {
    FUN_400d3a88(DAT_400d01b0,PTR_s_Zeroing_the_base_400d03b0,PTR_s_text_plain_400d0350,
                 PTR_s_device_uuid_is_wrong__400d0390);
    FUN_4009084c(300);
    iVar4 = DAT_400d02b0;
    fVar5 = (float)FUN_400d7f0c(DAT_400d02b0,10);
    if (NAN(fVar5 * 1.0)) {
      iVar6 = -0x80000000;
      if (0.0 <= fVar5) {
        iVar6 = 0x7fffffff;
      }
    }
    else {
      iVar6 = (int)(fVar5 * 1.4013e-45);
    }
    *(int *)(iVar4 + 4) = iVar6;
    FUN_4009084c(200);
    FUN_400d3a88(uVar1,PTR_DAT_400d0358);
    uVar7 = 200;
    puVar8 = PTR_DAT_400d036c;
  }
  FUN_400df6c0(uVar2,uVar7,puVar3,puVar8);
  return;
}


