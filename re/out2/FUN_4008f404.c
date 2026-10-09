// requested 4008f404 body [[4008f404, 4008f42f]]
// callees: FUN_40091448 FUN_400938a8 FUN_4009159c 
// callers: FUN_40112c9c FUN_4013d380 FUN_4013d3b4 FUN_400d4ef8 

undefined4 FUN_4008f404(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_400938a8(PTR_s_queue_c_3f41deb3_0x19_40080ef4,DAT_40080f90,
                 PTR_s_uxQueueMessagesWaiting_40080f8c,PTR_s_xQueue_40080f88);
  }
  FUN_40091448(param_1 + 0x4c,0xffffffff);
  memw();
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  FUN_4009159c(param_1 + 0x4c);
  return uVar1;
}


