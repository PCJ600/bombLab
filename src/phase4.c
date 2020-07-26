#include<stdio.h>

int func4(int x, int y, int z) {
    int ecx;                
    int ret = z - y;        

    if(z < y) {
        ret += 1;
    }
    ret >>= 1;
    ecx = ret + y;          

    if(ecx == x) {
        return 0;
    } else if (ecx <= x) {
        return 2 * func4(x, ecx + 1, z) + 1;
    } else {
        return 2 * func4(x, y, ecx - 1);
    }
    return ret;
}

int main() {
    for(int i = 0; i <= 14; ++i) {
        if(func4(i, 0, 14) == 0) {
            printf("answer: %d\n", i);
        }
    }
    return 0;
}
