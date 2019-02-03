#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;
int n1;
string lname[1000];
void print_main()
{
	cout<<"#############################################"<<endl;
	cout<<"#           欢迎使用抽号系统   v2.0         #"<<endl;
	cout<<"#              请按[1]直接抽号              #"<<endl;
	cout<<"#               按[2]加载名单               #"<<endl;
	cout<<"#               按[3]新建名单               #"<<endl;
	cout<<"#              按[4]查看版本信息            #"<<endl;
	cout<<"#                 按[5]退出                 #"<<endl;
	cout<<"#############################################"<<endl;
	return;
}
void info()
{
	cout<<"程序版本：2.0"<<endl;
	cout<<"内部版本：190203"<<endl;
	cout<<"版权归zrl所有"<<endl;
	getch();
	return; 
}
void listc()
{
	ofstream of;
	char name[256];
	char a[256];
	cin>>a;
	of.open(a);
	int num;
	cin>>num;
	of<<num<<endl;
	cout<<"文件创建成功，下面请输入人名完成创建（每个人名之间打空格或换行）"<<endl;
	for(int i=1;i<=num;i++)
	{
		cin>>name;
		of<<name<<endl;
	}
	cout<<"文件"<<a<<"创建成功"<<endl;
	return; 
}
int listr()
{
	char n[256];
	cin>>n;
	ifstream of(n);
	of>>n1;
	int i;
	for(i=1;i<=n1;i++)
	{
		of>>lname[i];
	}
	if(n1!=0)
	{
	   cout<<"文件"<<n<<"读取成功！"<<endl;
	   return 0;
    }
    else
       cout<<"文件"<<n<<"读取失败，可能因为杀毒软件阻止或文件已经损坏"<<endl;
    return 1;
}
int radom(int n)
{
int j=0;
	while(j==0)
	{
	   srand((unsigned)time(NULL));
   	   j = rand() % n;
	}
	return j;
}
int main()
{
	//Read config
	std::ifstream rcon ("basic.config", std::ifstream::binary);
	bool ifcomm;
	rcon>>ifcomm;
	//Use command line mod
	if(ifcomm == true)
	{
		system("comlm.exe");
	}
	else//Use graphical interface 
	{
	    char input;
	    int n;
	    bool ifread=false;
		while(1)
		{
			print_main();
			input=getch();
			if(input=='1')
			{
				if(ifread==false)
				{
					cout<<"请输入能抽到的最大值（最小值为0）:";
				    cin>>n;
			        cout<<radom(n);
				}
				else
					cout<<lname[radom(n)]<<endl;
				getch();
			}
			else if(input=='2')
			{
				cout<<"输入文件名：";
				ifread=true;
				if(listr()==1)
				   ifread=false;
			}
			else if(input=='3')
			    listc();
			else if(input=='4')
			    info();
			else if(input=='5')
			    return 0;
			system("cls");
		}
	}
	system("pause");
	return 0;
}

