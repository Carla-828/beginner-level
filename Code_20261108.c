#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char nam[55];
int sco,cnt;

typedef struct{
    char name[55];
    int score;
}Student;

Student students[55];

//交换两个学生
void swap(int x,int y)
{
    Student tmp = students[y];
    students[y] = students[x];
    students[x] = tmp;
}

//修复完整冒泡排序：按分数降序
void sort()
{
    for(int i = cnt; i > 1; i--)
    {
        for(int j = 1; j < i; j++)
        {
            if(students[j].score < students[j+1].score)
            {
                swap(j,j+1);
            }
        }
    }
}

//【新增】根据分数得到等级和绩点（燕大标准）
void getGradePoint(int score, char *level, double *gpa)
{
    if(score >=96 && score <=100)
    {
        strcpy(level,"A+");
        *gpa = 4.5;
    }
    else if(score >=90 && score <=95)
    {
        strcpy(level,"A");
        *gpa =4.0;
    }
    else if(score >=85 && score <=89)
    {
        strcpy(level,"B+");
        *gpa =3.5;
    }
    else if(score >=80 && score <=84)
    {
        strcpy(level,"B");
        *gpa =3.0;
    }
    else if(score >=75 && score <=79)
    {
        strcpy(level,"C+");
        *gpa =2.5;
    }
    else if(score >=70 && score <=74)
    {
        strcpy(level,"C");
        *gpa =2.0;
    }
    else if(score >=65 && score <=69)
    {
        strcpy(level,"D+");
        *gpa =1.5;
    }
    else if(score >=60 && score <=64)
    {
        strcpy(level,"D");
        *gpa =1.0;
    }
    else
    {
        strcpy(level,"F");
        *gpa =0.0;
    }
}

int main()
{
    int n;
    bool tru = true;
    cnt = 0;
    while(tru)
    {
        printf("\n====学生成绩管理系统（燕山大学绩点版）====\n");
        printf("请输入数字，选择你的操作：\n"
            "1.录入/修改学生成绩\n"
            "2.查询学生百分制成绩\n"
            "3.查询学生成绩排名\n"
            "4.查询第x名学生姓名与成绩\n"
            "5.输出所有学生成绩（含等级、绩点）\n"
            "7.查询学生的等级与绩点\n"
            "6.退出\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                printf("请输入学生成绩：");
                scanf("%d", &sco);
                if(sco<0||sco>100){
                    printf("成绩范围0‑100，录入失败！\n");
                    break;
                }
                int found = 0;
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        students[i].score = sco;
                        found = 1;
                        break;
                    }
                }
                if(!found)
                {
                    strcpy(students[++cnt].name, nam);
                    students[cnt].score = sco;
                }
                sort();
                printf("录入/修改完成！\n");
                break;
            }
            case 2:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                int found = 0;
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        printf("学生 %s 的成绩为：%d\n", students[i].name, students[i].score);
                        found = 1;
                        break;
                    }
                }
                if(!found)printf("该学生成绩尚未录入\n");
                break;
            }
            case 3:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                int found =0;
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        printf("学生 %s 的排名为：%d\n", students[i].name, i);
                        found =1;
                        break;
                    }
                }
                if(!found) printf("未找到该学生\n");
                break;
            }
            case 4:
            {
                printf("请输入排名：");
                int rank;
                scanf("%d", &rank);
                if(rank <1)printf("无效排名，请确认操作。\n");
                else if(rank > cnt)printf("当前共有 %d 名学生\n", cnt);
                else {
                    printf("第%d名：%s ，分数：%d\n",rank,students[rank].name,students[rank].score);
                }
                break;
            }
            case 5:
            {
                if(cnt==0){
                    printf("暂无学生数据！\n");
                    break;
                }
                char lv[5];
                double gp;
                for(int i = 1; i <= cnt; i++){
                    getGradePoint(students[i].score, lv, &gp);
                    printf("排名：%d 姓名：%s 分数：%d 等级：%s 绩点：%.1f\n",
                           i, students[i].name, students[i].score, lv, gp);
                }
                break;
            }
            case 7:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                int found=0;
                char lv[5];
                double gp;
                for(int i=1;i<=cnt;i++)
                {
                    if(strcmp(students[i].name,nam)==0)
                    {
                        getGradePoint(students[i].score,lv,&gp);
                        printf("学生：%s，百分制：%d，等级：%s，绩点：%.1f\n",
                               nam,students[i].score,lv,gp);
                        found=1;
                        break;
                    }
                }
                if(!found) printf("没有找到该学生\n");
                break;
            }
            case 6:
            {
                tru = false;
                printf("程序退出。\n");
                break;
            }
            default:
                printf("无效的操作，请重新输入。\n");
        }
    }
    system("pause");
    return 0;
}