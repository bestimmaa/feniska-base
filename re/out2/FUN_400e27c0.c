// requested 400e27c0 body [[400e27c0, 400e2844]]
// callees: FUN_400eaa30 FUN_400e2700 FUN_40088934 FUN_400ea940 FUN_400eaa20 
// callers: FUN_400d7140 

int FUN_400e27c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (-1 < (int)*(uint *)(param_1 + 0x38)) {
    FUN_400ea940(*(uint *)(param_1 + 0x38) & 0xff,5);
    iVar1 = FUN_400eaa30(*(undefined1 *)(param_1 + 0x38));
    *(bool *)(param_1 + 0x48) = iVar1 == 0;
  }
  if ((-1 < (int)*(uint *)(param_1 + 0x3c)) && (*(char *)(param_1 + 0x304) != '\0')) {
    FUN_400ea940(*(uint *)(param_1 + 0x3c) & 0xff,3);
    FUN_400eaa20(*(undefined1 *)(param_1 + 0x3c),*(int *)(param_1 + 0x40) == 0);
  }
  iVar1 = FUN_400e2700(param_1);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x22d) = 0;
    *(undefined1 *)(param_1 + 0x138) = 0;
    *(undefined1 *)(param_1 + 0x159) = 0;
  }
  iVar2 = FUN_40088934(param_1 + 0x24e);
  *(int *)(param_1 + 0x270) = iVar2 * 1000;
  return iVar1;
}


