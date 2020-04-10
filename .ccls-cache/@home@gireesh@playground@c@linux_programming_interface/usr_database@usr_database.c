#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define clear() printf("\033[H\033[J")
#define clearline() printf("\033[1A\033[J")

typedef
struct user{
    char user_name[20];
    char login_id[15];
    char password[20];
    int   age;
    struct user* next;
} user;

user* head = NULL;
user* tail = NULL;

user* add_record();
void delete_record(char*);
void modify_record();
void list_records();
void check_str(char*);
int chk_id(char*);


int main(){
    unsigned int choice;
    while(1){
        clear();
        choice = 0;
        printf("============ User Database Management System ============\n\n");
        printf("\t1.  Add Record\n");
        printf("\t2.  Delete Record\n");
        printf("\t3.  Modify Record\n");
        printf("\t4.  List Record\n");
        printf("\t5.  Exit\n\n\n");
        printf("\tSelect your choice ==> ");
        __fpurge(stdin);
        scanf("%d",&choice);
        while ( choice < 1 || choice >5){
            clearline();
            printf("\tEnter a valid choice! ==> ")    ;
            __fpurge(stdin);
            scanf("%d", &choice);
        }
        switch (choice){
            case 1: 
                if (!head){
                head = add_record();
                tail = head;
                }
                else{
                    head->next = add_record();
                    head = head->next;
                }
                break;
            case 2:
                printf("\tEnter user Login ID : ");
                __fpurge(stdin);
                char usr[15];
                delete_record(fgets(usr,strlen(usr),stdin));
                break;
            case 3:
                modify_record();
                break;
            case 4:
                clear();
                list_records();
                printf("Press Enter to continue\t");
                __fpurge(stdin);
                while(getc(stdin)!='\n');
                break;
            case 5:
                puts("Good Bye,\n");
                exit(0);
                break;
        }
    }
    return 0;
}

user* add_record(){
    user* usr = (user *)malloc(sizeof(user));
    usr->next = NULL;
    printf("\tEnter User name : ");
    __fpurge(stdin);
    check_str(fgets(usr->user_name,20,stdin));
    do{
    printf("\tEnter Login ID  : ");
    check_str(fgets(usr->login_id,15,stdin));
    }while(chk_id(usr->login_id));
    printf("\tEnter password  : ");
    check_str(fgets(usr->password,20,stdin));
    printf("\tEnter age       : ");
    __fpurge(stdin);
    scanf("%d",&usr->age);
    while (usr->age == 0){
        clearline();
        printf("\tEnter valid age : ");
        __fpurge(stdin);
        scanf("%d",&usr->age);
    }
    return usr;
}


void delete_record(char* id){
    user* u;
    for (u = tail; u; u=u->next){
        printf("%s\n",u->next->login_id);
        if(!strcmp(u->next->login_id,id)){
            user* usr ;
            usr = u->next;
            printf("debug1\n");
            u->next = usr->next;
            printf("debug2\n");
            free(usr);
            printf("debug3\n");
            return;
        }
    }
}
void modify_record(){}
void list_records(){
    puts("=======================================================================================");
    printf("| %6s | %15s | %20s | %20s | %10s |\n","No.","LoginId","Username","Password","Age");
    puts("=======================================================================================");
    int cnt = 1;
    user* u = tail;
    while( u){
        printf("| %6d | %15s | %20s | %20s | %10d |\n",cnt++, u->login_id,u->user_name,u->password,u->age);
        u = u->next;
    }
    puts("=======================================================================================");
}

void check_str( char* str){
    char *s;
    if ((s = strchr(str,'\n'))) *s = '\0';
    else{
        printf("Warning input is too long and it will be stripped!!!\n");
        __fpurge(stdin);
    }
}

int chk_id(char* id){
    char* s;
    s = id;
    for (id;*id;id++){
        if (*id == ' '){
            clearline();
            puts("\tNo spaces are allowed in loginId!!!");
            return -1;
        }
    }
    user *u;
    for (u = tail; u;u=u->next){
        if (!strcmp(s,u->login_id)){
            clearline();
            puts("\tPlease select other login Id. This one is already used :( ");
            return -1;
        }
    }
    return 0;
}
