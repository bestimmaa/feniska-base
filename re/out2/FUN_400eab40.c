// requested 400eab40 body [[400eab40, 400eab6e]]
// callees: FUN_400ed4e0 FUN_40089a7c 
// callers: FUN_400d7140 

void FUN_400eab40(uint param_1,uint param_2)

{
  uint uVar1;
  uint local_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  uint uStack_30;
  
  uVar1 = param_2 & 0xff;
  if (uVar1 < 0x10) {
    FUN_40089a7c(auStack_34,0,0x14);
    uStack_3c = uVar1 >> 3;
    uStack_38 = param_2 & 7;
    uStack_30 = uVar1 >> 1 & 3;
    local_40 = param_1 & 0xff;
    FUN_400ed4e0(&local_40);
  }
  return;
}


