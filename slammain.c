#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

char catagories[][15]={"Good Friend","School Friend","College Friend","Commom Friend","Best Friend","BFF"};
void returnfunc(void);
void mainmenu(void);
void addfriends(void);
void deletefriends(void);
void editfriends(void);
void searchfriends(void);
void viewfriends(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void Password();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findfriend;
char password[10]={"codewithc"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct friends
{
int id;
char stname[20];
char name[20];
char address[20];
char movie[20];
char factor[20];
char factors[20];
int age;
float bdate;
int count;
int session;
char *cat;

};
struct friends a;
int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{

system("cls");

system("Color A0");
int i;
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add friends   ");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Delete friends");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Search friends");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. View friend list");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. Edit friend's Record");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application");
gotoxy(20,17);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,18);
t();
gotoxy(20,21);
printf("Enter your choice:");
switch(getch())
{
case '1':
addfriends();
break;
case '2':
deletefriends();
break;
case '3':
searchfriends();
break;
case '4':
viewfriends();
break;
case '5':
editfriends();
break;
case '6':
{
system("cls");
system("Color BC");
gotoxy(16,3);
printf("\tSLAM BOOK PROJECT");
gotoxy(16,4);
printf("\tMini Project in C");
gotoxy(16,5);
printf("\tis brought to you by");
gotoxy(16,7);
printf("\tVidya \tRibeka \tJennifer");
gotoxy(16,8);
printf("******************************************");
gotoxy(16,10);
printf("*******************************************");
gotoxy(16,11);
printf("*******************************************");
gotoxy(16,13);
printf("********************************************");
gotoxy(10,17);
printf("Exiting in 3 second...........>");
Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
void addfriends(void)    //funtion that add friends
{
system("cls");
system("Color 01");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Good Friend");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. School Friend");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. College Friend");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. Common Friend");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Best Friend");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. BFF");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,22);
printf("Enter your choice:");
scanf("%d",&s);
if(s==7)

mainmenu() ;
system("cls");
fp=fopen("slam.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,24);
printf("The record is sucessfully saved");
gotoxy(21,25);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
addfriends();
}
}
void deletefriends()    //function that delete items from file fp
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the friend ID to  delete:");
scanf("%d",&d);
fp=fopen("slam.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The friend record is available");
gotoxy(10,8);
printf("friend name is %s",a.name);
gotoxy(10,9);
printf("session. is %d",a.session);
findfriend='t';
}
}
if(findfriend!='t')
{
gotoxy(10,10);
printf("No record is found modify the search");
if(getch())
mainmenu();
}
if(findfriend=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(y/n):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("slam.dat");
rename("test.dat","slam.dat"); //copy all item from temporary file to fp except that
fp=fopen("slam.dat","rb+");    //we want to delete
if(findfriend=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}
void searchfriends()
{
system("cls");
system ("Color 17");
int d;
printf("*****************************Search friends*********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("slam.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Friends By Id****");
gotoxy(20,5);
printf("Enter the friend id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Friend is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Address:%s ",a.address);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Movie:%s ",a.movie);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Favourite Actor:%s ",a.factor);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Favourite Actoress:%s ",a.factors);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2 Year Of Friendship:%d ",a.age);gotoxy(47,15);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,16);
printf("\xB2 B'day:%.2f",a.bdate);gotoxy(47,16);printf("\xB2");
gotoxy(20,17);
printf("\xB2 Starting.. :%d ",a.session);gotoxy(47,17);printf("\xB2");
gotoxy(20,18);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
findfriend='t';
}

}
if(findfriend!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchfriends();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search friends By Name****");
gotoxy(20,5);
printf("Enter Friend Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Friend is already available in Slam Book !");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Address:%s",a.address);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Movie:%s",a.movie);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Favourite Actor:%s",a.factor);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Favourite Actoress:%s",a.factors);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2 Year of Friendship :%d",a.age);gotoxy(47,15);printf("\xB2");
gotoxy(20,16);
printf("\xB2 Bday:%.2f",a.bdate);gotoxy(47,16);printf("\xB2");
gotoxy(20,17);
printf("\xB2 Starting.. :%d ",a.session);gotoxy(47,17);printf("\xB2");
gotoxy(20,18);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchfriends();
else
mainmenu();
break;
}
default :
getch();
searchfriends();
}
fclose(fp);
}
void viewfriends(void)  //show the list of friend 
{
int j;
system("cls");
gotoxy(1,1);
printf("*********************************FRIENDS LIST*****************************");
gotoxy(2,2);
printf(" CATEGORY      ID   Friend's Name   Address   Movie    Fav Actor  Fav Actoress  Year of Friendship   Bday   Starting..");
j=4;
fp=fopen("slam.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
printf("%s",a.cat);
gotoxy(17,j);
printf("%d",a.id);
gotoxy(22,j);
printf("%s",a.name);
gotoxy(39,j);
printf("%s",a.address);
gotoxy(48,j);
printf("%s",a.movie);
gotoxy(58,j);
printf("%s",a.factor);
gotoxy(70,j);
printf("%s",a.factors);
gotoxy(85,j);
printf("%d",a.age);
gotoxy(102,j);
printf("%.2f",a.bdate);
gotoxy(111,j);
printf("%d",a.session);
printf("\n\n");
j++;

}

fclose(fp);
gotoxy(35,25);
returnfunc();
}
void editfriends(void)  //edit information about friend
{
system("cls");
system("Color D7");
int c=0;
int d,e;
gotoxy(20,4);
printf("****Edit Friends Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Friend Id to be edited:");
scanf("%d",&d);
fp=fopen("slam.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The Friend is availble");
gotoxy(15,8);
printf("The Friend ID:%d",a.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",a.name);
gotoxy(15,10);
printf("Enter new address:");scanf("%s",a.address);
gotoxy(15,11);
printf("Enter new movie:");scanf("%s",a.movie);
gotoxy(15,12);
printf("Enter new fav actor:");scanf("%s",a.factor);
gotoxy(15,13);
printf("Enter new fav actoress:");scanf("%s",a.factors);
gotoxy(15,14);
printf("Enter new year of friendship:");scanf("%d",&a.age);
gotoxy(15,15);
printf("Enter new birth day:");scanf("%f",&a.bdate);
gotoxy(15,16);
printf("Enter new Starting..:");scanf("%d",&a.session);
gotoxy(15,17);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
system("Color F5");
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(50,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(50,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(50,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(50,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(50,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(50,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(50,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2");gotoxy(50,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2");gotoxy(50,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2");gotoxy(50,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Friend ID:\t");
gotoxy(35,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThis Friend Id already exists\a");
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Friend's Name:");gotoxy(35,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Address:");gotoxy(35,8);
scanf("%s",a.address);
gotoxy(21,9);
printf("Movie:");gotoxy(35,9);
scanf("%s",a.movie);
gotoxy(21,10);
printf("Fav Actor:");gotoxy(35,10);
scanf("%s",a.factor);
gotoxy(21,11);
printf("Fav Actoress:");gotoxy(35,11);
scanf("%s",a.factors);
gotoxy(21,12);
printf("Year of Friendship:");gotoxy(45,12);
scanf("%d",&a.age);
gotoxy(21,13);
printf("Bday:");gotoxy(35,13);
scanf("%f",&a.bdate);
gotoxy(21,14);
printf("Starting..:");gotoxy(35,14);
scanf("%d",&a.session);
return 1;
}
int checkid(int t)  //check whether the friend is exist in slam book or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if friend exits
return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
system("Color F4");
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
//End of program
