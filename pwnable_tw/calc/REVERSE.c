#include <stdio.h>
#include <unistd.h>
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

u8[400] ebp_40c; // NULL

int get_expr(u8* buffer, int max_length);
void calc(void);

int
main(int argc, char** argv) {
    calc();
    puts("Merry Christmas!");
    return 0;
}

void
calc(void) {
    char expr_buf[0x400]; // ebp - 0x40c
    int pool[];           // ebp - 0x59c
    int pool_idx;         // ebp - 0x5a0
    int r;
    // calc+20
    bzero(expr_buf, 0x400);
    while(
        (int r = get_expr(expr_buf, 0x400)) != 0) {


        // <calc+83>
        init_pool(&pool_idx);
        int parse_result = parse_expr(expr_buf, &pool_idx);
        if (parse_result == 0) 
            continue;
        printf("%d\n", pool[pool_idx-1]);
        
        // calc + 20
        bzero(expr_buf, 0x400);
    }
    // <calc+68> stack_guard, return
    return;
}

void
init_pool(int* param) {
    int i = 0; // ebp-0x4
    *param = 0;
    while (ebp_4h <= 0x63) {
        int[] pool = param + 4;
        pool[i] = 0;
        i++;
    }

}


int
get_expr(u8* buffer, int max_length) {
    int len;
    char c;
    while(r = read(0, &c, 1)) {
        if (r == 0 || c == '\n') {
            break;
        }
        if ((c <= '/' && '9' < c) || c != '+' || c != '-' || c != '*' || 
                c != '/' || c != '%') {
            continue;
        }
        buffer[len++] = c;

    }
    buffer[max_length] = '\0';
    return len;
}


void 
parse_expr(char* expr_buf, &pool_idx) {
    char ebp70h[0x64];
    s32 result;   // ebp - 0x74
    u8* heap_obj;    // ebp - 0x78
    u32 size;   // ebp - 0x7c
    u32 offset; // ebp - 0x84
    u32 last_start = glob_buffer; //ebp - 0x88
    u8* ptr = expr_buf; // ebp - 0x8c, the expression buffer
    u32* p_poolidx; 
    // parse_expr+72
    bzero(ebp70h, 0x64);
    offset = 0;
    eax = *(ptr + offset); // parse_expr+101
    while  (eax - '0' < 9) {
        // parse_expr+762
        offset += 1
    }
    // parse_expr+119
    eax = ptr + offset;
    size = eax - glob_buffer;
    heap_obj = malloc(size + 1);

    // parse_expr+188
    memcpy(heap_obj, last_start, size); 
    heap_obj[size] = '\0';

    int r = strcmp(heap_obj, "0");
    if (r == 0) {
        // parse_expr+227
        puts("prevent division by zero");

    }
    // parse_expr + 262
    result = atoi(heap_obj);
    if (result <= 0) {
       // parse_expr + 314 
    
    }

    // parse_expr + 282n
    *p_poolidx ++;

    // TODO parse_expr + 301?
    // interesting: +310
}

