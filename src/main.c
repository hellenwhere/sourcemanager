//modify begin with creat
#include"dirent.h"
int select_name(char name[])
{
    int i;
    for(i=0;name[i]!=0;i++)
    {
        if(isalpha(name[i])||name[i]=='.')
            return 0;
    }
    return 1;
}

int process_num(void)
{
    DIR* dir;
    struct dirent* ptr;
    int total = 0;
    int i;
    char dir_buf[256];
    char buffer[256];
    char* info[26];
    int  fd;    
    dir = opendir("/proc");
    while((ptr=readdir(dir))!=0)
    {
       //printf("while cycle %s \r\n",ptr->d_name);
        if(select_name(ptr->d_name))
        {
            sprintf(dir_buf,"/proc/%s/stat",ptr->d_name);
            fd = open(dir_buf,O_RDONLY);
            read(fd,buffer,sizeof(buffer);
            close(fd);
            info[0]=strok(buffer,delim);
            for(i=0;i<26;i++)
            {
                info[i]=strok(NULL,delim);
            }
            info[]
            total++;
        }
    }
    return total;
}


int main(int argc,char* argv[])
{
    int processnum =0;
    processnum = process_num();
    printf("proccess num %d \r\n",processnum);
    return 0;
}
