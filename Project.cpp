#include<iostream.h>
using namespace std;
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
int choice;
char username[50];
char password[20];
char qw[20];

class ebtariff
{
private:
int sertype;
int currentreading;
int lastreading;
char name[20];
char phoneno[20];
char streetname[200];
float doorno;
int power;
char aadharno[12];
char areaname[100];
char cityname[200];
char email_id[50];
public:
float serviceno;
int newreading;
int newreading2;
unsigned long cost;
void mainmenu();
void getdata();
void getchoice();
void info();
void ser();
void display1();
void choiceone();
void choicetwo();
void choicethree();
void choicefour();
void choicefive();
void choicesix();
void modify();
}bill;

void ebtariff::mainmenu()
{
clrscr();
for(int d=0;d<=79;d++)
cout<<"-";
cout<<"\n\t\t\t\t!!!!! HOME PAGE !!!!!\n";
for(int f=0;f<=79;f++)
cout<<"-";
cout<<"\n\n\n\n\t\t\t\t1.TO PRINT BILL";
cout<<"\n\t\t\t\t2.TO CREATE A SERVICE";
cout<<"\n\t\t\t\t3.TO SEARCH A SERVICE";
cout<<"\n\t\t\t\t4.DELETE A SERVICE NUMBER";
cout<<"\n\t\t\t\t5.TO MODIFY A SERVICE";
cout<<"\n\t\t\t\t6.EXIT";
cout<<"\nENTER YOUR CHOICE [1(or)2(or)3(or)4(or)5(or)6]:";
}

void ebtariff::getdata()
{
cout<<"\n1.ENTER THE NAME OF THE CONUSMER:";
gets(name);
cout<<"\n2.ENTER AADHAR NUMBER:";
for(int o=0;o<12;o++)
cin>>aadharno[o];
cout<<"\n3.ENTER YOUR EMAIL ID:";
gets(email_id);
cout<<"\n4.ENTER ADDRESS:";
cout<<"\n\t\t\t 4.1DOOR NUMBER:";
cin>>doorno;
cout<<"\n\t\t\t 4.2 NAME OF THE STREET:";
gets(streetname);
cout<<"\n\t\t\t 4.3 NAME OF THE AREA:";
gets(areaname);
cout<<"\n\t\t\t 4.4 DISTRICT NAME:";
gets(cityname);
cout<<"\n\t\t\t 5.PHONE NUMBER:";
gets(phoneno);
cout<<"\n\t\t\t 6.SERVICE NUMBER:";
cin>>serviceno;
cout<<"\n7.TARIFF TYPE:";
cout<<"1.COMMERCIAL\t2.INDUSTRIAL\t3.DOMESTIC:";
cout<<"\nENTER YOU OPTIONS [1(or)2(or)3]:";
cin>>sertype;
lastreading=0;
}
void ebtariff::ser()
{
switch(sertype)
{
case 1:
cout<<"\n   COST PER UNIT ENERGY IS Rs7.\n";
cost=power*7;
break;

case 2:
cout<<"\n   COST PER UNIT ENERGY IS Rs 5.\n";
cost=power*5;
break;

case 3:
cout<<"\n   COST PER UNIT ENERGY IS Rs 3.\n";
cost=power*3;
break;
}
}
void ebtariff::info()
{
cout<<"\n1.NAME:"<<name;
cout<<"\n2.SERVICE NUMBER:"<<serviceno;
cout<<"\n3.AADHAR NUMBER:";
for(int t=0;t<12;t++)
cout<<aadharno[t];
cout<<"\n4.EMAIL ID:"<<email_id;
cout<<"\n5.PHONE NUMBER:"<<phoneno;
cout<<"\n6.ADDRESS:\n\t\t\t";
cout<<"6.1 DOOR NUMBER:"<<doorno;
cout<<"\n\t\t\t6.2 NAME OF THE STREET:"<<streetname;
cout<<"\n\t\t\t6.3 NAME OF THE AREA:"<<areaname;
cout<<"\n\t\t\t6.4 DISTRICT NAME:"<<cityname;
}


void ebtariff::choiceone()
{
ifstream fillin;
clrscr();
fillin.open("service.txt",ios::binary|ios::in);
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
 cout<<"\n\t\t  \t!!!!! ELECTRICITY BILL !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"\n\n\t  \t";
bill.choicefive();
clrscr();
for(int q1=0;q1<=79;q1++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! ELECTRICITY BILL !!!!!\n";
for(int q2=0;q2<=79;q2++)
cout<<"-";
bill.info();
cout<<"\n7.LAST READING:"<<lastreading;
cout<<"\n8.CURRENT READING:"<<currentreading;
cout<<"\n";
for(int y=0;y<=35;y++)
cout<<"*";
bill.ser();
for(int u=0;u<=35;u++)
cout<<"*";
cout<<"\n\t\t\t*****************************";
cout<<"\n\t\t\t\tTOTAL COST :"<<cost;
cout<<"\n\t\t\t*****************************\n";
getch();
}

void ebtariff::choicefive()
{
char aaa;
fstream filline;
filline.open("service.txt",ios::in|ios::out|ios::binary);
char found='f';
int searched,pos;
char lk;
do{
cout<<"\n\t\t\tENTER THE SERVICE NUMBER TO BE BILLED: :";
cin>>searched;
while(!filline.eof())
{
pos=filline.tellg();
filline.read((char*)&bill,sizeof(bill));
if(bill.serviceno==searched)
{
bill.info();
bill.lastreading=bill.currentreading;
cout<<"\nLAST READING:"<<bill.lastreading;
cout<<"\nENTER THE CURRENT READING:";
cin>>currentreading;
if(currentreading<bill.lastreading)
{
cout<<"NEW READING MUST BE GREATER THAN THE OLD (OR) PREVIOUS READING::PLEASE CONTINUE FROM FIRST...PRESS 'y' TO PROCEED:";
cin>>lk;
if(lk=='y')
choiceone();
break;
}
else
power=currentreading-bill.lastreading;
bill.ser();
filline.seekg(pos);
filline.write((char*)&bill,sizeof(bill));
found = 't';
break;
}
}
if(found=='f')
{
cout<<"ERROR.... SERVICE NUMBER IS NOT FOUND...";
cout<<"\nDO YOU WANT TO TRY AGAIN???...:ENTER 'Y' TO TRY AGAIN...";
cin>>aaa;
}
}while(aaa=='y');
filline.seekg(0);
clrscr();
while(filline.read((char*)&bill,sizeof(bill)))
bill.info();
filline.close();
}


void ebtariff::getchoice()
{
char yo;
do{
mainmenu();
cin>>choice;
switch(choice)
{
case 1:	choiceone();
	break;
case 2:	choicetwo();
	break;
case 3:	choicethree();
	break;
case 4:	choicefour();
	break;
case 5:	modify();
	break;
case 6: choicesix();
	getch();
	break;
default:cout<<"\n OPTION ENTER DOES NOT MATCH....DO YOU WANT TO TRY AGAIN....PRESS 'y' TO RETRY...:";
cin>>yo;
}
}while(yo=='y');
}

void ebtariff::choicetwo()
{
ofstream file;
char cont;
file.open("service.txt",ios::binary|ios::app);

clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\t\t  \t!!!!! APPLICATION FORM !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
bill.getdata();
file.write((char*)&bill,sizeof(bill));
cout<<"\n\t\t\t\!!!!!!THANK YOU!!!!!!";
file.close();
}

void ebtariff::choicethree()
{
clrscr();
long pos;
char cj;
char foun='y';
ifstream fin3;
int searched;
do{
fin3.open("service.txt",ios::binary|ios::in);
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! SEARCH ENGINE..... !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"\n\n\t\t*ENTER THE SERVICE NUMBER TO VEIW DETAILS:";
cin>>searched;
while(fin3.read((char*)&bill,sizeof(bill)))
{
if(serviceno==searched)
{
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! SEARCH ENGINE..... !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"THE SERVICE NUMBER "<<serviceno<<" CONTAINS :\n";
bill.info();
cout<<"\nLAST READING:"<<lastreading;
bill.ser();
foun='n';
break;
}
}
if(foun=='y')
cout<<"\n...THIS SERVICE NUMBER DOES NOT EXIT....";
fin3.close();
cout<<"\n\nDO YOU WANT TO SEARCH MORE:";
cin>>cj;
}while(cj=='y');
cout<<"\n\t\t\t!!!!THANK YOU!!!!";
getch();
}


void ebtariff::choicefour()
{
ifstream fio1;
ofstream file2;
int check;
char ques;
char aym;
char confirm;
char found1='y';
clrscr();
fio1.open("service.txt",ios::binary|ios::in);
file2.open("temp.txt",ios::binary|ios::out|ios::app);
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\t\t\t!!!!!  DELETION  !!!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"\n\n\t**ENTER SERVICE NUMBER:";
cin>>check;
while(fio1.read((char*)&bill,sizeof(bill)))
{
if(bill.serviceno!=check)
file2.write((char*)&bill,sizeof(bill));
else
{
bill.info();
cout<<"\n IS THE INFORMATION CORRECT???..PRESS ANY KEY TO PROCCED..";
getch();
remove("service.txt");
rename("temp.txt","service.txt");
found1='n';
cout<<"\n****DELETED SUCESSFULLY................*****\n\n";
}
fio1.close();
file2.close();
if(found1=='y')
{
cout<<"RECORD NOT FOUND....";
cout<<"DO YOU WANT TO TRY AGAIN...PRESS 'y' TO RETRY..";
cin>>aym;
}
}while(aym=='y');
}


void ebtariff:: modify()
{
clrscr();
int sea;
float doorno1;
int gt;
char streetname1[20];
char areaname1[20];
char aadharno1[12];
char cityname1[20];
char phoneno1[20];
int sertype1;
char rj;
char email_id1[50];
char newname[20];
long pos1;
fstream fine;
fine.open("service.txt",ios::in|ios::out|ios::binary);
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! MODIFICATION !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";

cout<<"\n\n\n\t\tENTER THE SERVICE NUMBER TO BE MODIFIED:";
cin>>sea;
while(fine.read((char*)&bill,sizeof(bill)))
{
pos1=fine.tellg();
{
if(serviceno==sea)
bill.info();

cout<<"\nOPTIONS TO MODIFY:";
cout<<"\n\t\t\t1.NAME\n\t\t\t2.ADDRESS\n\t\t\t3.PHONE NUMBER";
cout<<"\n\t\t\t4.TARIFF\n\t\t\t5.AADHAR NUMBER\n\t\t\t6.EMAIL ID";
cout<<"\n\t\t\tENTER YOUR CHOICE TO BE MODIFIED:";
cin>>gt;
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! MODIFICATION !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"\n\n\t";
do{
switch(gt)
{
case 1:
cout<<"ENTER NEW NAME:";
gets(newname);
strcpy(name,newname);
break;

case 2:
cout<<"ENTER THE NEW ADDRESS:";
cout<<"\n\t\t\tDOORNO:";
cin>>doorno1;
doorno=doorno1;
cout<<"\n\t\t\t NAME OF THE STREET:";
gets(streetname1);
strcpy(streetname,streetname1);
cout<<"\n\t\t\t NAME OF THE AREA:";
gets(areaname1);
strcpy(areaname,areaname1);
cout<<"\n\t\t\t DISTRICT NAME:";
gets(cityname1);
strcpy(cityname,cityname1);
break;

case 3:
cout<<"\n\t\t\tENTER THE NEW PHONE NUMBER:";
gets(phoneno1);
strcpy(phoneno,phoneno1);
break;

case 4:
cout<<"TYPES OF TRAIFF..:";
cout<<"1.COMMERIAL\n2.DOMESTIC\n3.INDUSTRIAL";
cout<<"\nENTER THE TYPE OF THE TARIFF...[1(or)2(or)3(or)]:";
cin>>sertype1;
sertype=sertype1;
break;

case 5:
cout<<"ENTER THE NEW AADHAR CARD NUMBER:";
for(int y=0;y<12;y++)
{
cin>>aadharno1[y];
aadharno[y]=aadharno1[y];
}
break;

case 6:
cout<<"ENTER THE NEW EMAIL ID:";
gets(email_id1);
strcpy(email_id,email_id1);
break;

default:cout<<"THE OPTION YOU HAVE ENTER IS INVALID....";
cout<<"DO YOU WANT TO TRY AGAIN??... ENTER 'y' TO PROCEED:";
cin>>rj;
}
}while(rj=='y');
fine.seekg(pos1-sizeof(bill));
fine.write((char*)&bill,sizeof(bill));
}
}
}

void ebtariff::choicesix()
{
clrscr();
for(int q=0;q<=79;q++)
cout<<"-";
cout<<"\n\t\t  \t!!!!! ELECTRICITY BOARD !!!!!\n";
for(int r=0;r<=79;r++)
cout<<"-";
cout<<"\n\n\t  \t";
cout<<"EXIT...!!";
cout<<"\n\n\t\tDO YOU WANT TO EXIT:";
char a;
cin>>a;
if(a=='y')
{
cout<<"FOR FURTUR ENQURIES... CONTACT:\n\t\t*PHONE NUMBER:1912\n\t\t*EMAIL ID:electricitysave@gamil.com";
cout<<"\n\n\n\t\t -SHIFT TO RENEWABLE ENERGY..FOR BRIGHT FUTURE..";
getch();
cout<<"\\n\n\n\n\n\t\t\t\t!!!!!!!!!!THANK YOU!!!!!!!!!!";
exit(0);
}
else
getchoice();
getch();
}

int main()
 {
  char ccv;
  char ch;
  do{
  clrscr();
  cout<<"\n\n\n\n\n\n\n\n";
  for(int i=0;i<=79;i++)
  cout<<"-";
  cout<<"\n\t\t\t   SRI VAGEESHA VIDHYASHRAM\n";
  for(int j=0;j<=79;j++)
  cout<<"-";
  cout<<"\n\n\n\t\t\t\t\t\t\tDONE BY:\n\t\t\t\t\t\t\t\tABISHEK BHAT.R\n\t\t\t";
  system("pause");
  clrscr();
  for(int q=0;q<=79;q++)
  cout<<"-";
  cout<<"\n\t\t  \t!!!!! ELECTRICITY BOARD !!!!!\n";
  for(int r=0;r<=79;r++)
  cout<<"-";
  cout<<"\n\n\n\n\n\t\t\tUSERNAME:";
  gets(username);
  cout<<"\n\t\t\tPASSWORD:";
  gets(password);
  if(strcmp(username,"collectorofbill")==0&&(strcmp(password,"qwer1234")==0))
  {
  do
  {
  bill.getchoice();
  cout<<"\n\t\tDO YOU WANT TO RETURN TO HOME PAGE..PRESS 'y' TO RETURN..:";
   cin>>ch;
  }while(ch=='y');
  clrscr();
  cout<<"\n\t\t\tFOR FURTUR ENQURIES... CONTACT:\n\t\t\t\t*PHONE NUMBER:1912\n\t\t\t\t*EMAIL ID:electricitysave@gamil.com";
  cout<<"\n\t\t -RENEWABLE ENERGY MAKES WORLD LESS CARBON FOOT PRINT...";
  }
  if(strcmp(username,"collectorofbill")!=0||(strcmp(password,"qwer1234")!=0))
  {
  cout<<"WRONG PASSWORD\n";
  cout<<"DO YOU WANT TO TRY AGAIN:";
  cin>>ccv;
  }
   }while(ccv=='y');
  getch();
  return 0;
   }
