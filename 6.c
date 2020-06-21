
#define BOMB 1


// phase6_1 数组共6个元素，每个元素必须小于等于6, 且相邻两个元素都不能相同
// phase6_2 对每个数组元素a[i], 用 7 - a[i]的值替换

int phase6_1(int arr[6]) {

    int r12d, r13, rsi;
    int rsp, rbp;
    rsp = &arr;     // 401106 指向栈顶，即arr数组首地址
    r13 = rsp;      // r13初值为rsp, 内存为数组第一个元素
    rsi = rsp;

    // read_six_numbers
    r14 = rsp;      
    r12d = 0;

    // 数组每个值必须小于6, 
    while(r12d < 6) {
        rbp = r13;      // 0x401114, 初值等于rsp
        eax = *(r13); 
        if(eax > 6) {
            return BOMB;
        }
        ++r12d;
        if(r12d == 6) {
            break;
        }
        ebx = r12d; 
        while(1) {
            eax = ebx;  // 0x401135
            eax = (int *)(rsp + 4 * eax); // 指向数组下一个元素
            if(eax == (int *)rbp) { // 0x401145
                return BOMB;
            }
            ebx += 1;
            if(ebx <= 5) {
                continue;
            }
            r13 += 4;   // 指向下一个数组
            break;
       }
    }
    return 0;
}

int phase6_2()
{
    rsi = rsp + 0x18;    // 0x401153
    r14 = rsp;           // 被调用者保存寄存器, r14值不会修改，应等于rsp

    eax = r14;   // 被调用者保存寄存器, r14值不会修改，应等于rsp, 即指向数组首地址
    ecx = 7;     // 用7 - a[i] 替换 a[i]

    while(rax != rsi) {     // 相当于for循环遍历数组
        edx = ecx;
        edx -= *eax;
        *eax = edx;
        eax += 4;   // 指向下一个数组
    }

    esi = 0;        // 0x401197开始
    ecx = rsp[esi];
    edx = 0x6032d0; // TODO: 需要查看内存
    
0x401176:
    if(ecx > 1) {   // 如果第一个数大于1
        eax = 1;
        while(eax != ecx) {     // 0x401176
            rdx = *(rdx + 8);
            ++eax;
        }
    }

0x401188:
    rsp[rsi / 2 + 8] = rdx;
    rsi += 4;
    if(rsi == 24) {
        goto 0x4011ab;
    } else {
        ecx = rsp[rsi];
        if(ecx <= 0x1) {
            goto 0x401188;
        } else {
            eax = 1;
            goto 0x401176;
        }
    }
    rbx = rsp[8];
    rax = rsp[10];
    rsi = rsp[20];
    rcx = rbx;
    rdx = *($rax);
    *($rcx + 8) = rdx;
    rax += 8;
    if(rax == rsi) {
        goto 0x4011d2;
    } else {
        rcx = rdx;
        goto 0x4011bd;
    }
    return 0;
}

// 初值esi: 501, rdi: 6303984
// 需要返回2
int phase_secret(int esi, int rdi)
{
    esi = input;    //501
    while(rdi) {
        edx = *rdi;
        if(edx <= esi) {
            eax = 0;
            if(edx == esi) {
                return eax;
            }
            rdi = *(rdi + 0x10);
            eax = phase_secret(esi, rdi);
            eax = 2 * eax + 1;
            return eax;
        } else {
            edi = *(edi + 0x8);
            eax = phase_secret(esi, rdi);
            eax *= 2;
            return eax;
        }
    }
    eax = -1;
    return eax;
}


















