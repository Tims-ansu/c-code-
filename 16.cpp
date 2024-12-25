#include <stdio.h>
#include <stdlib.h>

int josephus_last_man(int n) {
    // ��̬��������ռ䣬���ڱ��ÿ�����Ƿ���Ȧ��
    int *people = (int *)malloc(n * sizeof(int));
    if (people == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    // ��ʼ����1 ��ʾ����Ȧ�У�0 ��ʾ���˳�
    for (int i = 0; i < n; i++) {
        *(people + i) = 1;
    }

    int leaveCount = 0;  // ���˳�����
    int count = 0;       // ����������
    int index = 0;       // ��ǰָ��ָ����±�
    
    while (leaveCount < n - 1) {
        // �������δ�˳����Ž��б���
        if (*(people + index) == 1) {
            count++;
            // ��������3�������˳�
            if (count == 3) {
                *(people + index) = 0;
                leaveCount++;
                count = 0; 
            }
        }
        // ָ�����һλ��ģ�⻷��
        index = (index + 1) % n;
    }

    // �ҳ������Ȧ�������
    int lastMan = 0;
    for (int i = 0; i < n; i++) {
        if (*(people + i) == 1) {
            lastMan = i + 1;  // �����±� i ��Ӧ�� (i+1) ����
            break;
        }
    }

    free(people);
    return lastMan;
}

int main() {
    int n;
    printf("���������� n��");
    scanf("%d", &n);

    int answer = josephus_last_man(n);
    printf("������µ���ԭ���� %d ���ˡ�\n", answer);

    return 0;
}

