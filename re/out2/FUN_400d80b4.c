// requested 400d80e0 body [[400d80b4, 400d80cd] [400d80d1, 400d80eb] [400d80ed, 400d80ff] [400d8103, 400d810a]]
// callees: FUN_400d7f0c FUN_400d7fc4 FUN_400d7f58 FUN_400d7e80 FUN_400d8040 
// callers: FUN_400d810c 

float FUN_400d80b4(int param_1,undefined1 param_2)

{
  byte bVar1;
  float fVar2;
  
  bVar1 = *(byte *)(param_1 + 0x14);
  if (bVar1 == 2) {
    fVar2 = (float)FUN_400d7fc4(param_1,param_2);
    goto LAB_400d80dc;
  }
  if (bVar1 < 3) {
    if (bVar1 == 1) {
      fVar2 = (float)FUN_400d7f58(param_1);
      goto LAB_400d80dc;
    }
  }
  else {
    if (bVar1 == 3) {
      fVar2 = (float)FUN_400d8040(param_1,param_2,DAT_400d0608);
      goto LAB_400d80dc;
    }
    if (bVar1 == 4) {
      fVar2 = (float)FUN_400d7e80(param_1);
      goto LAB_400d80dc;
    }
  }
  fVar2 = (float)FUN_400d7f0c(param_1);
LAB_400d80dc:
  return fVar2 - (float)*(int *)(param_1 + 4) / 1.0;
}


