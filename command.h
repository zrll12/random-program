#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>
using namespace std;
string zhil;
char lname[256][100];
char a[256],n[256];
int n1;
int nu;
bool ir=false;
int help()
{
	cout<<"指令列表："<<endl;
	cout<<"random [int:n]：从1~n之间随机取一个整数。如果已经读取列表，则不输入n"<<endl;
	cout<<"cls：清空整个屏幕"<<endl;
	cout<<"info：显示系统信息"<<endl;
	cout<<"exit：退出程序"<<endl;
	cout<<"listc <string:m> <int:n>：创建一个名为m,包含n个元素的列表文件"<<endl;
	cout<<"listr <string:m>：读取名为m的文件"<<endl;
	cout<<"tool：进入设置菜单"<<endl;
	cout<<"注：<>中为必填，[]中为条件性填写"<<endl;
	return 0;
}
void randm()
{
	int j=0;
	if(ir==false)
	{
	    cout<<"请输入能抽到的最大值（最小值为0）:";
        cin>>n1;
    }
	while(j==nu)
	{
	   srand((unsigned)time(NULL));
   	   j = rand() % n1;
	}
	nu=j;
	if(ir==true)
	    cout<<lname[j]<<endl;
	else
        cout<<j<<endl;
	return;
}
int info()
{
	cout<<"系统版本：2.0.2"<<endl;
	cout<<"内部版本：190226"<<endl;
	cout<<"版权归zrl所有"<<endl;
	return 0;
}
int listc(bool comm)
{
	ofstream of;
	char name[256];
	string a1;
	cin>>a1;
	a1+=".lis";
	strcpy(a,a1.c_str());
	of.open(a);
	int num;
	if(comm==false)
	   cout<<char(7);
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
	string n2;
	cin>>n2;
	n2+=".lis";
	strcpy(n,n2.c_str());
	ir=false;
	ifstream of(n);
	of>>n1;
	int i;
	for(i=0;i<n1;i++)
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
    return 0;
}
