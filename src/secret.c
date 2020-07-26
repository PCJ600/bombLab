#include<stdio.h>
// 二叉树的数组表示，树高4层, 共15个节点
const int arrTree[] = { 0x24, 
                        0x8, 0x32,
                        0x6, 0x16, 0x2d, 0x6b,
                        0x1, 0x7 , 0x14, 0x23, 0x28, 0x2f, 0x63, 0x3e9 };

int fun7(int idx, int userInput) {
    if(idx < 0 || idx > 14) {
        return -1;  // 如当前节点为NULL, 返回-1
    }

    int ret = 0;
    if(arrTree[idx] < userInput) {
        ret = 2 * fun7(2 * idx + 2, userInput) + 1; // 取当前节点的右子女
    } else if(arrTree[idx] > userInput) {
        ret = 2 * fun7(2 * idx + 1, userInput); // 取当前节点的左子女
    }
    return ret;
}

int main() {
    for(int i = 0; i < 1002; ++i) 
        if(fun7(0, i) == 2) // idx初值为0, 表示从二叉树的根开始递归
            printf("answer: %d\n", i);
    return 0;
}
