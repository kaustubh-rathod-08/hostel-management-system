#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main_exit;
//--------------------------------------------------------------------------------------------------------------------
void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void close();

// --------------------------------------------------------------------------------------------------------------------
struct date{
    int month,day,year;
};
struct {

    char name[120];
    int age;
    char city[120];
    char mail_id[60];
    int room_no;
    char father_name[60];
    long int father_phone_no;
    long int phone_no;
    char hostel_name[6];
    char hostel_id[10];
    struct date dob;
    int rent_paid;
    }
     add,upd,check,rem,sort;

//--------------------------------------------------------------------------------------------------------------------
int main()
{
  menu();
  return 0;
}

// -------------------------------------------------------------------------------------------------------------------
void menu()
{

    int choice;
    printf("---------------------------------------------------------------------------------------------");
    printf("\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1>> Enter new Student's data");
    printf("\n\t\t2>> Update information of existing account");
    printf("\n\t\t3>> Check the details of existing account");
    printf("\n\t\t4>> Removing existing account");
    printf("\n\t\t5>> View all students list");
    printf("\n\t\t6>> Exit");
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:close();
        break;
        default:menu();
    }
}
//------------------------------------------------------------------------------------------------------------------
void new_entry()
{
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.dat","a+");
    hostel_id:

    printf("\t\t\t ADD STUDENTS DATA ");
    printf("\nEnter your hostel_id:");
    scanf("%s",check.hostel_id);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, &add.rent_paid)!=EOF)
    {
        if (strcmp(check.hostel_id,add.hostel_id)==0)
            {printf("Students hostel_id already in use!");
             goto hostel_id;
        }
    }

    strcpy(add.hostel_id,check.hostel_id);
    printf("\n Enter the name:");
    scanf("%s",add.name);
    printf("\n Enter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\n Enter the age:");
    scanf("%d",&add.age);
    printf("\n Enter the city:");
    scanf("%s",add.city);
    printf("\n Enter the phone number:");
    scanf("%ld",&add.phone_no);
    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%ld",&add.father_phone_no);
    printf("\n --------------------------Hostel contains 10 rooms------------------------!!!!");
    printf("\n Enter the room no.:");
    scanf("%d",&add.room_no);
    printf("\n Total rent is:5000");
    printf("\n Amount of rent paid: ");
    scanf("%d" , &add.rent_paid);
    
        fprintf(ptr,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no,add.rent_paid);
        fclose(ptr);
    
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
        menu();
        
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    printf("---------------------------------------------------------------------------------------------");
    printf("\t\nHOSTEL_ID\tNAME\t\t\tCity\t\tRENT PAID\t\tROOM ALLOTED\n");
    printf("---------------------------------------------------------------------------------------------");

    while(fscanf(view,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, &add.rent_paid)!=EOF)       
       {
           printf("\n\t%s\t%s\t\t\t %s\t\t %d\t\t\t %d",add.hostel_id,add.name,add.city,add.rent_paid,add.room_no);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");
            
        }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
void see()
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    {   
        printf("\n\nEnter the hostel id to check details of the student:");
        scanf("%s",check.hostel_id);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, &add.rent_paid)!=EOF)        
       {
            if(strcmp(add.hostel_id,check.hostel_id)==0)
            {
                test=1;

                printf("\nhostel_id:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%ld \nE-Mail id:%s \nFather's name:%s \nFather's Phone No.:%ld \nRoom No:%d \nAdd.rent_paid :%d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.rent_paid);
            }
        }
    }
  

    fclose(ptr);
    
     if(test!=1)
        printf("\nRecord not found!!\a\a\a");
   
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            see();
        else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the hostel id of the student whose info you want to change:");
    scanf("%s",upd.hostel_id);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, &add.rent_paid)!=EOF)
    {
        if (strcmp(add.hostel_id,upd.hostel_id)==0)
        {   
            test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone): ");
            scanf("%d",&choice);

            if(choice==1)
                {
                printf("Enter the new room no.:");
                scanf("%d",&upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no,add.rent_paid);
                
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%ld",&upd.phone_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no,add.rent_paid);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no,add.rent_paid);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }

}

//------------------------------------------------------------------------------------------------------------------
void erase()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Hostel_id of student whose data you want to delete:");
    scanf("%s",rem.hostel_id);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, &add.rent_paid)!=EOF)
   {
        if(strcmp(add.hostel_id,rem.hostel_id)!=0)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %ld %s %s %ld %d %d\n",add.hostel_id, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no,add.rent_paid);

        else
            {
            test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
        printf("\nRecord not found!!\a\a\a");
    
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
void close()
{

    printf("\n\n\n\t\t-------------*******THANK YOU*******-------------\t\t\n\n\n");
}