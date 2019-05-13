#include <stdio.h>
#include <stdlib.h>
typedef struct _tagStruct{
    char name[32];
    int age;
    int grade;
}Student,*PStudent;


int Pop_struct(void){
    printf(" input number of student\n");
    int num = 0;
    scanf("%d ",&num);
    PStudent stu = (PStudent)malloc(sizeof(Student)*num);
    int i = 0;
    int j = 0;
    for(i = 0;i<num;i++){
        scanf("%s %d",stu[i].name,&stu[i].age);
    }
    printf(" You input data: \n");
    for(i = 0;i<num;i++){
        printf("name is %s: grade is %02d \n",stu[i].name, stu[i].age);
    }
    //sort and out put
    char tmp[32] = {0};

    for(i = 0;i<num -1;i++){
        for(j = 0;j<num-1 -i;j++){
            if(stu[j].age > stu[j+1].age){

                //交换年龄字段
                stu[j].age   = stu[j].age ^ stu[j+1].age;
                stu[j+1].age = stu[j].age ^ stu[j+1].age;
                stu[j].age   = stu[j].age ^ stu[j+1].age;

                //交换名字字段
                memcpy(tmp,stu[j].name,sizeof(tmp));
                memcpy(stu[j].name,stu[j+1].name,sizeof(stu[j+1].name));
                memcpy(stu[j+1].name,tmp,sizeof(tmp));
                memset(tmp,0,sizeof(tmp));

            }
        }
    }
    printf("Sort By grade : \n");
    for(i = 0;i<num;i++){
        printf("name is %s : grade is :%02d \n",stu[i].name, stu[i].age);
    }
    free(stu);
    stu = NULL;

    return 0;
}


char *deleteChar(char *str,char c){
    char *head = NULL;
    char *p = NULL;
    if(!str){
        printf("input char is NULL\n");
        return NULL;
    }
    head = p = str;
    while(*p){
        if(*p != c){
            *str++ = *p;
        }
        *p++;
    }
    *str = '\0';
    return head;
}


int main(int argc, char *argv[])
{
  //  Pop_struct();

    char test_str1[256] = {0};
    char *stree = "hello world";
    char *stree1 = "test";

    memcpy(test_str1,stree,strlen(stree));
    int len_test = strlen(stree);
    memcpy(&test_str1[len_test],stree1,strlen(stree1));
    printf(" %s \n",test_str1);
    char str1[32] = {0};
    char str2[32] = {0};
    printf(" Input str length < 32\n");
    gets(str1);
    printf("Input delete char length < 32 \n");
    gets(str2);
    int len = strlen(str2);
    int i = 0;
    for(i = 0;i<len;i++){
       deleteChar(str1,str2[i]);
    }

    printf("%s \n",str1);
    return 0;
}
