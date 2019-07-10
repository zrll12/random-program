#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <Windows.h>
#include <conio.h>
using namespace std;


#define rand() _r_a_n_d_(r_a_n_d)

string zhil;
char lname[256][100];
char a[256],n[256];
int n1,times;//times:现在随机到哪一位同学
char name[256];
bool ir=false;
int help() {
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
void re_upset() { //重新打乱
	srand(unsigned(time(0))); //fixed:为了避免可能的问题(wenge) 
	random_shuffle(lname,lname+n1-1);
	/*///////////////////////////////////////////bug
	ofstream ow;
	ow.open(n);
	char comman[265]="del ";
	strcat(comman,n);
	system(comman);
	ow<<n1<<endl;
	for(int i=0; i<=n1; i++)
		ow<<lname[i]<<endl;
	ow.close();
	*/
	return;
}
void randm() {
	if(ir==false) {
		mt19937_64 r_a_n_d(time(NULL));
		uniform_int_distribution<long long> _r_a_n_d_(0,9223372036854775807);
		cout<<"请输入能抽到的最大值（最小值为0）:";
		cin>>n1;
		cout<<rand() % (n1+1)<<endl;//fixed:取模错误(wenge)
	} 
	else /*if(ir==true)*/ {
		if(times>=n1){
			re_upset();
			times=0;//fixed:抽到n1次后会抽到空白 (wenge)
		}
		cout<<lname[times]<<endl;
		times++;
	}
	return;
}
int info() {
	cout<<"系统版本：2.1.0"<<endl;
	cout<<"内部版本：190416"<<endl;
	cout<<"版权归zrl所有"<<endl;
	return 0;
}
int listc(bool comm) {
	ofstream of;
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
	for(int i=1; i<=num; i++) {
		cin>>name;
		of<<name<<endl;
	}
	cout<<"文件"<<a<<"创建成功"<<endl;
	of.close();
	return 0;
}
int listr() {
	string n2;
	cin>>n2;
	n2+=".lis";
	strcpy(n,n2.c_str());
	ir=false;
	ifstream of(n);
	of>>n1;
	int i=0,counter=0;
	while(of>>lname[i]) {
		i++;
		counter++;
	}
	of.close();
	if(n1!=0 && counter==n1) {
		ir=true;
		cout<<"文件"<<n<<"读取成功！"<<endl;
		re_upset();
		/*///////////////////////////////////////bug 
		random_shuffle(lname,lname+n1);
		//使用随机后的名单替换之前的
		ofstream ow;//ow = over_write
		ow.open(n);
		//先删除之前的
		char comman[265]="del ";//用于储存拼接后的命令
		strcat(comman,n);
		system(comman);
		//生成打乱后的
		ow<<n1<<endl;
		for(i=0; i<=n1; i++)
			ow<<lname[i]<<endl;
		ow.close();
		*/
	}
	else
		cout<<"文件"<<n<<"读取失败，可能因为杀毒软件阻止或文件已经损坏"<<endl;
	return 0;
}
