#include <stdio.h>
#include <stdlib.h>

#define STU_NUM 4
#define COURSE_NUM 5

typedef struct {
    int id;               // 学号
    double score[COURSE_NUM];  // 5门课程的成绩
    double avg;                // 平均分
} Student;

// 1. 输入（或初始化）数据
void inputData(Student *stu, int n) {
    for(int i = 0; i < n; i++){
        printf("请输入第 %d 个学生的学号：", i+1);
        scanf("%d", &(stu + i)->id);
        double sum = 0;
        for(int j = 0; j < COURSE_NUM; j++){
            printf("  请输入第 %d 门课成绩：", j+1);
            scanf("%lf", &((stu + i)->score[j]));
            sum += (stu + i)->score[j];
        }
        (stu + i)->avg = sum / COURSE_NUM;
        printf("\n");
    }
}

// 2. 求第一门课程的平均分
double course1Average(Student *stu, int n) {
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += (stu + i)->score[0];  // 第一门课下标 0
    }
    return sum / n;
}
// 3. 找出有2门及以上不及格的学生，输出其信息
void find2Fails(Student *stu, int n) {
    printf("【有2门及以上不及格的学生】\n");
    for(int i = 0; i < n; i++){
        int failCount = 0;
        for(int j = 0; j < COURSE_NUM; j++){
            if((stu + i)->score[j] < 60){
                failCount++;
            }
        }
        if(failCount >= 2) {
            // 输出学号、全部成绩及平均分
            printf("学号: %d  成绩:", (stu + i)->id);
            for(int j = 0; j < COURSE_NUM; j++){
                printf(" %.1f", (stu + i)->score[j]);
            }
            printf("  平均: %.2f\n", (stu + i)->avg);
        }
    }
    printf("\n");
}
// 4. 找出平均成绩 > 90 或全部课程 > 85 的学生
void findHighAchievers(Student *stu, int n) {
    printf("【平均成绩 > 90 或者全部课程成绩 > 85 的学生】\n");
    for(int i = 0; i < n; i++){
        // 判断平均成绩
        int allAbove85 = 1;  // 假设全部课程都>85
        for(int j = 0; j < COURSE_NUM; j++){
            if((stu + i)->score[j] <= 85) {
                allAbove85 = 0;
                break;
            }
        }

        if((stu + i)->avg > 90 || allAbove85){
            printf("学号: %d  成绩:", (stu + i)->id);
            for(int j = 0; j < COURSE_NUM; j++){
                printf(" %.1f", (stu + i)->score[j]);
            }
            printf("  平均: %.2f\n", (stu + i)->avg);
        }
    }
    printf("\n");
}

int main(){
    Student stu[STU_NUM];
    
    printf("请录入 %d 个学生的成绩：\n", STU_NUM);
    inputData(stu, STU_NUM);

    // 1) 第一门课程的平均分
    double avgCourse1 = course1Average(stu, STU_NUM);
    printf("\n第一门课程的平均分是：%.2f\n\n", avgCourse1);

    // 2) 找出有2门及以上不及格的学生
    find2Fails(stu, STU_NUM);

    // 3) 找出平均 > 90 或者全部课程 > 85 的学生
    findHighAchievers(stu, STU_NUM);

    return 0;
}

