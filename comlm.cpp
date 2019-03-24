#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream> 
#include "command.h"
using namespace std;
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
		cout<<"RANDOM-POGRA> ";
		cin>>zhil;
	    if(zhil=="help")
	       help();
	    else if(zhil=="exit")
	       return 0;
	    else if(zhil=="random")
	    {
	       randm();
	    }
	    else if(zhil=="info")
	       info();
	    else if(zhil=="cls")
		   system("cls"); 
		else if(zhil=="listc")
		   listc(true);
        else if(zhil=="listr")
           listr();
        else if(zhil=="tool")
        {
		    system("tool.exe");
		    system("cls");
		    cout<<"#######################################"<<endl;
	        cout<<"##      欢迎使用zrl的抽号系统        ##"<<endl;
        	cout<<"##      查询指令列表请输入\"help\"     ##"<<endl;
	        cout<<"#######################################"<<endl;
		}
		else
		   cout<<"未知指令，可能暂未更新"<<endl;
	}
	return 0;
}
