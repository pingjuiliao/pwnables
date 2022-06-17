
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010931(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  puts("Processing......");
  sleep(1);
  if (param_2 == 1) {
LAB_000109a9:
    if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
      FUN_00010ba0();
    }
    return;
  }
  iVar4 = param_2 + -2;
  puVar5 = param_1 + param_2 + -1;
  do {
    puVar3 = param_1;
    if (iVar4 != -1) {
      do {
        uVar2 = *puVar3;
        if (puVar3[1] < uVar2) {
          *puVar3 = puVar3[1];
          puVar3[1] = uVar2;
        }
        puVar3 = puVar3 + 1;
      } while (puVar5 != puVar3);
      if (iVar4 == 0) goto LAB_000109a9;
    }
    iVar4 = iVar4 + -1;
    puVar5 = puVar5 + -1;
  } while( true );
}

