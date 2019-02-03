#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream> 
using namespace std;
string zhil;
char lname[256][100];
int n1;
int nu;
bool ir=false;
int help()
{
	cout<<"指令列表："<<endl;
	cout<<"random <int:n>：从1~n之间随机取一个整数"<<endl;
	cout<<"cls：清空整个屏幕"<<endl;
	cout<<"info：显示系统信息"<<endl;
	cout<<"exit：退出程序"<<endl;
	cout<<"listc <string:m> <int:n>：创建一个名为m,包含n个元素的列表文件"<<endl;
	cout<<"listr <string:m>：读取名为m的文件"<<endl;
	return 0;
}
int randm(int n)
{
	int j=0;
	while(j==nu)
	{
	   srand((unsigned)time(NULL));
   	   j = rand() % n;
	}
	nu=j;
	return j;
}
int info()
{
	cout<<"系统版本：2.0"<<endl;
	cout<<"内部版本：190203"<<endl;
	cout<<"版权归zrl所有"<<endl;
	return 0;
}
int listc()
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
	return 0; 
}
int listr()
{
	char n[256];
	cin>>n;
	ir=false;
	ifstream of(n);
	of>>n1;
	int i;
	for(i=1;i<=n1;i++)
	{
		of>>lname[i];
	}
	if(n1!=0)
	{
	   ir=true;
	   cout<<"文件"<<n<<"读取成功！"<<endl;
    }
    else
       cout<<"文件"<<n<<"读取失败，可能因为杀毒软件阻止或文件已经损坏"<<endl; 
}
int main()
{
	int num,cho; 
	system("cls");
	cout<<"#######################################"<<endl;
	cout<<"##      欢迎使用zrl的抽号系统        ##"<<endl;
	cout<<"##      查询指令列表请输入\"help\"     ##"<<endl;
	cout<<"#######################################"<<endl;
	for(;;)
	{
		cin>>zhil;
	    if(zhil=="help")
	       help();
	    else if(zhil=="exit")
	       return 0;
	    else if(zhil=="random")
	    {
	       if(ir==false)
	       {
		      cin>>num;
		      cout<<randm(num)<<endl;
		   }
		   else
		   {
		   	  cho=randm(n1);
		   	  cout<<lname[cho]<<endl;
		   }
	    }
	    else if(zhil=="info")
	       info();
	    else if(zhil=="cls")
		   system("cls"); 
		else if(zhil=="listc")
		   listc();
        else if(zhil=="listr")
           listr();
		else
		   cout<<"未知指令，可能暂未更新"<<endl;
	}
	return 0;
}

