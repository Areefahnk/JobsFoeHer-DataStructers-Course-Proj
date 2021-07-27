#include<stdio.h>
#include<string.h>
#define max 5
#define Max 5
int ele,ch,ra=0;
struct profile{
	char name[30];
	int age;
	char mail[100]; 
	char q[50];      
}p;
/**** For checking whether the mail id enterred by the applicant exist or not ****/
void mail()
{
	FILE *fp;
	char str[256];
	int f=-991;
	fp = fopen("C:\\Users\\Office\\Desktop\\test.txt", "r");
	//printf("Enter a mail id\n");
	scanf("%s",p.mail);
	while(!feof(fp) && f)
	{
	 fscanf(fp, "%s\n", str);
	 if(strcmp(str,p.mail)==0)
	 {
	  puts("already exists");
	  printf("Use other mail\n");
	  mail();     /*To allow the applicant to register with other mail ID */
	  f=0;
	   }
	}
	fclose(fp);
	if(f) /** If the mail Id enterred donot exists... it will be stored in file for reference **/
	{	
		fp = fopen("C:\\Users\\Office\\Desktop\\test.txt","a");
		fprintf(fp,"%s\n",p.mail);
	}
	fclose(fp);
} 			/**** ---- PROFILE CREATION---- *****/
void profile()
{
	printf("Enter your Name\n");
	scanf("%s",p.name);
	printf("Enter the mail id\n");
	mail();
	printf("Enter your age\n");
	scanf("%d",&p.age);
	printf("Enter your qualifications\n");
	scanf("%s",p.q);
}               
              /** ----------- Registration Process ---------- **/
void registration(int n)
{	
	int c;
	FILE *fp1;
	profile();
	fp1=fopen("C:/Users/Office/Desktop/areefa.txt","a");
	fprintf(fp1,"%s %s %d %s %d\n",p.name,p.mail,p.age,p.q,n);
         fclose(fp1);
}
int top=-1,n,ch;
char s1[Max];
void insert(int ele)
{
	if(top==Max-1)
	printf("Stack overflow\n");
	else{
		s1[++top]=ele;
	}
}
void delete()
{
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("Element deleted is %c\n",s1[top]);
		s1[top--];
	}
}
void display2()
{
	int i=0;
	if(top==-1)
	{
		printf("Underflow\n");
	}
	else{
		for(i=0;i<=top;i++)
		{
			printf("%c ",s1[i]);
		}
		int j;
		printf("Final preferences are\n");
		FILE *fp5;
		fp5=fopen("C:\\Users\\Office\\Desktop\\we.txt","w");
		fprintf(fp5,"%s",s1);
		for(j=0;j<i;j++)
		{
			if(j==(i-1))
			{
				printf("%c",s1[j]);
			}
			else{
			printf("%c->",s1[j]);
		         }
		}
		fclose(fp5);
		givejob();
	}
	
}
void del()
{
	s1[top--];
}
void givejob()
{
	del();
	del();
	del();
	Permit();
}
void preferrences() /* Placing job preferrences options */
{
	do{
	printf("\nAvailable jobs are:\n");
	printf("A.IT Technician\n");
	printf("B.Marketting\n");
	printf("C.Management\n");
	printf("D.Content Writing\n");
	printf("E.Event manager and hosting\n");
		printf("\n\n1.Opt your selection according to preferrences order\n");
		printf("2.To delete recently opted one\n");
		printf("3.Display all the preferrences opted\n");
		printf("4.Press 4 to confirm preferrences and halt!!!\n");
		printf("enter ur choice\n");
		scanf("%d",&ch);
	switch(ch)
         {
         	case 1:
		printf("Enter your preference\n");
		scanf(" %c",&ele);
		insert(ele);
         	       break;
         	case 2:delete();
         	       break;
         	case 3:display2();
         	       break;
         	case 4:printf("You ended the opting of preferences\n");
         	printf("Selected preferrences are:\n");
         	display2();
         	exit(0);
         	break;
         	default:exit(0);
	}
        }while(1);
}
		/*** Whole Jobseek fuction - Main function ***/
void Jobseek()
{
	int ch1,enter;
	char psswd1[10];
	char str1[10];
		printf("\n1.To register for jobs\n");
		printf("2.Opt the job preferences (Terms-only if you got the OTP)\n");
		printf("Enter the choice\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
				/* For demo purpose we have considered only 2 registrations */
				printf("Registrations are openned\n");
					int n=1;
				do{
				   registration(n);
				   n++;
				}while(n!=3);
				printf("Registrations are closed (Applicants exceeded)!\n");
				printf("Do wait till the release of new jobs\n");
				Permit();
			break;
			case 2:	/** To not allow job seekers who didn't recieved otp and preferrences permission **/
			         printf("Enter psswd of jobseek\n");
			         scanf("%s",&psswd1);
			         FILE *f1;int c1;
			         f1=fopen("C:\\Users\\Office\\Desktop\\pass2.txt","r");
			         int j=0,co=0;
			         while(((c1=fgetc(f1))!=EOF) && (j<5))
			         {
			         	str1[j]=c1;
			         	if(psswd1[j]==str1[j])
			         	{
			         		co++;
					}
					j++;
				}
				fclose(f1);
				if(co==5)
				{
					printf("Welcome\n");
					preferrences();
				}
				else
				{
					printf("Sorry wrong OTP...\n");
					printf("Enter the correct OTP which you recieved\n");
					printf("Press 1 to re enter the otp\n");
					printf("Press 2 to exit\n");
					scanf("%d",&enter);
					if(enter==1)
					{
						printf("Enter psswd of jobseek\n");
			         		scanf("%s",&psswd1);
						f1=fopen("C:\\Users\\Office\\Desktop\\pass2.txt","r");
						int j=0,co=0;
						while(((c1=fgetc(f1))!=EOF) && (j<5))
						{
						         str1[j]=c1;
						         if(psswd1[j]==str1[j])
						         {
						         	co++;
							}
							j++;
						}
						if(co==5)
						{
							printf("Welcome\n");
							preferrences();
						}
						else{
							printf("Await for OTP\n");
							Permit();
						}		
					}
					else if(enter==2){
					printf("If you didn't recieve OTP! Await.... till you get");
					Permit();
				         }
				}
			break;
			default: Permit();
		}

}     
struct dll
{
	char Name[30];
	char mail[30];
	char q[50];
	int regn;
	int age;
	struct dll *next;
	struct dll *prev;
}s;      
typedef struct dll node;
node *start=NULL;
node *temp,*newnode;
node *prev1; 
node *getnode(char *Name, char *mail,int *age,char *q,int *regn)
{
	newnode=(node *)malloc(sizeof(node));
         strcpy(newnode->Name,Name);
	strcpy(newnode->mail,mail);
	newnode->age=age;
	strcpy(newnode->q,q);
	newnode->regn=regn;
	newnode->next=NULL;
	newnode->prev=NULL;
}  
void read()
{
	FILE *fp;
	fp=fopen("C:\\Users\\Office\\Desktop\\areefa.txt","r");
	while(!feof(fp)){
         	fscanf(fp,"%s %s %d %s %d\n",s.Name,s.mail,&s.age,s.q,&s.regn);
         	newnode = getnode(s.Name, s.mail,s.age,s.q,s.regn);
         	if(start==NULL)
			start = newnode;
		else
		{
			temp = start;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = newnode;
			newnode->prev = temp;
		}
         }
         fclose(fp);
}
void Viewprofile()
{
	read();
	temp=start;
	while(temp->next!=NULL)
	{
		printf("\nName = %s\n",temp->Name);
		printf("eMail = %s\n",temp->mail);
		printf("Age = %d\n",temp->age);
		printf("Qualification = %s\n",temp->q);
		printf("Registration no. = %d\n---------------\n",temp->regn);
		temp=temp->next;
	}
	printf("Name = %s\n",temp->Name);
	printf("eMail = %s\n",temp->mail);
	printf("Age = %d\n",temp->age);
         printf("Qualification = %s\n",temp->q);
	printf("Registration no. = %d\n--------------",temp->regn);
}
void Message()
{
	int otp;
	if(ra==0)
	{
	printf("-----------------------------------------------------\n");
	printf("\n\n-------- Message - INBOX-------\n");
	printf("ID-Jobsforher\n");
	printf("Congratulations you have been shortlisted\n");
	FILE *fp3;
	fp3=fopen("C:\\Users\\Office\\Desktop\\pass2.txt","r");
	while(!feof(fp3)){
         	fscanf(fp3,"%d",&otp);
         }
         printf("%d is the OTP and donot disclose with anyone\n",otp);
         }
         int n;
	printf("Enter 1 to proceed to put job preferences\n");
	scanf("%d",&n);
	if(n==1)
	{
		Jobseek();
	}
	else{
		ra=1;
		Message();
	}
	
}
void Admin()      /*Admin----*/
{	int ch2;
	int regno;
	int otp;
	int reg1;
	do{
	printf("\n1.View profile\n");
	printf("2.Send OTP to job seek for preferences\n");
	printf("3.See preferrences by applicant to which otp sent recently\n");
	printf("Enter your choice\n");
	scanf("%d",&ch2);
	switch(ch2)
	{
		case 1:Viewprofile();
		break;
		case 2:	
			printf("\n enter reg no");
			scanf("%d",&regno);
			printf("Send the OTP to job applicant %d\n",regno);
			scanf("%d",&otp);
			FILE *fp2;
			fp2=fopen("C:\\Users\\Office\\Desktop\\pass2.txt","w");
			fprintf(fp2,"%d",otp);
			fclose(fp2);
			printf("OTP sent...!!!");
			Message();
		break;
		case 3:
		printf("Enter the reg no., whose job preferences you want to view\n");
		printf("TERMS AND CONDITIONS: To which you have sent otp only\n");
		scanf("%d",&reg1);
		job(reg1);
		exit (0);
		break;
		default: exit(0);
	}
	}while(1);
}
struct queue
{
	char data3;
	struct queue *next3;
};
FILE *fp6;
char q[10],z;
int i=0,j=0;

typedef struct queue node3;
node3 *front=NULL,*rear=NULL;
node3 *newnode3,*temp3,*prev3;
int n3,ch3;
void push(char ele)
{
	newnode3=(node3*)malloc(sizeof(node3));
	newnode3->data3=ele;
	if(front==NULL)
	{
		newnode3->next3=NULL;
		rear=newnode3;
		front=newnode3;
	}
	else
	{
		newnode3->next3=NULL;
		rear->next3=newnode3;
		rear=newnode3;
	}
}
void pop(int reg1)
{
	char job;
	if(rear==NULL)
	 printf("queue is empty\n");
	else
	{
		printf("Allot job\n");
		scanf(" %c",&job);
		printf("%c job is allotted to %d\n",job,reg1);
		Admin();
	}
}
void display()
{
	if(rear==NULL)
	 printf("\n queue is empty");
	else
	{
		temp3=front;
		while(temp3->next3!=NULL)
		{
			printf("%c",temp3->data3);
			temp3=temp3->next3;
		}
		printf("%c\n",temp3->data3);
	}
	//int k=rear-1;
	//printf("\nJob %c is alloted!!\n",q[k]);	
}
void job(int reg1)
{
	do{
		printf("\n 1.See the job preferrences");
		printf("\n 2.pop and allot jobs\n");
		printf("3.exit\n");
		printf("\n Enter ur choice");
		scanf("%d",&ch3);
		switch(ch3)
		{
			case 1:
				fp6=fopen("C:\\Users\\Office\\Desktop\\we.txt","r");
				while(((z=fgetc(fp6))!=EOF) )
				{
					if(isalpha(z)){
					q[i]=z;
					printf("%c ",q[i]);
					i++;	}
				}
				printf("are Job preferrences\n");
				if(i>3){
				for(j=0;j<3;j++)
				{
					printf("%c",q[j]);
					if(j==0)
					{
						printf("%c already alloted... So don't allot\n",q[j]);
					}
					break;
				}
				printf("\n");
				for(j=3;j<i;j++)
				printf("%c ",q[j]);
				}
				else if(i<3){
					for(j=0;j<i;j++)
					printf("%c ",q[j]);
				}
				for(j=i-1;j>=0;j--)
				{
					push(q[j]);
				}
			break;
			case 2:pop(reg1);
			break;
			case 3:exit(0);
			default: exit(0);
		}
	}while(1);
}
void Permit()
{
	int ch;
	char psswd[8];
	char str[5];
	int count1=1;
	do{
		printf("Let us know who you are\n");
		printf("1.Job Seeker\n");
		printf("2. Admin\n");
	
		printf("Enter the selection\n");
		scanf("%d",&ch);
		switch(ch)  //For permitting to respective roles
		{
			case 1:Jobseek();
				count1=0;
			break;
			case 2:printf("Enter the admin password!\n");
			 //To allow only admin
			       scanf("%s",&psswd);
			       FILE *f;int c;
			       f=fopen("D://password.txt","r");
			       int i=0,count=0;
			       	while(((c=fgetc(f))!=EOF) && (i<5))
			       	{
			       	     str[i]=c;
			       	 	if(psswd[i]==str[i])
			       	 	{
			       	 		count++;
					}
			               i++;		
			         }
				if(count==5)
				{
				    printf("Welcome Admin\n");
				    Admin();
				}	
				else
				printf("Sorry you donot have permission into to this\n");
				count1=0;
				fclose(f);	
			break;
		default: return 0;
		}
	}while(count1);
}
int main()
{
	Permit();
}
