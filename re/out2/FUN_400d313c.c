// requested 400d313c body [[400d313c, 400d31a9]]
// callees: FUN_400e6fcc FUN_4008eab8 FUN_40186cdc FUN_400d5b00 
// callers: FUN_400d34e8 FUN_400d31ac FUN_400d3328 FUN_400d3444 FUN_400d34a4 FUN_400d326c 

void FUN_400d313c(int param_1,char param_2)

{
  FUN_400d5b00(*(undefined4 *)(param_1 + 0x1c));
  if (*(char *)(param_1 + 8) == '\0') {
    (*(code *)PTR_FUN_400d0038)(*(undefined4 *)(param_1 + 4),1);
    FUN_400e6fcc(*(undefined4 *)(param_1 + 4),0,0,0x5a,0x16,PTR_DAT_400d005c);
    *(undefined1 *)(param_1 + 8) = 1;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),0x5a,0,0x96,0x16);
  if (param_2 != '\0') {
    (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),0,0x16,0xf0,0x71);
  }
  FUN_4008eab8(*(undefined4 *)(param_1 + 0x1c),0,0);
  return;
}


