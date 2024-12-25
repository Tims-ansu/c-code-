#include <stdio.h>
#include <stdlib.h>

#define STU_NUM 4
#define COURSE_NUM 5

typedef struct {
    int id;               // ѧ��
    double score[COURSE_NUM];  // 5�ſγ̵ĳɼ�
    double avg;                // ƽ����
} Student;

// 1. ���루���ʼ��������
void inputData(Student *stu, int n) {
    for(int i = 0; i < n; i++){
        printf("������� %d ��ѧ����ѧ�ţ�", i+1);
        scanf("%d", &(stu + i)->id);
        double sum = 0;
        for(int j = 0; j < COURSE_NUM; j++){
            printf("  ������� %d �ſγɼ���", j+1);
            scanf("%lf", &((stu + i)->score[j]));
            sum += (stu + i)->score[j];
        }
        (stu + i)->avg = sum / COURSE_NUM;
        printf("\n");
    }
}

// 2. ���һ�ſγ̵�ƽ����
double course1Average(Student *stu, int n) {
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += (stu + i)->score[0];  // ��һ�ſ��±� 0
    }
    return sum / n;
}
// 3. �ҳ���2�ż����ϲ������ѧ�����������Ϣ
void find2Fails(Student *stu, int n) {
    printf("����2�ż����ϲ������ѧ����\n");
    for(int i = 0; i < n; i++){
        int failCount = 0;
        for(int j = 0; j < COURSE_NUM; j++){
            if((stu + i)->score[j] < 60){
                failCount++;
            }
        }
        if(failCount >= 2) {
            // ���ѧ�š�ȫ���ɼ���ƽ����
            printf("ѧ��: %d  �ɼ�:", (stu + i)->id);
            for(int j = 0; j < COURSE_NUM; j++){
                printf(" %.1f", (stu + i)->score[j]);
            }
            printf("  ƽ��: %.2f\n", (stu + i)->avg);
        }
    }
    printf("\n");
}
// 4. �ҳ�ƽ���ɼ� > 90 ��ȫ���γ� > 85 ��ѧ��
void findHighAchievers(Student *stu, int n) {
    printf("��ƽ���ɼ� > 90 ����ȫ���γ̳ɼ� > 85 ��ѧ����\n");
    for(int i = 0; i < n; i++){
        // �ж�ƽ���ɼ�
        int allAbove85 = 1;  // ����ȫ���γ̶�>85
        for(int j = 0; j < COURSE_NUM; j++){
            if((stu + i)->score[j] <= 85) {
                allAbove85 = 0;
                break;
            }
        }

        if((stu + i)->avg > 90 || allAbove85){
            printf("ѧ��: %d  �ɼ�:", (stu + i)->id);
            for(int j = 0; j < COURSE_NUM; j++){
                printf(" %.1f", (stu + i)->score[j]);
            }
            printf("  ƽ��: %.2f\n", (stu + i)->avg);
        }
    }
    printf("\n");
}

int main(){
    Student stu[STU_NUM];
    
    printf("��¼�� %d ��ѧ���ĳɼ���\n", STU_NUM);
    inputData(stu, STU_NUM);

    // 1) ��һ�ſγ̵�ƽ����
    double avgCourse1 = course1Average(stu, STU_NUM);
    printf("\n��һ�ſγ̵�ƽ�����ǣ�%.2f\n\n", avgCourse1);

    // 2) �ҳ���2�ż����ϲ������ѧ��
    find2Fails(stu, STU_NUM);

    // 3) �ҳ�ƽ�� > 90 ����ȫ���γ� > 85 ��ѧ��
    findHighAchievers(stu, STU_NUM);

    return 0;
}

