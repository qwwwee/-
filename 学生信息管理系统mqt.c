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
printf("\t\t***********欢迎进入学生信息管理系统********\n\n");
printf("\t\t\t0. 输入记录\n");
printf("\t\t\t1. 显示记录\n");
printf("\t\t\t2. 按姓名查找\n");
printf("\t\t\t3. 按电话号码查找\n");
printf("\t\t\t4. 插入记录 \n");
printf("\t\t\t5. 按姓名排序\n");
printf("\t\t\t6. 删除记录\n");
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
printf("\t\t\t**************** 请输入用户信息 ****************\n");
printf("\t\t\t输入姓名:\n");
scanf("%s",student[num].name);
printf("\t\t\t输入电话号码:\n");
scanf("%s",student[num].phone);
printf("\t\t\t输入班级:\n");
scanf("%s",student[num].adress);
printf("\t\t\t输入学号:\n");
scanf("%s",student[num].postcode);
printf("\t\t\t输入电子邮箱:\n");
scanf("%s",student[num].e_mail);
num++;
printf("\t\t\t是否继续添加?(Y/N):\n");
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
printf("\t\t\t*************** 以下为通讯录所有信息************\n");
for (i=0;i<num;i++)
{
printf("\t\t\t姓名:%s\n",student[i].name);
printf("\t\t\t电话:%s\n",student[i].phone);
printf("\t\t\t班级:%s\n",student[i].adress);
printf("\t\t\t学号:%s\n",student[i].postcode);
printf("\t\t\t电子邮箱:%s\n",student[i].e_mail);
if(i+1<num)
{
system("pause");
}
}
printf("\t\t\t************************************************\n");
}
else
printf("\t\t\t学生信息管理系统中无任何纪录\n");
printf("\t\t\t按任意键返回主菜单:\n");
getch(); 
return;
}
int searchbyname()
{
int mark=0;
int i;
printf("\t\t\t***************** 按姓名查找 *******************\n");
char name[20];
printf("\t\t\t请输入姓名:\n");
scanf("%s",name);
for(i=0;i<num;i++)
{
if (strcmp(student[i].name,name)==0)
{
printf("\t\t\t************* 以下是您查找的用户信息 ***********\n");
printf("\t\t\t姓名: %s",student[i].name);
printf("\t\t\t电话: %s",student[i].phone);
printf("\t\t\t班级: %s",student[i].adress);
printf("\t\t\t电子邮箱:%s",student[i].e_mail);
printf("\t\t\t************************************************\n");
mark++;
if((i+1)<num)
{
printf("\t\t\t是否继续查找相同名字的用户信息:(y/n)\n");
if(getch()=='y' || getch()=='Y')
{
continue;
}
else
return(0);
}
else
{
printf("\t\t\t按任意键返回主菜单");
getch();
return(0);
}
}
}
if(mark == 0)
{
printf("\t\t\t没有相同姓名的用户纪录\n");
printf("\t\t\t按任意键返回主菜单\n");
getch();
return(0);
}
return 0;
}
int searchbyphone()
{
int mark=0;
int i;
printf("\t\t\t****************** 按电话查找 ******************\n");
char phone[10];
printf("\t\t\t请输入电话号码:\n");
scanf("%s",phone);
for(i=0;i<num;i++)
{
if (strcmp(student[i].phone,phone)==0)
{
printf("\t\t\t************** 以下是您查找的用户信息 **********\n");
printf("\t\t\t姓名: %s",student[i].name);
printf("\t\t\t电话: %s",student[i].phone);
printf("\t\t\t班级: %s",student[i].adress);
printf("\t\t\t电子邮箱:%s",student[i].e_mail);
printf("\t\t\t************************************************\n");
printf("\t\t\t按任意键返回主菜单\n");
mark++;
getch();
return(0);
}
}
if (mark==0)
{
printf("\t\t\t没有改用户的信息\n");
printf("\t\t\t按任意键返回主菜单\n");
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
printf("\t\t\t请输入要删除用户电话号码:\n");
scanf("%s",phone);
if(num==0)
{
printf("\t\t\t对不起，文件中无任何纪录\n");
printf("\t\t\t按任意键返回主菜单\n");
getch();
return;
}
for (i=0;i<num;i++)
{
if (strcmp(student[i].phone,phone)==0)
{
printf("\t\t\t以下是您要删除的用户纪录:\n");
printf("\t\t\t姓名: %s",student[i].name);
printf("\t\t\t电话: %s",student[i].phone);
printf("\t\t\t班级: %s",student[i].adress);
printf("\t\t\t电子邮箱:%s",student[i].e_mail);
printf("\t\t\t是否删除?(y/n)");
if (getch()=='y' || getch()=='Y')
{
for (j=i;j<num-1;j++)
student[j]=student[j+1];
num--;
deletemark++;
printf("\t\t\t删除成功");
printf("\t\t\t是否继续删除?(y/n)");
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
printf("\t\t\t没有该用户的纪录");
printf("\t\t\t是否继续删除?(y/n)");
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
printf("\t\t\t请输入要删除用户姓名:\n");
scanf("%s",name);
for (i=a;i<num;i++)
{
if(strcmp(student[i].name,name)==0)
{
printf("\t\t\t以下是您要删除的用户纪录:");
findmark++;
printf("\t\t\t________________________________");
printf("\t\t\t姓名: %s",student[i].name);
printf("\t\t\t电话: %s",student[i].phone);

printf("\t\t\t班级: %s",student[i].adress);
printf("\t\t\te-mail:%s",student[i].e_mail);
printf("\t\t\t________________________________");
printf("\t\t\t是否删除?(y/n)");
if (getch()=='y' || getch() == 'Y')
{
for(j=i;j<num-1;j++)
student[j]=student[j+1];
num--;
deletemark++;
printf("\t\t\t删除成功");
if((i+1)<num)
{
printf("\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
if (getch()=='y')
{
a=i;
continue;
}
}
printf("\t\t\t是否继续删除?(y/n)");
if (getch()=='y')
deletebyname();
return;
}
if((i+1)<num)
{
printf("\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
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
printf("\t\t\t没有该用户的纪录");
printf("\t\t\t是否继续删除?(y/n)");
if(getch()=='y' || getch() == 'Y')
deletebyphone();
return;
}
else if (findmark!=0)
{
printf("\t\t\t没有重名信息");
printf("\t\t\t没有该用户的纪录");
printf("\t\t\t是否继续删除?(y/n)");
if(getch()=='y' || getch() == 'Y')
deletebyphone();
return;
}
}
int dele()
{
char choic;
printf("\t\t\t1-按电话号码删除 2-按姓名删除");
printf("\t\t\t请选择:");
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
printf("\t\t\t排序成功,是否显示?(y/n)");
if (getch()=='y')
list();
return(0);
}
int main()
{
printf("\t\t************************************************\n");
printf("\t\t***************欢迎进入学生信息管理系统*******************\n");
printf("\t\t*************************************************\n");
printf("按任意键进入主菜单\n");
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
