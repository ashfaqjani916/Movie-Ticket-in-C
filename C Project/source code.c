#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bookticket();
void viewticket();
void newlog();
void oldlog();
void accountcreated();
void hall();

struct user {
    char name[50];
    char email[50];
    char username[50];
    char password[50];
};

int cinesquare[6][7],tm;
int cineprime[6][7];
char tmp[50],k[50];

void hall()
{ 
    FILE *fp,*fpp;
    fp = fopen("theatre1.txt","r");
    fpp = fopen("theatre2.txt","r");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            fscanf(fp, "%d ", &cineprime[i][j]);
            fscanf(fpp, "%d ", &cinesquare[i][j]);
        }
       
    }

    fclose(fp);
    fclose(fpp);
}

int main()
{
   
    for(int i=1;i<7;i++){
        for(int j=1;j<8;j++){
            cineprime[i][j]=0;
            cinesquare[i][j]=0;
        }
    }
    int inp;
    start:
    printf("--------------------WELCOME TO MOVIE TICKET BOOKING--------------------\n");
    printf("Please select the option:\n ");
    printf("1. For new user\n");
    printf(" 2. For existing user\n");
    scanf("%d",&inp);
    switch(inp){
        case 1:
        newlog();
        break;
        case 2:
        oldlog();
        break;
        default:
        {
            printf("INVALID INPUT!!!!!\n Please enter again.....\n\n\n\n");
            for(int i=0;i<2000000;i++){
                i++;i--;
            }
            goto start;

        }

    }
}

void newlog()
{
    struct user u1;
    printf("Please enter your name: ");
    scanf("%s",u1.name);
    printf("\nPlease enter your email ID: ");
    scanf("%s",u1.email);
    printf("\nPlease enter user name: ");
    scanf("%s",u1.username);
    printf("\nPlease input the password: ");
    scanf("%s",u1.password);
     
    FILE *fptr;
     char tmp[50];
     strcpy(tmp,u1.username);strcat(tmp,".txt");
     fptr = fopen(tmp,"w");
     fprintf(fptr,"%s",u1.username);
     fprintf(fptr,"%s\n",u1.password);
     fclose(fptr);
     accountcreated();

}
void accountcreated(void)  
{  
    int i;  
    
    char ch;  
    system("cls");  
    printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");  
    for (i = 0; i < 200000000; i++) {  
        i++;  
        i--;  
    }  
  

    printf("\nACCOUNT CREATED SUCCESSFULLY....");  
    
  
    oldlog();  
}  

void oldlog(){

     int opt; char car[50];
     FILE *file;
     char nam[50];
     char pass[50];
     printf("\n\n\n---------------------WELCOME TO LOGIN PAGE--------------------\n");
     printf("User Name:\n");
     scanf("%s",nam);
     strcpy(k,nam);
     printf("Password:\n");
     scanf("%s",pass);
     strcpy(tmp,nam);strcat(tmp,".txt");
     file=fopen(tmp,"r");
     fscanf(file,"%s",car);
     strcat(nam,pass);
     fclose(file);

        if (strcmp(nam,car)==0) {
            printf("--------------------------LOGIN SUCCESSFUL----------------------");
            printf("\nPlease Input an option......");
            printf("\n1. To Buy Tickets");
            printf("\n2. To View Tickets");
            scanf("%d",&opt);
            switch(opt){
                case 1:
                bookticket();
                break;
                case 2:
                viewticket();
                break;
                default:
                printf("\nInvalid INPUT");
            }
        }
        else
        {
            printf("\nWrong password!!!!");
        }
        
    }
    
void viewticket()
{ int val,i=0;
FILE *fp;
strcat(k,"1.txt");
fp = fopen(k,"r");
  if (fp == NULL)
    {
        printf("\n NO DATA FOUND!!!!!!\n");
        exit(0);
    }
    else{
        printf("The Seats you have booked in the order (row,column) are:");
    while (fscanf(fp, "%d", &val) != EOF) {
        if(i%2==0)
        printf("\n");
        printf("%d,",val);
        i++;
    }
    }
    fclose(fp);
}


void bookticket()
{
    int i,j,r,c,amt;
    hall();
    printf("\nThe Movie available at the time is Bahubali!!!!");
    printf("Please select the theatre.........\n 1.Cine Prime\n2.Cine Square");
    scanf("%d",&tm);
    strcat(k,"1.txt");
    FILE *film;
    film= fopen(k,"w");
    switch(tm){
        case 1:
        {
            printf("\nThank You for selecting Cine Prime");
            printf("\nThe available seats are:(1-OCCUPIED    0-EMPTY)\n");
            for(int i=1;i<7;i++){
            for(int j=1;j<8;j++){
                printf("%d ",cineprime[i][j]);
            }
            printf("\n");
            }
            printf("\nPlease enter the number of seats.......");
            tm=0;
            scanf("%d",&tm);
            amt=tm*150;
            int arr[tm*2];
            printf("\nplease enter the seats in the format row,column:  ");j=0;
            for(i=0;i<tm;i++){
                
                scanf("%d,%d",&r,&c);
                if(cineprime[r][c]==0){
                arr[j]=r;
                j++;
                arr[j]=c;
                j++;
                cineprime[r][c]=1;
                r=c=0;
                }
                else{
                    printf("\nThe seat is already booked!!!!!\n PLEASE ENTER AGAIN.......");
                    i--;
                }
            }
            for(i=0;i<tm*2;i++){
                fprintf(film,"%d ",arr[i]);
            }
            
            break;
        }
        case 2:
        {
             printf("\nThank You for selecting Cine Square");
            printf("\nThe available seats are:(1-OCCUPIED    0-EMPTY)\n");
            for(int i=1;i<7;i++){
            for(int j=1;j<8;j++){
                printf("%d ",cinesquare[i][j]);
            }
            printf("\n");
            }
            printf("\nPlease enter the number of seats.......");
            tm=0;
            scanf("%d",&tm);
            amt=tm*150;
            int arr[tm*2];
            printf("\nplease enter the seats in the format row,column:  ");j=0;
            for(i=0;i<tm;i++){
                
                scanf("%d,%d",&r,&c);
                if(cinesquare[r][c]==0){
                arr[j]=r;
                j++;
                arr[j]=c;
                j++;
                cinesquare[r][c]=1;
                r=c=0;
                }
                else{
                    printf("The seat is already booked!!!!!\n PLEASE ENTER AGAIN.......");
                    i--;
                }
            }
            for(i=0;i<tm*2;i++){
                fprintf(film,"%d ",arr[i]);
            }
            break;
        }
        default:
        printf("\nINVALID ENTRY!!!!!!!!!!!\n");
    }
    
    FILE *fp ,*fpp;
    fp = fopen("theatre1.txt","w");
    fpp = fopen("theatre2.txt","w");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(fp, "%d ", cineprime[i][j]);
            fprintf(fpp, "%d ", cinesquare[i][j]);
        }
        fprintf(fp, "\n");
        fprintf(fpp, "\n");
    }

    fclose(fp);
    fclose(fpp);
    fclose(film);
}
