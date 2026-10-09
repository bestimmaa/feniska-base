// requested 400d75d4 body [[400d75d4, 400d76f3]]
// callees: FUN_40186674 FUN_400d7dec FUN_400e4654 FUN_4008e9d4 FUN_400db358 FUN_400dd58c FUN_400e8b54 FUN_400e2354 FUN_401689c4 FUN_400e519c FUN_400dfd14 FUN_400d2f94 FUN_400e9b38 FUN_400d7bfc 
// callers: 

void FUN_400d75d4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  FUN_400d7bfc(DAT_400d04f0,0,0x23,1);
  FUN_400d7dec(DAT_400d02b0);
  uVar5 = DAT_400d02ec;
  FUN_400e8b54(DAT_400d02ec,0x87,0xf0);
  puVar1 = DAT_400d02f0;
  FUN_400e8b54(DAT_400d02f0,0x87,0xf0);
  uVar6 = DAT_400d01b0;
  *puVar1 = PTR_PTR_400d056c;
  *(undefined1 *)(puVar1 + 0x38) = 1;
  puVar1[0x39] = 0;
  puVar1[0x3b] = 0;
  puVar1[0x37] = uVar5;
  FUN_400d2f94(uVar6,puVar1,uVar5);
  uVar4 = DAT_400d0570;
  FUN_400dd58c(DAT_400d0570);
  uVar6 = DAT_400d031c;
  FUN_400dfd14(DAT_400d031c,0x50);
  uVar5 = DAT_400d0514;
  *DAT_400d0524 = PTR_PTR_400d0574;
  puVar3 = PTR_DAT_400d0454;
  FUN_400e9b38(uVar5,PTR_DAT_400d0454);
  FUN_400e9b38(DAT_400d0510,puVar3);
  FUN_400e9b38(DAT_400d034c,puVar3);
  iVar2 = DAT_400d037c;
  FUN_400e2354(DAT_400d037c,PTR_s_FENISKA_BASE_400d04e8,uVar4,DAT_400d0580,PTR_DAT_400d057c,
               PTR_s_init_3f416c39_5_400d0578);
  *(undefined4 *)(iVar2 + 0x14) = uVar6;
  uVar5 = (*(code *)PTR_FUN_400d02c0)(0x60);
  FUN_400db358();
  uVar6 = DAT_400d00fc;
  *DAT_400d0100 = uVar5;
  FUN_400e519c(uVar6,uVar5);
  FUN_400e9b38(DAT_400d020c,puVar3);
  FUN_400e9b38(DAT_400d01c8,puVar3);
  uVar6 = (*(code *)PTR_FUN_400d02a4)();
  uVar6 = FUN_4008e9d4(uVar6,0xc,0);
  *DAT_400d026c = uVar6;
  FUN_400e4654(DAT_400d00f0);
  return;
}


