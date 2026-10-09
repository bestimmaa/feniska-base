// requested 400d8160 body [[400d8140, 400d8160]]
// callees: 
// callers: 

undefined4 FUN_400d8140(int *param_1,int param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  puStack_28 = PTR_PTR_400d0610;
  uStack_24 = *(undefined4 *)(param_2 + 4);
  uVar1 = (**(code **)(*param_1 + 0x48))(param_1,&puStack_28,param_3,param_1[9]);
  return uVar1;
}


