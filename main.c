#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define Max_Size 100
static int iterator=0;
typedef struct patient
{
	char name[50];
	char gender[50];
	int age;
	int id;
	int count_id;
	char *slot;

}patient;

int main()
{

	printf("************************************************************");
	printf("************************************************************");
	printf("************************************************************");
	printf("************************************************************");
	printf("                                             Clinic Management System\n");
	printf("Auther : Ahmed Arabe Sayed\n");
	printf("Version :1.0\n");
	printf("Date : 26/12/2021\n");
	printf("************************************************************");
	printf("************************************************************");
	printf("************************************************************");
	printf("************************************************************\n");


	char mode;
	int pass;
	int check_pass=0;
	int fun;
	int temp;
	static int counter=0;
	patient arr[Max_Size];

	char *slot[5]=
	{
			{"2pm to 2:30pm"},
			{"2:30pm to 3pm"},
			{"3pm to 3:30pm"},
			{"4pm to 4:30pm"},
			{"4:30pm to 5pm"}
	};

	static char *valid_slot[5];
	for(temp=0;temp<5;temp++)
	{
		valid_slot[temp]=slot[temp];
	}

	y:;
	printf("Enter mode : user or admin\nfor admin enter A/a and for user enter B/b\n");
	scanf(" %c",&mode);
	if(mode =='A' || mode =='a') //Admin modde
	{
		printf("Hello Admin\nplease Enter password\n");
		scanf("%d",&pass);

		while(pass !=1234 && check_pass <3 )
		{
			if(pass!=1234 &&check_pass <2)
			{
				printf("please enter correct password\n");
				check_pass++;
				scanf("%d",&pass);
			}
			else
			{
				printf("Wrong password\n");
				return 0;
			}
		}
		if(pass==1234)
		{

			printf("Welcome Admin\n");
			x:;
			printf("what do you want\n1-Add new patient record\n");
			printf("2-Edit patient record\n3-Reserve a slot with the doctor\n");
			printf("4-Cancel reservation\n");
			printf("What do you want \n");
			scanf("%d",&fun);
		}

	}

	if(fun ==1 && (mode =='A' || mode =='a') )
	{

		printf("Enetr new record\n");
		printf("Enetr Name\n");
		scanf("%s",&arr[iterator].name);
		printf("Enetr Age\n");
		scanf("%d",&arr[iterator].age);
		printf("Enetr Gender\n");
		scanf("%s",&arr[iterator].gender);
		printf("Enetr ID\n");
		scanf("%d",&arr[iterator].id);

		temp=iterator-1;
		while(temp >=0)
		{
			if(arr[temp].id ==arr[iterator].id)
			{
				printf("this id is already exist\n");
				return 0;
			}
			temp--;
		}

		printf("*******************************************************\n");
		printf("Data of new record is \n");
		printf("*******************************************************\n");
		printf("name = %s\nage =%d\ngender =%s\nId =%d\n",arr[iterator].name,arr[iterator].age,arr[iterator].gender,arr[iterator].id);
		printf("*******************************************************\n");
		counter++;
		iterator++;
		printf("if you want another service in admin mode press 1 else press 0\n");
		int press;
		scanf("%d",&press);
		if(press==1)
		{
			goto x;
		}

		else if (press ==0)
		{
			goto y;
		}
	}


	else if(fun ==2 && (mode =='A' || mode =='a'))
	{
		int id;

		printf("you can edit your record by enter ID\n");
		printf("Enter your ID ");
		scanf("%d",&id);
		temp=counter;
		int flag=0;
		while(temp>=0)
		{
			if(id!=arr[temp].id)
			{
				temp--;
				flag=1;
			}
			else if(id==arr[temp].id)
			{
				flag=0;
				break;
			}

		}
		if(flag==0)
		{
			printf("Enter your name\n");
			scanf("%s",&arr[temp].name);
			printf("Enetr Age\n");
			scanf("%d",&arr[temp].age);
			printf("Enetr Gender\n");
			scanf("%s",&arr[temp].gender);


			printf("*******************************************************\n");
			printf("Data of new record is \n");
			printf("*******************************************************\n");
			printf("name = %s\nage =%d\ngender =%s\nId =%d\n",arr[temp].name,arr[temp].age,arr[temp].gender,arr[temp].id);
			printf("*******************************************************\n");

		}
		else if(flag==1)
		{
			printf("Invalid ID");
			return 0;
		}

		printf("if you want another service in admin mode press 1 else press 0\n");
		int press;
		scanf("%d",&press);
		if(press==1)
		{
			goto x;
		}
		else if (press ==0)
		{
			goto y;
		}
	}

	else if(fun==3 && (mode =='A' || mode =='a'))
	{
		static int slote;
		int i,id;
		printf("\nTo reserve a slot enter your id\n");
		scanf("%d",&id);
		temp=counter;
		int flag=0;
		while(temp>=0)
		{
			if(id!=arr[temp].id)
			{
				temp--;
				flag=1;
			}
			else if(id==arr[temp].id)
			{
				flag=0;
				break;
			}

		}
		if(flag==0)
		{

			printf("you can choose between :\n");
			for(i=0;i<sizeof(valid_slot)/sizeof(valid_slot[0]);i++)
			{
				if(valid_slot[i]!=NULL)
					printf("%d- %s\n",i+1,valid_slot[i]);
			}
			printf("what do you want\n");
			scanf("%d",&slote);
			if(valid_slot[slote-1]!=NULL)
			{
				printf("you chose : %s\n ",valid_slot[slote-1]);
				arr[iterator-1].slot=valid_slot[slote-1];
				valid_slot[slote-1]=NULL;

			}
			else
			{
				printf("Invalid slot\n");
				return 0;
			}
		}
		else if(flag!=0)
		{
			printf("Invalid ID\n");
		}
		printf("if you want another service in admin mode press 1 else press 0\n");
		int press;
		scanf("%d",&press);
		if(press==1)
		{
			goto x;
		}

		else if (press ==0)
		{
			goto y;
		}
	}


	else if(fun ==4 && (mode =='A' || mode =='a'))
	{
		int id,temp=0,flag=0,i;
		printf("you can cancel your reservation\n");
		printf("Enter ID\n");
		scanf("%d",&id);
		temp=iterator-1;
		while(temp>=0)
		{
			if(id==arr[temp].id)
			{
				flag=1;

				break;
			}
			flag=0;
			temp--;
		}
		if(flag==1)
		{

			printf("you are canceled your reservation\n");

			for(i=0;i<sizeof(valid_slot)/sizeof(valid_slot[0]);i++)
			{
				if(valid_slot[i]!=NULL)
				{
					//  printf("%d- %s\n",i+1,valid_slot[i]);

				}
				else if(valid_slot[i]==NULL)
				{
					valid_slot[i]=arr[temp].slot ;
					//  printf("%d- %s\n",i+1,valid_slot[i]);

				}
			}
		}
		else if(flag==0)
		{
			printf("Invalid id\n");
		}
		printf("if you want another service in admin mode press 1 else press 0\n");
		int press;
		scanf("%d",&press);
		if(press==1)
		{
			goto x;
		}

		else if (press ==0)
		{
			goto y;
		}

	}


	if((mode =='B' || mode =='b'))
	{
		int temp,id,flag;
		H:;
		printf("Welcome user\n");
		printf("What do you want\n");
		printf("1-View patient record\n2- View today's reservations\n");
		scanf("%d",&temp);

		if(temp==1 )
		{
			printf("Enetr your ID\n");
			scanf("%d",&id);
			temp=iterator;
			while(temp>=0)
			{
				if(id==arr[temp].id)
				{
					flag=0;
					break;
				}
				else if(id!=arr[temp].id)
				{
					flag=1;
					temp--;
				}
			}
			if(flag==0)
			{
				printf("\nname : %s\n",arr[temp].name);
				printf("age : %d\n",arr[temp].age);
				printf("gender : %s\n",arr[temp].gender);
				printf("ID : %d\n",arr[temp].id);
			}
			else if(flag==1)
			{
				printf("Invalid ID\n ");
				return 0;
			}

			printf("if you want another service in user mode press 1 else press 0\n");
			int press;
			scanf("%d",&press);
			if(press==1)
			{
				goto H;
			}

			else if (press ==0)
			{
				goto y;
			}


		}
		else if(temp==2)
		{

			printf("Enter your ID\n");
			scanf("%d",&id);
			temp=iterator;
			flag=0;
			while(temp>=0)
			{
				if(id==arr[temp].id)
				{
					flag=0;
					break;
				}
				else if(id!=arr[temp].id)
				{
					flag=1;
					temp--;
				}
			}

			if(flag==0)
			{

				printf("slot : %s\n",arr[temp].slot);
			}
			else if(flag==1)
			{
				printf("Invalid ID\n ");
				return 0;
			}

			printf("if you want another service in user mode press 1 else press 0\n");
			int press;
			scanf("%d",&press);
			if(press==1)
			{
				goto H;
			}

			else if (press ==0)
			{
				goto y;
			}

		}


	}

	return 0;
}

/*
patient Add_New_Patient_Record(char name[],int age,char gender[],int id)
{


    patient arr[iterator];
    arr[iterator].age=age;
    arr[iterator].id=id;
    strcpy(arr[iterator].gender,gender);
    strcpy(arr[iterator].name,name);
  //  iterator++;
  //  p1.age=age;
  //  strcpy(p1.name,name);
  //  strcpy(p1.gender,gender);
   // p1.id=id;

    return arr[iterator];
}*/




