#include <stdio.h>
#include <stdlib.h>
void newAcc();
void viewList();
void edit();
void transact();
void deposit();
void withdraw();
void erase();
int addnum();
struct bank{
    int accNum, bday, bmonth, byear, age;
    unsigned int password;
    char name[20], address[100], accType[20];
    long long int citNum ,phoneNum;
    float balance;
}client[100];

int clear_input_buffer(){
    int ch;
    while(((ch=getchar())!=EOF) && (ch != '\n'));
return ch;}

int main(){
int s;
    printf("Welcome to Banque Shoubra's menu.\n\nTake a choise :)\n\n1-New account.\n2-View list.\n3-Edit.\n4-transact.\n5-Erase.\n6-Exit.\n");
        scanf("%d",&s);
    switch(s){
        case 1: newAcc();
                break;
        case 2: viewList();
                break;
        case 3: edit();;
                break;
        case 4: transact();
                break;
        case 5: erase();
                break;
        case 6: exit(0);
        default : printf("Enter 1-6 only.\n");
    }
    printf("\nWe hope to be in your high regards :)\n");
    return 0;
}
// Creating a new account.
void newAcc(){
system("cls");
int n;
FILE *fptr;
    n=addnum();
fptr=fopen("Clients.bin","ab+");
        client[n-1].accNum=n;
    printf("We are happy because you will be one of us :)\nYour account number is %d\n\n",n);
    printf("Enter your name:");
        clear_input_buffer();
        gets(client[n-1].name);
    printf("Enter your date of birth.\nDay:");
        scanf("%d",&client[n-1].bday);
    printf("Month:");
        scanf("%d",&client[n-1].bmonth);
    printf("Year:");
        scanf("%d",&client[n-1].byear);
    printf("Enter your citizenship number:");
        scanf("%lli",&client[n-1].citNum);
        clear_input_buffer();
    printf("Enter your age ( In years ):");
        scanf("%d",&client[n-1].age);
    printf("Enter your address:");
        clear_input_buffer();
        gets(client[n-1].address);
    printf("Enter your phone number:+201");
        scanf("%lli",&client[n-1].phoneNum);
    printf("Enter the type you want for your account:");
        clear_input_buffer();
        gets(client[n-1].accType);
    printf("Enter the cash you want deposit in your account ( EGP ):");
        scanf("%f",&client[n-1].balance);
    printf("Enter a password for your account:");
        scanf("%d",&client[n-1].password);
    printf("\n%s, Your account has been created.\n",client[n-1].name);
fwrite(&client[n-1], sizeof(struct bank), 1, fptr);
fclose(fptr);
}
// View the banking information of a customer.
void viewList(){
system("cls");
int n;
unsigned int password;
FILE *fptr;
fptr=fopen("Clients.bin","rb");
fread(client, sizeof(client), 1, fptr);
fclose(fptr);
    printf("Please, Enter your account number:");
        scanf("%d",&n);
    printf("Enter your password:");
        scanf("%d",&password);
system("cls");
    if(password==client[n-1].password){
        printf("Welcome %s.\nYour citizenship number is %lli\nYour date of birth is %d/%d/%d\nYou are %d years old.\nYour address is %s.\nYour phone number is +201%lli\nYour account tpye is %s.\nYour balance equals %.2f LE\n",client[n-1].name ,client[n-1].citNum ,client[n-1].bday ,client[n-1].bmonth ,client[n-1].byear ,client[n-1].age ,client[n-1].address ,client[n-1].phoneNum ,client[n-1].accType ,client[n-1].balance);
    }else{
        printf("Sorry, The password that you've entered is incorrect.\n");
        exit(2);
    }
}
// Editing the address and phone number for a particular customer.
void edit(){
system("cls");
int n;
unsigned int password;
FILE *fptr;
fptr=fopen("Clients.bin","rb");
fread(client, sizeof(client), 1, fptr);
fclose(fptr);
    printf("Please, Enter your account number:");
        scanf("%d",&n);
    printf("Enter your password:");
        scanf("%d",&password);
    if(password==client[n-1].password){
            printf("\nWelcome %s, Enter your new adress:",client[n-1].name);
                clear_input_buffer();
                gets(client[n-1].address);
            printf("Enter your new phone number:+201");
                scanf("%lli",&client[n-1].phoneNum);
    }else{
        printf("\nSorry, The password that you've entered is incorrect.\n");
        exit(3);
    }
fptr=fopen("Clients.bin","wb");
fwrite(client, sizeof(client), 1, fptr);
fclose(fptr);
}
//Doing a transact on customer account.
void transact(){
system("cls");
int n, s;
float money;
    printf("Please, Switch what do you want to do:\n1-Deposit\n2-Withdraw\n");
        scanf("%d",&s);
system("cls");
        switch(s){
        case 1: deposit();
                break;
        case 2: withdraw();
                break;
        default : printf("Enter 1-2 only.\n");
}
}
//Deleting a customer account.
void erase(){
system("cls");
int n, i;
unsigned int password;
FILE *fptr;
fptr=fopen("Clients.bin","rb");
fread(client, sizeof(client), 1, fptr);
fclose(fptr);
    printf("We hope that you are sure to make a decision like that :'(\nPlease, Enter your account number to erase it:");
        scanf("%d",&n);
    printf("Enter your password:");
        scanf("%d",&password);
    if(password==client[n-1].password){
        printf("\nWe are proud of dealing with you %s and we hope all the best for you :)\n",client[n-1].name);
    client[n-1].accNum=0;
    client[n-1].citNum=0;
    client[n-1].bday=0;
    client[n-1].bmonth=0;
    client[n-1].byear=0;
    client[n-1].age=0;
    client[n-1].phoneNum=0;
    client[n-1].balance=0;
     }else{
        printf("\nSorry, The password that you've entered is incorrect.\n");
        exit(4);
    }
fptr=fopen("Clients.bin","wb");
fwrite(client, sizeof(client), 1, fptr);
fclose(fptr);
}
void deposit(){
int n;
float money;
unsigned int password;
FILE *fptr;
fptr=fopen("Clients.bin","rb");
fread(client, sizeof(client), 1, fptr);
fclose(fptr);
    printf("Please, Enter your account number:");
        scanf("%d",&n);
    printf("Enter your password:");
        scanf("%d",&password);
    if(password==client[n-1].password){
    printf("How much do you want to deposit ( EGP ):");
        scanf("%f",&money);
            client[n-1].balance+=money;
    printf("\nNow, Your balance became %.2f LE.\n",client[n-1].balance);
    }else{
    printf("\nSorry, The password that you've entered is incorrect.\n");
    exit(4);
    }
fptr=fopen("Clients.bin","wb");
fwrite(client, sizeof(client), 1, fptr);
fclose(fptr);
}
void withdraw(){
int n;
float money;
unsigned int password;
FILE *fptr;
fptr=fopen("Clients.bin","rb");
fread(client, sizeof(client), 1, fptr);
fclose(fptr);
    printf("Please, Enter your account number:");
        scanf("%d",&n);
    printf("Enter your password:");
        scanf("%d",&password);
    if(password==client[n-1].password){
    printf("How much do you want to withdraw ( EGP ):");
        scanf("%f",&money);
    if(money>client[n-1].balance){
    printf("\nSorry, Your balance is not enough.\n");
    exit(1);
    }
            client[n-1].balance-=money;
    printf("\nNow, Your balance became %.2f LE.\n",client[n-1].balance);
    }else{
        printf("\nSorry, The password that you've entered is incorrect.\n");
    exit(4);
    }
fptr=fopen("Clients.bin","wb");
fwrite(client, sizeof(client), 1, fptr);
fclose(fptr);
}
int addnum(){
FILE *fnr;
FILE *fnw;
int n;
fnr = fopen("Accounts_Numbers.txt","r");
        fscanf(fnr,"%d", &n);
fclose(fnr);
    n++;
fnw = fopen("Accounts_Numbers.txt","w");
    fprintf(fnw,"%d",n);
fclose(fnw);
return n;
}