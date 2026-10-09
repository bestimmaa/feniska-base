// refs: device uuid is wrong.

void FUN_400d6138(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = FUN_400d58b4();
  puVar2 = PTR_s_text_plain_400d0350;
  uVar1 = DAT_400d031c;
  if (iVar3 == 0) {
    FUN_400df6c0(DAT_400d031c,400,PTR_s_text_plain_400d0350,PTR_s_device_uuid_is_wrong__400d0390);
  }
  else {
    FUN_400d5300();
    FUN_400df6c0(uVar1,200,puVar2,PTR_s_restarting_400d03ac);
    FUN_400e8cd0(DAT_400d02fc);
  }
  return;
}


