#include <stdio.h>

int main()
{
    int n, i;
    float score[100], sum = 0, avg;

    printf("请输入学生人数：");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个学生成绩：", i + 1);
        scanf("%f", &score[i]);
        sum += score[i];
    }

    avg = sum / n;
    printf("全班平均成绩：%.2f\n", avg);

    printf("成绩高于平均分的学生：\n");
    for (i = 0; i < n; i++)
    {
        if (score[i] > avg)
        {
            printf("第%d个学生：%.2f\n", i + 1, score[i]);
        }
    }

    return 0;
}