#include<stdio.h>
#include<stdio_ext.h>


int main(){
    char s[5];
    fgets(s,5,stdin);
    printf("string : %s\n",s);
    __fpurge(stdin);
    fgets(s,5,stdin);
    printf("buffered : %s",s);
}
