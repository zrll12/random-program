#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;
string charToStr(char * contentChar)

{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{

		tempStr+=contentChar[i];
	}
	return tempStr;
}
void change(int lineNum,char *content)
{
	/*
	ifstream in;
	char line[1024]={'\0'};
	in.open("basic.config");
	int i=0;
	string tempStr;
	while(in.getline(line,sizeof(line)))
	{
		i++;
		if(lineNum!=i)
		{
			tempStr+=charToStr(line);
		}
		else
		{
	       tempStr+=charToStr(content);
		}
		tempStr+='\n';
	}
	in.close();
	ofstream out;
	out.open("basic.config");
	out.flush();
	out<<tempStr;
	out.close();
	*/
	ofstream out;
	out.open("basic.config",ios::out|ios::trunc);
	out<<content;
	out.close();
	return;
}
void pconfig()
{
	system("cls");
	ifstream rea;
	rea.open("basic.config");
	int con;//basic.config中至少要写入一个'0'(wenge) 
	
	if(con=rea.get(),con!=EOF){
		char tempstr[2]={'0','\n'};
		change(1,tempstr);
		con=0;
	}
	while(1)
	{
		cout<<"设置"<<endl;
		if(con==0)
	        cout<<"交互模式       图形界面"<<endl;
    	else
    	    cout<<"交互模式       命令行"<<endl;
    	cout<<"按\"1\"来改变交互模式的设置，按\"2\"保存并返回";
    	char get;
    	get=getch();
    	if(get=='1')
    		con^=1;
	        //con=1-con;
	    if(get=='2' && con==0)
	    {
	    	char tempstr[2]={'0','\n'};
	    	change(1,tempstr);
	    	cout<<endl<<"保存成功！"<<endl;
		    return;
		}
		if(get=='2' && con==1)
	    {
	    	char tempstr[2]={'1','\n'};
	    	change(1,tempstr);
	    	cout<<endl<<"保存成功！"<<endl;
		    exit(0);
		}
		system("cls");
	}
}

const int current_version=211;
int update()
{
	system("del version.txt"); 
	system("cls"); 
	cout<<"加载中..."<<endl;
	int ver;
	char link[260];
	//检查更新
	system("aria2c.exe https://zhengruilin.github.io/random-program/version.txt");
	//cout<<"\n\n\n\n\n\n233\n";到这里都正常 
	ifstream up;
	
	up.open("version.txt");
	
	
	up>>ver>>link;
	cout<<"bfgsgfdvgdxbngbjnhdxv grscdxnbvgyudnsc"; 
	
	if(ver==current_version)
	{
		cout<<"您运行的是最新版本的\n";
		system("cls");
		return 0;
	}
	else if(ver<current_version)
	{
	    cout<<"错误：无法识别的版本号\n";
	    system("pause");
	    return 0;
	}
	//下载更新包
	system("cls");
	cout<<"检查到更新，版本："<<ver/100<<"."<<ver/10%10<<"."<<ver%10<<endl;
	cout<<"是否要更新？(Y/N)\n";
	while(1){
		char c=getch();
		if     (c=='Y'||c=='y')break;
		else if(c=='N'||c=='n')return 0;
	}
	char cmd[260];
	strcpy(cmd,"aria2c.exe ");
	strcat(cmd,link); 
	system(cmd);
	//检查更新包
	//解压缩
	system("start updatelauncher.exe");
	exit(0);
	//运行更新程序
	/*
    STARTUPINFO startupInfo = {0};
    PROCESS_INFORMATION processInformation = { 0 };
    
    	BOOL bSuccess = CreateProcess(TEXT("up\\update.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL,&startupInfo,&processInformation);
    if (bSuccess)
    {
        cout << "Succeed loading the update programme!" << endl;
    }
    else
    {
    	ofstream error;
    	error.open("error.txt");
        error << "Cannot start the pogramme!" << endl
            << "Error code:\t" << GetLastError() << endl;
    }
    */
    return 0;
}

