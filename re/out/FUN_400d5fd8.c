// refs: device uuid is wrong.

void FUN_400d5fd8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined *puStack_24;
  
  puVar1 = DAT_400d0060;
  memw();
  puStack_24 = (undefined *)*DAT_400d0060;
  memw();
  iVar2 = FUN_400d58b4();
  puVar3 = DAT_400d031c;
  puVar4 = PTR_s_text_plain_400d0350;
  if (iVar2 != 0) goto LAB_400d601d;
  uVar5 = 400;
  puVar6 = PTR_s_device_uuid_is_wrong__400d0390;
  while( true ) {
    FUN_400df6c0(puVar3,uVar5,puVar4,puVar6);
    puVar4 = puStack_24;
    memw();
    memw();
    puVar3 = (undefined *)*puVar1;
    if (puStack_24 == puVar3) break;
    FUN_400f4a20();
LAB_400d601d:
    FUN_400e9b38(auStack_44,PTR_s_brightness_400d0394);
    FUN_400dde50(auStack_34,puVar3,auStack_44);
    uVar5 = FUN_400ea908(auStack_34);
    FUN_400e99ac(auStack_34);
    FUN_400e99ac(auStack_44);
    FUN_400eab04(1,uVar5);
    uVar5 = 200;
    puVar6 = PTR_DAT_400d036c;
  }
  return;
}


