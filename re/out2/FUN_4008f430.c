// requested 4008f430 body [[4008f430, 4008f461]]
// callees: FUN_40091448 FUN_400938a8 FUN_4009159c 
// callers: FUN_400d50c0 FUN_400d4ef8 

int FUN_4008f430(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_400938a8(PTR_s_queue_c_3f41deb3_0x19_40080ef4,DAT_40080f98,
                 PTR_s_uxQueueSpacesAvailable_40080f94,PTR_DAT_40080f00);
  }
  FUN_40091448(param_1 + 0x4c,0xffffffff);
  memw();
  iVar2 = *(int *)(param_1 + 0x38);
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_4009159c(param_1 + 0x4c);
  return iVar1 - iVar2;
}


