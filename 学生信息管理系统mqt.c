/*
 *
 *
 *
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct record
{
char name[20];
char phone[12]; 
char adress[50]; 
char postcode[8];
char e_mail[20]; 
}student[100]; 
int num; 
int menu_select()
{
char s[80];
int a;
system("cls");
printf("\t\t***********��ӭ����ѧ����Ϣ����ϵͳ********\n\n");
printf("\t\t\t0. �����¼\n");
printf("\t\t\t1. ��ʾ��¼\n");
printf("\t\t\t2. ����������\n");
printf("\t\t\t3. ���绰�������\n");
printf("\t\t\t4. �����¼ \n");
printf("\t\t\t5. ����������\n");
printf("\t\t\t6. ɾ����¼\n");
printf("\t\t\t7. Quit\n");
printf("\t\t***********************************************\n\n");
do{
printf("Enter you choice(0~7):");
scanf("%s",s);
a=atoi(s);
}
while (a<0 || a>7);
return a;
}
int adduser()
{
printf("\t\t\t**************** �������û���Ϣ ****************\n");
printf("\t\t\t��������:\n");
scanf("%s",student[num].name);
printf("\t\t\t����绰����:\n");
scanf("%s",student[num].phone);
printf("\t\t\t����༶:\n");
scanf("%s",student[num].adress);
printf("\t\t\t����ѧ��:\n");
scanf("%s",student[num].postcode);
printf("\t\t\t�����������:\n");
scanf("%s",student[num].e_mail);
num++;
printf("\t\t\t�Ƿ�������?(Y/N):\n");
if(getch()=='y' || getch()=='Y')
adduser();
return(0);
}
void list()
{
int i;
system("cls");
if(num!=0)
{
printf("\t\t\t*************** ����ΪͨѶ¼������Ϣ************\n");
for (i=0;i<num;i++)
{
printf("\t\t\t����:%s\n",student[i].name);
printf("\t\t\t�绰:%s\n",student[i].phone);
printf("\t\t\t�༶:%s\n",student[i].adress);
printf("\t\t\tѧ��:%s\n",student[i].postcode);
printf("\t\t\t��������:%s\n",student[i].e_mail);
if(i+1<num)
{
system("pause");
}
}
printf("\t\t\t************************************************\n");
}
else
printf("\t\t\tѧ����Ϣ����ϵͳ�����κμ�¼\n");
printf("\t\t\t��������������˵�:\n");
getch(); 
return;
}
int searchbyname()
{
int mark=0;
int i;
printf("\t\t\t***************** ���������� *******************\n");
char name[20];
printf("\t\t\t����������:\n");
scanf("%s",name);
for(i=0;i<num;i++)
{
if (strcmp(student[i].name,name)==0)
{
printf("\t\t\t************* �����������ҵ��û���Ϣ ***********\n");
printf("\t\t\t����: %s",student[i].name);
printf("\t\t\t�绰: %s",student[i].phone);
printf("\t\t\t�༶: %s",student[i].adress);
printf("\t\t\t��������:%s",student[i].e_mail);
printf("\t\t\t************************************************\n");
mark++;
if((i+1)<num)
{
printf("\t\t\t�Ƿ����������ͬ���ֵ��û���Ϣ:(y/n)\n");
if(getch()=='y' || getch()=='Y')
{
continue;
}
else
return(0);
}
else
{
printf("\t\t\t��������������˵�");
getch();
return(0);
}
}
}
if(mark == 0)
{
printf("\t\t\tû����ͬ�������û���¼\n");
printf("\t\t\t��������������˵�\n");
getch();
return(0);
}
return 0;
}
int searchbyphone()
{
int mark=0;
int i;
printf("\t\t\t****************** ���绰���� ******************\n");
char phone[10];
printf("\t\t\t������绰����:\n");
scanf("%s",phone);
for(i=0;i<num;i++)
{
if (strcmp(student[i].phone,phone)==0)
{
printf("\t\t\t************** �����������ҵ��û���Ϣ **********\n");
printf("\t\t\t����: %s",student[i].name);
printf("\t\t\t�绰: %s",student[i].phone);
printf("\t\t\t�༶: %s",student[i].adress);
printf("\t\t\t��������:%s",student[i].e_mail);
printf("\t\t\t************************************************\n");
printf("\t\t\t��������������˵�\n");
mark++;
getch();
return(0);
}
}
if (mark==0)
{
printf("\t\t\tû�и��û�����Ϣ\n");
printf("\t\t\t��������������˵�\n");
getch();
return(0);
}
return(0);
}
void deletebyphone()
{
int i,j;
int deletemark=0;
char phone[20];
printf("\t\t\t������Ҫɾ���û��绰����:\n");
scanf("%s",phone);
if(num==0)
{
printf("\t\t\t�Բ����ļ������κμ�¼\n");
printf("\t\t\t��������������˵�\n");
getch();
return;
}
for (i=0;i<num;i++)
{
if (strcmp(student[i].phone,phone)==0)
{
printf("\t\t\t��������Ҫɾ�����û���¼:\n");
printf("\t\t\t����: %s",student[i].name);
printf("\t\t\t�绰: %s",student[i].phone);
printf("\t\t\t�༶: %s",student[i].adress);
printf("\t\t\t��������:%s",student[i].e_mail);
printf("\t\t\t�Ƿ�ɾ��?(y/n)");
if (getch()=='y' || getch()=='Y')
{
for (j=i;j<num-1;j++)
student[j]=student[j+1];
num--;
deletemark++;
printf("\t\t\tɾ���ɹ�");
printf("\t\t\t�Ƿ����ɾ��?(y/n)");
if (getch()=='y' || getch()=='Y')
deletebyphone();
return;
}
else
return;
}
continue;
}
if (deletemark==0)
{
printf("\t\t\tû�и��û��ļ�¼");
printf("\t\t\t�Ƿ����ɾ��?(y/n)");
if(getch()=='y' || getch()=='Y')
deletebyphone();
return;
}
return;
}
void deletebyname()
{
int a=0;
int findmark=0;
int j;
int deletemark=0;
int i;
char name[20];
printf("\t\t\t������Ҫɾ���û�����:\n");
scanf("%s",name);
for (i=a;i<num;i++)
{
if(strcmp(student[i].name,name)==0)
{
printf("\t\t\t��������Ҫɾ�����û���¼:");
findmark++;
printf("\t\t\t________________________________");
printf("\t\t\t����: %s",student[i].name);
printf("\t\t\t�绰: %s",student[i].phone);

printf("\t\t\t�༶: %s",student[i].adress);
printf("\t\t\te-mail:%s",student[i].e_mail);
printf("\t\t\t________________________________");
printf("\t\t\t�Ƿ�ɾ��?(y/n)");
if (getch()=='y' || getch() == 'Y')
{
for(j=i;j<num-1;j++)
student[j]=student[j+1];
num--;
deletemark++;
printf("\t\t\tɾ���ɹ�");
if((i+1)<num)
{
printf("\t\t\t�Ƿ����ɾ����ͬ�������û���Ϣ?(y/n)");
if (getch()=='y')
{
a=i;
continue;
}
}
printf("\t\t\t�Ƿ����ɾ��?(y/n)");
if (getch()=='y')
deletebyname();
return;
}
if((i+1)<num)
{
printf("\t\t\t�Ƿ����ɾ����ͬ�������û���Ϣ?(y/n)");
if (getch()=='y' || getch() == 'Y')
{
a=i;
continue;
}
}
}
else
continue;
}
if ((deletemark==0)&&(findmark==0))
{
printf("\t\t\tû�и��û��ļ�¼");
printf("\t\t\t�Ƿ����ɾ��?(y/n)");
if(getch()=='y' || getch() == 'Y')
deletebyphone();
return;
}
else if (findmark!=0)
{
printf("\t\t\tû��������Ϣ");
printf("\t\t\tû�и��û��ļ�¼");
printf("\t\t\t�Ƿ����ɾ��?(y/n)");
if(getch()=='y' || getch() == 'Y')
deletebyphone();
return;
}
}
int dele()
{
char choic;
printf("\t\t\t1-���绰����ɾ�� 2-������ɾ��");
printf("\t\t\t��ѡ��:");
choic=getch();
switch (choic)
{
case '1':deletebyphone();break;
case '2':deletebyname();break;
}
return(0);
}
int sortbyname() 
{
int i,j;
struct record tmp;
for (i=1;i<num;i++)
{
if(strcmp(student[i].name,student[i-1].name)<0)
{
tmp=student[i];
j=i-1;
do
{
student[j+1]=student[j];
j--;
}while ((strcmp(tmp.name,student[j].name)<0&&j>=0));
student[j+1]=tmp;
}
}
printf("\t\t\t����ɹ�,�Ƿ���ʾ?(y/n)");
if (getch()=='y')
list();
return(0);
}
int main()
{
printf("\t\t************************************************\n");
printf("\t\t***************��ӭ����ѧ����Ϣ����ϵͳ*******************\n");
printf("\t\t*************************************************\n");
printf("��������������˵�\n");
getch();
int selectnum;
while(1)
{
selectnum = menu_select();
switch(selectnum)
{
case 0:
{
adduser();
break;
}
case 1:
{
list();
break;
}
case 2:
{
searchbyname();
break;
}
case 3:
{
searchbyphone();
break;
}
case 4:
{
adduser(); 
break;
}
case 5:
{
sortbyname();
break;
}
case 6:
{
dele();
break;
}
case 7:
{
printf("BYE BYE!\n");
system("pause");
getchar();
exit(0);
}
}
}
getchar();
return 0;
} 
