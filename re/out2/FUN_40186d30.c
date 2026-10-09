// requested 40186d30 body [[40186d30, 40186d3b]]
// callees: 
// callers: FUN_400d326c FUN_400d3444 FUN_400d34e8 

void FUN_40186d30(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x1c) = param_2 & 0xffff;
  *(uint *)(param_1 + 0x18) = param_2 & 0xffff;
  return;
}


