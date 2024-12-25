#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// 函数：将矩阵中最大元素放中间，最小的4个元素放四角
void rearrange_matrix(int (*mat)[SIZE]) {
    // 1. 将 5x5 的矩阵拉成一维数组存储（指针方式）
    int temp[SIZE * SIZE];
    int *p = temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(p++) = mat[i][j];
        }
    }

    // 2. 对 temp 数组进行排序，便于找到最大值和最小值
    //   （这里我们可以先找最大值，也可以整体排序看情况；示例中直接排序最简单）
    int total = SIZE * SIZE;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // 此时 temp[0] 是最小值，temp[1] 第二小..., temp[total-1] 是最大值
    int maxVal = temp[total - 1];
    int minVal[4];
    for(int i = 0; i < 4; i++){
        minVal[i] = temp[i];
    }

    // 3. 找到原矩阵中最大值的位置，将其与中心位置(mat[2][2])交换
    //   这里可以先遍历原矩阵找到该最大值的位置
    int maxI = 0, maxJ = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(mat[i][j] == maxVal){
                maxI = i;
                maxJ = j;
                break;
            }
        }
    }
    // 交换
    int tmp = mat[2][2];
    mat[2][2] = mat[maxI][maxJ];
    mat[maxI][maxJ] = tmp;

    // 4. 四个角与4个最小值交换 (按从小到大顺序)
    //   corners: (0,0), (0,4), (4,0), (4,4)
    //   minVal: 从小到大
    int cornerPos[4][2] = {{0,0},{0,4},{4,0},{4,4}};
    for(int k = 0; k < 4; k++){
        int ci = cornerPos[k][0];
        int cj = cornerPos[k][1];
        // 在原矩阵中找到 minVal[k] 的位置并交换
        // 或者直接把 corner 的值与 minVal[k] 对调 -> 但需先找 minVal[k] 的原始位置
        // 简化做法：只要 corner 位置的值不是当前 minVal[k]，那就交换
        //          但是如果出现重复值，会比较麻烦。这里为了演示思路，假设数据足够区分

        // 找出 minVal[k] 在原矩阵的位置
        int foundI = -1, foundJ = -1;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(mat[i][j] == minVal[k]) {
                    foundI = i;
                    foundJ = j;
                    break;
                }
            }
            if(foundI != -1) break;
        }
        // 交换 corner <-> minVal[k] 位置
        tmp = mat[ci][cj];
        mat[ci][cj] = mat[foundI][foundJ];
        mat[foundI][foundJ] = tmp;
    }
}

int main() {
    // 示例矩阵(可自行输入)
    int matrix[SIZE][SIZE] = {
        {10, 2,  7,  4,  12},
        {8,  11, 15, 6,  3 },
        {22, 16, 30, 5,  1 },
        {9,  14, 18, 19, 27},
        {25, 21, 17, 28, 13}
    };
    
    printf("原矩阵：\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // 调用函数处理
    rearrange_matrix(matrix);

    printf("\n处理后矩阵：\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

