#include<stdio.h>
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
    struct user* prev;
} user;

user* head = NULL;
user* tail = NULL;

void clear_stdin(void);
user* add_record();
void delete_record();
void modify_record();
void list_records();
void check_str(char*);


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
        scanf("%d",&choice);
        while ( choice < 1 || choice >5){
            clearline();
            clear_stdin();
            printf("\tEnter a valid choice! ==> ")    ;
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
                delete_record();
                break;
            case 3:
                modify_record();
                break;
            case 4:
                list_records();
                sleep(10);
                break;
            case 5:
                printf("Good Bye,\n");
                exit(0);
                break;
        }
    }
    return 0;
}

user* add_record(){
    user* usr = (user *)malloc(sizeof(user));
    usr->prev = head;
    usr->next = NULL;
    printf("\tEnter User name : ");
    clear_stdin();
    check_str(fgets(usr->user_name,20,stdin));
    printf("\tEnter Login ID  : ");
    check_str(fgets(usr->login_id,15,stdin));
    printf("\tEnter password  : ");
    check_str(fgets(usr->password,20,stdin));
    printf("\tEnter age       : ");
    scanf("%d",&usr->age);
    while (usr->age == 0){
        clearline();
        printf("\tEnter valid age : ");
        scanf("%d",&usr->age);
    }
    return usr;
}


void delete_record(){}
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
    if (s = strchr(str,'\n')) *s = '\0';
    else{
        printf("Warning input is too long and it will be stripped!!!\n");
        clear_stdin();
    }
}

void clear_stdin(){
    char c;
    do c = getchar();
    while(c !=EOF && c !='\n');
}
