
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 main(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  int in_GS_OFFSET;
  uint local_78;
  uint local_74 [8];
  undefined local_54 [64];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  FUN_000108b5();
  __printf_chk(1,"What your name :");
  read(0,local_54,0x40);
  __printf_chk(1,"Hello %s,How many numbers do you what to sort :",local_54);
  __isoc99_scanf(&DAT_00010bfa,&local_78);
  if (local_78 != 0) {
    puVar3 = local_74;
    uVar2 = 0;
    do {
      __printf_chk(1,"Enter the %d number : ",uVar2);
      fflush(stdout);
      __isoc99_scanf(&DAT_00010bfa,puVar3);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < local_78);
  }
  FUN_00010931(local_74,local_78);
  puts("Result :");
  if (local_78 != 0) {
    uVar2 = 0;
    do {
      __printf_chk(1,&DAT_00010c1d,local_74[uVar2]);
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_78);
  }
  uVar1 = 0;
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
    uVar1 = FUN_00010ba0();
  }
  return uVar1;
}

