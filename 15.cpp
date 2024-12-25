#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// �����������������Ԫ�ط��м䣬��С��4��Ԫ�ط��Ľ�
void rearrange_matrix(int (*mat)[SIZE]) {
    // 1. �� 5x5 �ľ�������һά����洢��ָ�뷽ʽ��
    int temp[SIZE * SIZE];
    int *p = temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(p++) = mat[i][j];
        }
    }

    // 2. �� temp ����������򣬱����ҵ����ֵ����Сֵ
    //   ���������ǿ����������ֵ��Ҳ�����������������ʾ����ֱ��������򵥣�
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

    // ��ʱ temp[0] ����Сֵ��temp[1] �ڶ�С..., temp[total-1] �����ֵ
    int maxVal = temp[total - 1];
    int minVal[4];
    for(int i = 0; i < 4; i++){
        minVal[i] = temp[i];
    }

    // 3. �ҵ�ԭ���������ֵ��λ�ã�����������λ��(mat[2][2])����
    //   ��������ȱ���ԭ�����ҵ������ֵ��λ��
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
    // ����
    int tmp = mat[2][2];
    mat[2][2] = mat[maxI][maxJ];
    mat[maxI][maxJ] = tmp;

    // 4. �ĸ�����4����Сֵ���� (����С����˳��)
    //   corners: (0,0), (0,4), (4,0), (4,4)
    //   minVal: ��С����
    int cornerPos[4][2] = {{0,0},{0,4},{4,0},{4,4}};
    for(int k = 0; k < 4; k++){
        int ci = cornerPos[k][0];
        int cj = cornerPos[k][1];
        // ��ԭ�������ҵ� minVal[k] ��λ�ò�����
        // ����ֱ�Ӱ� corner ��ֵ�� minVal[k] �Ե� -> �������� minVal[k] ��ԭʼλ��
        // ��������ֻҪ corner λ�õ�ֵ���ǵ�ǰ minVal[k]���Ǿͽ���
        //          ������������ظ�ֵ����Ƚ��鷳������Ϊ����ʾ˼·�����������㹻����

        // �ҳ� minVal[k] ��ԭ�����λ��
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
        // ���� corner <-> minVal[k] λ��
        tmp = mat[ci][cj];
        mat[ci][cj] = mat[foundI][foundJ];
        mat[foundI][foundJ] = tmp;
    }
}

int main() {
    // ʾ������(����������)
    int matrix[SIZE][SIZE] = {
        {10, 2,  7,  4,  12},
        {8,  11, 15, 6,  3 },
        {22, 16, 30, 5,  1 },
        {9,  14, 18, 19, 27},
        {25, 21, 17, 28, 13}
    };
    
    printf("ԭ����\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // ���ú�������
    rearrange_matrix(matrix);

    printf("\n��������\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

