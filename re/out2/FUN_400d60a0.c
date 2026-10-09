// requested 400d60a0 body [[400d60a0, 400d6122] [400d6134, 400d6135]]
// callees: FUN_400e9b38 FUN_400e9fc4 FUN_400df6c0 FUN_400e956c FUN_400f4a20 FUN_400e99ac FUN_400df344 
// callers: 

void FUN_400d60a0(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  puVar1 = PTR_s_text_html_400d0360;
  iVar3 = DAT_400d031c;
  piVar2 = DAT_400d0060;
  memw();
  iStack_24 = *DAT_400d0060;
  memw();
  if (*(char *)(DAT_400d037c + 800) == '\0') goto LAB_400d60f1;
  FUN_400e956c(DAT_400d00cc,PTR_s_iOS_detected_400d039c);
  FUN_400df6c0(iVar3,200,puVar1,PTR_s_<_DOCTYPE_HTML_PUBLIC_____W3C__D_400d03a0);
  while( true ) {
    iVar3 = iStack_24;
    memw();
    memw();
    piVar2 = (int *)*piVar2;
    if ((int *)iStack_24 == piVar2) break;
    FUN_400f4a20();
LAB_400d60f1:
    FUN_400e9b38(auStack_34,PTR_s_<_DOCTYPE_html>_<html>_<head><ti_400d03a4);
    FUN_400e9fc4(auStack_34,PTR_s_<_div>_<_body>_<_html>_400d03a8);
    FUN_400df344(iVar3,200,puVar1,auStack_34);
    FUN_400e99ac(auStack_34);
  }
  return;
}


