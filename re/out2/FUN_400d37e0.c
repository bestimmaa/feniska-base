// requested 400d37e0 body [[400d37e0, 400d3831]]
// callees: FUN_40186d3c FUN_400d5b00 FUN_400e86e0 FUN_4008eab8 FUN_40186d18 
// callers: FUN_400d7704 

void FUN_400d37e0(int param_1,undefined4 param_2)

{
  FUN_400d5b00(*(undefined4 *)(param_1 + 0x1c));
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),0x6e,0,0x87,0x1e);
  (*(code *)PTR_FUN_400d0088)(*(undefined4 *)(param_1 + 4),1);
  (*(code *)PTR_FUN_400d0040)(*(undefined4 *)(param_1 + 4),DAT_400d003c,0);
  FUN_400e86e0(*(undefined4 *)(param_1 + 4),param_2,0x6e,10,2);
  FUN_4008eab8(*(undefined4 *)(param_1 + 0x1c),0,0);
  return;
}


