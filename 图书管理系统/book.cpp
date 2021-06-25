#include"book.h"
#include"user.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<sstream>
using namespace std;
ostream & operator<<(ostream &fout, Book &obj){
	fout<<obj.getn()<<endl;
	fout<<obj.getc()<<endl;
	fout<<obj.getnu()<<endl;
}
string charToStr(char * contentChar);
void modifyContentInFile(char *fileName,int lineNum,char *content);
void list(){
	ifstream fin("E:/book.txt",ios::in);
	string temp1,temp2,temp3;
	cout<<"书名\t"<<"编号\t"<<"数量\t"<<endl;
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		cout<<temp1<<'\t'<<temp2<<'\t'<<temp3<<'\t'<<endl;
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 }	
	}
	fin.close();
}
void Book::add(Book b){
	ofstream fout("E:/book.txt",ios::app);
	fout<<b;
	//fout<<name<<endl;
	//fout<<code<<endl;
	//fout<<num<<endl;
	fout.close();
	cout<<"操作成功"<<endl; 
}
string Book::del(){ 
	int i=0; 
	getc();
	string s=code;
	ofstream fout("E:/book.txt",ios::app);
	ifstream fin("E:/book.txt",ios::in);
	string temp1= "1",temp2= "1",temp3= "1";
	//string data = "";  // 保存文件内容
	while(getline(fin,temp1)){
		if(temp1!="0"){
			getline(fin,temp2);
			getline(fin,temp3);
			i+=3;
			if(temp2==s){
			modifyContentInFile("E:/book.txt",i-2,"0");
			modifyContentInFile("E:/book.txt",i-1,"0");
			modifyContentInFile("E:/book.txt",i,"0");
			}	
			}
		else{
			getline(fin,temp2);
			getline(fin,temp3);
			i+=3;	
		}
		}
		cout<<"操作成功"<<endl; 
		cout<<"当前存书："<<endl;
		list();
		fout.close();
	}	

void Book::xiu(){
	int i=0,a0,j=0;
	getc();
	string s=code;
	ifstream fin("E:/book.txt",ios::in);
	string temp1,temp2,temp3;
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		i+=3;
		if(temp2==code){
			cout<<"请输入修改后的数量"<<endl;
			char n[]={0};
			cin>>n;
			cout<<"您要修改的是："<<temp1<<' '<<temp2<<endl;
			cout<<"数目更改为： "<<n<<"本"<<endl;
			cout<<"确定：1"<<"取消：2"<<endl;
			cin>>a0;
			if(a0==1){
			modifyContentInFile("E:/book.txt",i,n);
			cout<<"修改成功"<<endl;
			j++;
			break; 
			} 
			else{
				break;
			}
		}
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 	i+=3;
		 }
			
	}
	if(j==0){
		cout<<"输入有误！"<<endl;
	}
	fin.close();	
}
void Book::jie(string c){
	getc();
	int i=0; 
	string temp1,temp2,temp3;
	ifstream fin("E:/book.txt",ios::in);
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		i+=3;
		if(temp2==code){
				istringstream temp(temp3);
				int a;
				temp>>a;
			if(a>0){
				a--;
				char n[100];
				itoa(a,n,10);
				modifyContentInFile("E:/book.txt",i,n);
				ofstream fout("E:/lend.txt",ios::app);
				fout<<c<<endl;
				fout<<getcode(c)<<endl;
				fout<<temp1<<endl;
				fout<<temp2<<endl;
				fout.close();
				cout<<"操作成功！"<<endl;
			}
			else{
				cout<<"库存不足！"<<endl;
			}
		}
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 	i+=3;
		 }	
	}
	fin.close();
}
void Book::huan(string c){
	getc();
	int i=0,j=0,k=0; 
	string temp1,temp2,temp3,temp4,temp5,temp6,temp7;
	ifstream fin("E:/book.txt",ios::in);
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		i+=3;
		if(temp2==code){
				istringstream temp(temp3);
				int a;
				temp>>a;
				a++;
				char n[100];
				itoa(a,n,10);
				modifyContentInFile("E:/book.txt",i,n);
				fin.close();
		}
	}
	else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 	i+=3;
		 }	
		 
		 ifstream fin("E:/lend.txt",ios::in);
				while(getline(fin,temp4)){//操作列表 
				if(temp4!="0"){
				getline(fin,temp5);
				getline(fin,temp6);
				getline(fin,temp7);
				j+=4;
				if(temp7==code&&temp4==c){
					modifyContentInFile("E:/lend.txt",j-3,"0");
					modifyContentInFile("E:/lend.txt",j-2,"0");
					modifyContentInFile("E:/lend.txt",j-1,"0");
					modifyContentInFile("E:/lend.txt",j,"0");
					k++;
					break; 
				}
			}
				else{
					getline(fin,temp5);
					getline(fin,temp6);
					getline(fin,temp7);
					j+=4;
				}
		}
		if(k==0){
			cout<<"输入有误！"<<endl;
		}
		else if(k>0){
			cout<<"操作成功！"<<endl;
		}
		fin.close();
		 
	fin.close();		
	}
}

string charToStr(char *contentChar)//char转string
{
	
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
void modifyContentInFile(char *fileName,int lineNum,char *content)//修改文件 
{	ifstream in;	
	char line[1024]={'\0'};	
	in.open(fileName);	
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
	tempStr+=content;		
	}		
	tempStr+='\n';	
	}	
	in.close();	
	ofstream out;	
	out.open(fileName);	
	out.flush();	
	out<<tempStr;	
	out.close();  
}
void mylend(string c){
	int i=0;
	ifstream fin("E://lend.txt",ios::in);
	string temp1,temp2,temp3,temp4;
	cout<<"目前您的借记状况为："<<endl;
	cout<<"姓名\t"<<"学号\t"<<"书名\t"<<"编号\t"<<endl;
	while(getline(fin,temp1))
		if(temp1!="0"){
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
			if(temp1==c){
					cout<<temp1<<'\t'<<temp2<<'\t'<<temp3<<'\t'<<temp4<<'\t'<<endl;
					i++;
			}
		}
		else{
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
		}	 
	
	if(i==0){
		cout<<"无"<<endl;
	}
	fin.close();
}
void lendlist(){
	int i=0;
	ifstream fin("E://lend.txt",ios::in);
	string temp1,temp2,temp3,temp4;
	cout<<"目前借记状况为："<<endl;
	cout<<"姓名\t"<<"学号\t"<<"书名\t"<<"编号\t"<<endl;
	while(getline(fin,temp1))
		if(temp1!="0"){
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
					cout<<temp1<<'\t'<<temp2<<'\t'<<temp3<<'\t'<<temp4<<'\t'<<endl;
					i++;
		}
		else{
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
		}	 
	
	if(i==0){
		cout<<"无"<<endl;
	}
	fin.close();
}
string getn(string c){
	ifstream fin("E:/book.txt",ios::in);
	string temp1,temp2,temp3;
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		if(temp2==c){
			return temp1;
		}
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 }	
	}
	fin.close();
}

int div1(string c){
	{
	int m=0;
	ifstream fin("E:/book.txt",ios::in);
	string temp1,temp2,temp3;
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		if(temp2==c) {
		m++;
		break;	
		}
		
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 }	
	}
	if(m==0){
		throw 1;
	}
	fin.close();
} 
}
int div2(string c){
	{
	int m=0;
	ifstream fin("E:/book.txt",ios::in);
	string temp1,temp2,temp3;
	while(getline(fin,temp1)){
		if(temp1!="0"){
		getline(fin,temp2);
		getline(fin,temp3);
		if(temp2==c) {
		m++;
		break;	
		}
		
		}
		 else{
		 	getline(fin,temp2);
		 	getline(fin,temp3);
		 }	
	}
	if(m>0){
		throw 1;
	}
	fin.close();
} 
}
int div3(string n,string c){
	int i=0;
	ifstream fin("E://lend.txt",ios::in);
	string temp1,temp2,temp3,temp4;
	while(getline(fin,temp1))
		if(temp1!="0"){
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
			if(temp1==n&&temp4==c){
					i++;
			}
		}
		else{
			getline(fin,temp2);
			getline(fin,temp3);
			getline(fin,temp4);
		}	 
	if(i==0){
		throw 1;
	}
	fin.close();
}

 
 
