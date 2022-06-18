#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned uint;
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
void setup(void);
void bubble_sort(uint *array, uint array_size); // FUN_00010931

int 
main(int argc, char** argv) { 
  // there's an "and" operation to %esp, so offset between %esp, %ebp 
  // can vary;
  // uint canary;          // 0x7c(%esp)
  char name_buffer[64]; // 0x3c(%esp)
  uint array[8];        // 0x1c(%esp)
  uint array_size;      // 0x18(%esp)
  
  setup(); // FUN_000108b5
  printf("What your name :");
  read(0,name_buffer,0x40);
  printf("Hello %s,How many numbers do you what to sort :",name_buffer);
  scanf("%u", &array_size);
  if (array_size != 0) {
    uint *puVar3 = array; // edi
    uint uVar2 = 0; // esi
    do {
      printf("Enter the %d number : ",uVar2);
      fflush(stdout);
      scanf("%u",puVar3);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < array_size);
  }
  bubble_sort(array,array_size); // FUN_00010931
  puts("Result :");
  if (array_size != 0) {
    uint uVar2 = 0; // esi
    do {
      printf("%u ",array[uVar2]);
      uVar2 = uVar2 + 1;
    } while (uVar2 < array_size);
  }

  return 0;
}

void 
bubble_sort(uint *nums, uint size)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int in_GS_OFFSET;
  
  puts("Processing......");
  sleep(1);
  if (size == 1) {
LAB_000109a9:
    if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
      FUN_00010ba0();
    }
    return;
  }
  iVar4 = size + -2;
  puVar5 = nums + size + -1;
  do {
    puVar3 = nums;
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

