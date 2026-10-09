// requested 40186d18 body [[40186d18, 40186d2e]]
// callees: 
// callers: FUN_400d34a4 FUN_400d34e8 FUN_400d3328 FUN_400d37e0 

void FUN_40186d18(int param_1,byte param_2)

{
  if (param_2 < 8) {
    if (param_2 == 0) {
      param_2 = 1;
    }
  }
  else {
    param_2 = 7;
  }
  *(byte *)(param_1 + 0x29) = param_2;
  return;
}


