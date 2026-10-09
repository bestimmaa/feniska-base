// requested 400d7bfc body [[400d7bfc, 400d7c44]]
// callees: FUN_400ea940 
// callers: FUN_400d75d4 

void FUN_400d7bfc(undefined1 *param_1,int param_2,undefined1 param_3,char param_4,undefined1 param_5
                 )

{
  undefined4 uVar1;
  
  param_1[0x10] = 0x14;
  *(undefined4 *)(param_1 + 0x14) = 300;
  uVar1 = DAT_400d00dc;
  param_1[8] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  param_1[0x24] = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  param_1[0x30] = 0;
  *param_1 = param_3;
  *(int *)(param_1 + 4) = param_2;
  if (param_2 == 0) {
    uVar1 = 5;
    if (param_4 == '\0') {
      uVar1 = 1;
    }
    FUN_400ea940(param_3,uVar1);
    param_1[8] = param_5;
  }
  return;
}


