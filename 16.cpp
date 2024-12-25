#include <stdio.h>
#include <stdlib.h>

int josephus_last_man(int n) {
    // 动态申请数组空间，用于标记每个人是否在圈子
    int *people = (int *)malloc(n * sizeof(int));
    if (people == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    // 初始化：1 表示人在圈中，0 表示已退出
    for (int i = 0; i < n; i++) {
        *(people + i) = 1;
    }

    int leaveCount = 0;  // 已退出人数
    int count = 0;       // 报数计数器
    int index = 0;       // 当前指针指向的下标
    
    while (leaveCount < n - 1) {
        // 如果此人未退出，才进行报数
        if (*(people + index) == 1) {
            count++;
            // 若报数到3，该人退出
            if (count == 3) {
                *(people + index) = 0;
                leaveCount++;
                count = 0; 
            }
        }
        // 指针后移一位（模拟环）
        index = (index + 1) % n;
    }

    // 找出最后还在圈子里的人
    int lastMan = 0;
    for (int i = 0; i < n; i++) {
        if (*(people + i) == 1) {
            lastMan = i + 1;  // 数组下标 i 对应第 (i+1) 号人
            break;
        }
    }

    free(people);
    return lastMan;
}

int main() {
    int n;
    printf("请输入人数 n：");
    scanf("%d", &n);

    int answer = josephus_last_man(n);
    printf("最后留下的是原来第 %d 号人。\n", answer);

    return 0;
}

