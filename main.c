#include <stdio.h>
#include<dirent.h>
#include <string.h>


#   示例temp.conf
#   dev tun
#   type tcp
#    remote 172.16.2.2.0 990
#    hahah  rrrr

//函数可封装为自己的方法函数使用
int re_write_config(char *src ，char *des);  //将src 替换为 des 
int main(int argc, char *argv[])
{
    FILE *fp = NULL;    //旧的配置文件
    FILE *new_fp = NULL;  //新的配置文件

    fp = fopen("./temp.conf","r");
    char buff[128] = {0};
    int ret = 0;
    int curr = 0 ;    //计数，当第一次运行程序时，采用创建新文件，以后则以追加方式打开
    while(fgets(buff,128,fp)){       
        if(curr == 0){
            new_fp = fopen("./client.conf","wb");
        }
        else{
            new_fp = fopen("./client.conf","a+");
        }
        if(strncmp("remote",buff,strlen("remote")) == 0){
            // 组织要写入的字符串 sprintf(buff,"%s%s","hello","world");或者其他方法，自行组织即可
            //当封装为函数的时候，可以用char *des进行替换
            memcpy(buff,"remote 192.168.1.123 1194",strlen("remote 192.168.1.123 1194"));
            ret = fwrite(buff,1,strlen(buff),new_fp);                    
            if(ret < 0){
                printf(" write to config fail!\n");
                return -1;
            }
        }
        else{
            ret = fwrite(buff,1,strlen(buff),new_fp);
            if(ret < 0){
                printf(" write to config fail 2!\n");
                return -1;
            }
        }
        fclose(new_fp);    //此处一定要执行关闭新写入的文件描述符，不然写入文件流会乱掉
        curr++;
    }
    fclose(fp);
    remove("./temp.conf");
    printf("HAND END!\n");
    return 0;
}
