//必须在编译选项增加-std=c++11 
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "command.h"
#include "config.h"
using namespace std;
void print_main()
{

	cout<<"#############################################"<<endl;
	cout<<"#          欢迎使用抽号系统   v2.0.1        #"<<endl;
	cout<<"#              请按[1]直接抽号              #"<<endl;
	cout<<"#               按[2]加载名单               #"<<endl;
	cout<<"#               按[3]新建名单               #"<<endl;
	cout<<"#             按[4]查看版本信息             #"<<endl;
	cout<<"#               按[5]更改设置               #"<<endl;
	cout<<"#                 按[6]退出                 #"<<endl;
	cout<<"#############################################"<<endl;
	return;
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
			    randm();
			else if(input=='2')
			{
				cout<<"输入文件名：";
				ifread=true;
				if(listr()==1)
				   ifread=false;
			}
			else if(input=='3')
			    listc(ifcomm);
			else if(input=='4')
			    info();
			else if(input=='5')
			    pconfig();
			else if(input=='6')
			    return 0;
			system("pause");
			system("cls");
		}
	}
	return 0;

}
