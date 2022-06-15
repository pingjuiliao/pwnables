#include <stdio.h>
#include <unistd.h>
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

int get_expr(u8* buffer, int max_length);
void calc(void);
struct NumPool {
    u32 pool[0x90];
    u32 pool_size;
};



int
main(int argc, char** argv) {
    calc();
    puts("Merry Christmas!");
    return 0;
}

void
calc(void) {
    char expr_buf[0x400]; // ebp - 0x40c
    struct NumPool num_pool;
    // num_pool->pool[]:   ebp-0x59c
    // num_pool->pool_idx: ebp-0x5a0

    // calc+20
    bzero(expr_buf, 0x400);
    while((int r = get_expr(expr_buf, 0x400)) != 0) {

        // <calc+83>
        init_pool(&num_pool);
        int parse_result = parse_expr(expr_buf, &num_pool);
        if (parse_result == 0) 
            continue;
        printf("%d\n", num_pool->pool[pool_size-1]);

        // calc + 20
        bzero(expr_buf, 0x400);
    }
    // <calc+68> stack_guard, return
    return;
}

void
init_pool(struct NumPool* num_pool) {
    int i = 0; // ebp-0x4
    num_pool->pool_size; = 0;
    while (i <= 0x63) {
        num_pool[i] = 0;
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
parse_expr(u8* expr_buf, struct NumPool* np) {
    char local_buf[0x64]; // ebp - 0x70
    s32 atoi_int;   // ebp - 0x74
    u8* heap_obj;    // ebp - 0x78
    u32 offset1;   // ebp - 0x7c
    u32 local_offset = 0; // ebp - 0x80
    u32 offset0 = 0; // ebp - 0x84
    u8* buf1 = expr_buf; //ebp - 0x88
    u8* buf0 = expr_buf; // ebp - 0x8c, the expression buffer
    struct NumPool* num_pool = np; // ebp - 0x90

    // parse_expr+58
    bzero(local_buf, 0x64);
    offset0 = 0;


    while (1) {
        // parse_expr + 87
        while (buf0[offset0] - '0' < 9) {
            // parse_expr+762
            offset0++;
        }
        // parse_expr+119
        offset1 = buf1 - (buf0 + offset0);
        heap_obj = malloc(offset1 + 1);
        memcpy(heap_obj, buf1, offset1);
        heap_obj[offset1] = '\0';

        if (strcmp(heap_obj, "0") == 0) {
            // parse_expr+227
            puts("prevent division by zero");
            fflush(stdout);
            // jmp parse_expr+ 821
            // parse_expr+821
            break;
        }

        // parse_expr + 262
        atoi_int = atoi(heap_obj);
        if (atoi_int > 0) {
            // parse_expr + 282 
            num_pool->pool_size += 1;

            // pase_expr + 301
            num_pool->pool[num_pool->pool_size - 1] = atoi_int;
        }

        // parse_expr + 314
        if (*((char *) (buf0 + offset0)) != 0) {
            // parse_expr + 335
            if (*(buf0 + offset0 + 1) - '0' > 9) {
                // parse_expr + 406
                puts("expression error"); // e.g. 1 ++ 2
                fflush(stdout);
                break;
            }
        }
        // parse_expr + 366
        buf1 = buf0 + offset0 + 1;
        // parse_expr + 389
        if (local_buf[local_offset] != 0) {
            // 473
            // u32 idx = buf0[offset0] - 0x25;
            switch(buf0[offset0]) {
                case '+':
                case '-':
                    // 514
                    eval(&num_pool, local_buf[local_idx]);
                    local_buf[local_offset] = buf0[offset0];
                    break;
                case '%':
                case '*':
                case '/':
                    // 578
                    if (local_buf[local_offset] != '+' &&
                            local_buf[local_offset] != '-') {
                        // 641 
                        eval(&num_pool, local_buf[local_offset]);    
                        local_buf[local_offset] = buf0[offset0];
                    } else {
                        // 608
                        local_offset ++;
                        local_buf[local_offset] = buf0[offset0];
                    }
                    break;
                default:
                    // 702
                    eval(&num_pool, local_buf[local_offset]);
                    local_offset -= 1;
                    break; // jmp 738
            }
        } else {
            // 441
            local_buf[local_offset] = buf0[offset0];
        }

        // 738
        if (buf0[offset0] == 0) {
            // 810
            while (local_offset != 0) {
                // 774
                eval(, local_buf_[local_offset]);
                local_offset -= 1;
            }
            // 816
            return;
        } else {
            // 762
            offset0 ++;
            continue;    
        }
    
    } // end while loop parse_expr + 87
    return;
}

void
eval(struct NumPool *num_pool, char op) {
    switch(op) {
        case '+':
            // 57
            num_pool->pool[num_pool->pool_size - 2] += \
                        num_pool->pool[num_pool->pool_size - 1];
            break;
        case '-':
            //109
            num_pool->pool[num_pool->pool_size - 2] += \
                        num_pool->pool[num_pool->pool_size - 1];
            break; 
        case '*':
            //158
        case '/':
            //208

        default:
            break;
    }
    //259
}
