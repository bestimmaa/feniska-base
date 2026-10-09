// requested 400e2354 body [[400e2354, 400e25a1]]
// callees: FUN_400e3c4c FUN_400e3c78 FUN_400e3ca4 FUN_400e3c30 FUN_40186bc4 
// callers: FUN_400d75d4 

void FUN_400e2354(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *param_1 = 0;
  param_1[4] = PTR_PTR_400d0d9c;
  puVar1 = PTR_s_iwcAll_400d0da0;
  puVar4 = param_1 + 0x13;
  param_1[8] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_400e3c30(puVar4,puVar1);
  puVar3 = param_1 + 0x1a;
  FUN_400e3c30(puVar3,PTR_s_iwcSys_400d0da8,PTR_s_System_configuration_400d0da4);
  FUN_400e3c30(param_1 + 0x21,PTR_s_iwcCustom_400d0dac,0);
  FUN_400e3c30(param_1 + 0x28,PTR_s_hidden_3f4297e0_3_400d0db0,0);
  puVar5 = param_1 + 0x2f;
  FUN_400e3c30(puVar5,PTR_s_iwcWifi0_400d0db4,0);
  param_1[0x2f] = PTR_PTR_400d0db8;
  FUN_400e3c4c(param_1 + 0x36,PTR_s_WiFi_SSID_400d0dc0,PTR_s_iwcWifiSsid_400d0dbc,param_1 + 0x4e,
               0x21,0,0,0);
  FUN_400e3ca4(param_1 + 0x42,PTR_s_WiFi_password_400d0dc8,PTR_s_iwcWifiPassword_400d0dc4,
               (int)param_1 + 0x159,0x21,0,0,PTR_s_ondblclick__pw_this_id___400d0dcc);
  (*(code *)PTR_FUN_400d0e18)(puVar5,param_1 + 0x36);
  (*(code *)PTR_FUN_400d0e18)(puVar5,param_1 + 0x42);
  FUN_400e3c4c(param_1 + 0x5f,PTR_s_Thing_name_400d0dd4,PTR_s_iwcThingName_400d0dd0,param_1 + 0x83,
               0x21,0,0,0);
  FUN_400e3ca4(param_1 + 0x6b,PTR_s_AP_password_400d0ddc,PTR_s_iwcApPassword_400d0dd8,
               (int)param_1 + 0x22d,0x21,0,0,PTR_s_ondblclick__pw_this_id___400d0dcc);
  FUN_400e3c78(param_1 + 0x77,PTR_s_Startup_delay__seconds__400d0de8,PTR_s_iwcApTimeout_400d0de4,
               (int)param_1 + 0x24e,0x21,PTR_DAT_400d0de0,0,PTR_s_min__1__max__600__400d0dec);
  puVar2 = PTR_FUN_400d0df4;
  param_1[0x9d] = DAT_400d08ec;
  puVar1 = PTR_FUN_400d0df0;
  param_1[0x9e] = 0;
  param_1[0xb1] = puVar1;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa3] = 0;
  param_1[0xa7] = 0;
  param_1[0xab] = 0;
  param_1[0xaf] = 0;
  param_1[0xb4] = puVar2;
  param_1[0xb3] = PTR_FUN_400d0df8;
  puVar1 = PTR_LAB_400d0e00;
  param_1[0xb5] = PTR_FUN_400d0dfc;
  param_1[0xb8] = puVar1;
  param_1[0xb7] = PTR_FUN_400d0e04;
  puVar1 = PTR_LAB_400d0e0c;
  param_1[0xb9] = PTR_FUN_400d0e08;
  param_1[0xbc] = puVar1;
  param_1[0xbb] = PTR_FUN_400d0e10;
  param_1[0xbd] = 500;
  param_1[0xbe] = 500;
  param_1[0xbf] = 500;
  param_1[0xc0] = 500;
  *(undefined2 *)(param_1 + 0xc1) = 1;
  param_1[0xc2] = 0;
  param_1[199] = param_1 + 0xc6;
  puVar1 = PTR_PTR_400d0e14;
  param_1[0x66] = param_2;
  param_1[0xc3] = 0;
  param_1[2] = param_3;
  param_1[0xc6] = puVar1;
  param_1[3] = param_4;
  *param_1 = param_5;
  param_1[1] = param_6;
  *(undefined1 *)(param_1 + 0x78) = 0;
  (*(code *)PTR_FUN_400d0e18)(puVar3,param_1 + 0x5f);
  (*(code *)PTR_FUN_400d0e18)(puVar3,param_1 + 0x6b);
  (*(code *)PTR_FUN_400d0e18)(puVar3,puVar5);
  (*(code *)PTR_FUN_400d0e18)(puVar3,param_1 + 0x77);
  (*(code *)PTR_FUN_400d0e18)(puVar4,puVar3);
  (*(code *)PTR_FUN_400d0e18)(puVar4,param_1 + 0x21);
  (*(code *)PTR_FUN_400d0e18)(puVar4,param_1 + 0x28);
  param_1[0xc4] = param_1 + 0x4e;
  param_1[0xc5] = (int)param_1 + 0x159;
  return;
}


