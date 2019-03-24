#include <iostream>
#include "config.h"
#include <string>
#include <io.h>
using namespace std;
void ptools()
{
	cout<<"#############################################"<<endl;
	cout<<"#             这是本程序的工具栏            #"<<endl;
	cout<<"#               按[1]更改设置               #"<<endl;
	cout<<"#              按[2]自动加后缀              #"<<endl;
	cout<<"#         按[3]删除菜单文件(带后缀)         #"<<endl;
	//cout<<"#               按[4]检查更新               #"<<endl;
	cout<<"#                 按[4]返回                 #"<<endl;
	cout<<"#############################################"<<endl;
}
int main()
{
	char putin;
	while(1)
	{
		system("cls");
		ptools();
	    putin=getch();
	    if(putin=='1')
		{
			pconfig();
			return true;
		}
		else if(putin=='2')
		{
			string wjm;//wjm：文件名 
			cout<<"请输入文件名：";
			cin>>wjm;
			string name1,comm;
			name1=wjm+".lis";
			comm="ren "+wjm+" "+name1;
			char comma[1000],name2[500];
			memset(comma,0,sizeof(comma));
			strcpy(comma,comm.c_str());
			system(comma);
			memset(name2,0,sizeof(name2));
			strcpy(name2,name1.c_str());
			if(_access(name2,0)==-1)
				cout<<"更改失败，请检查杀毒状态和管理员权限"<<endl;
			else
				cout<<"更改成功！"<<endl;
		}
		else if(putin=='3')
		{
			cout<<"请输入文件名（不用加后缀）：";
			string name;
			cin>>name;
			name+=".lis";
			string comm;
			comm="del "+name;
			char comma[500];
			memset(comma,0,sizeof(comma));
			strcpy(comma,comm.c_str());
			system(comma);
			char tempname[256];
			memset(tempname,0,sizeof(tempname));
			strcpy(tempname,name.c_str());
			if(_access(tempname,0)==-1)
			    cout<<"删除成功！"<<endl;
			else
			    cout<<"删除失败，请检查杀毒状态和管理员权限"<<endl;
		}
		else if(putin=='4')
		     return 0;
		cout<<"按任意键继续..."<<endl;
		getch();
	} 
}
