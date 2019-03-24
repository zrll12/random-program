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
}
void pconfig()
{
	system("cls");
	ifstream rea;
	rea.open("basic.config");
	int con;
	rea>>con;
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
	        con=1-con;
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
		    return;
		}
		system("cls");
	}
}
