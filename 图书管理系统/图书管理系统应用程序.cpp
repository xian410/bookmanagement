#include <iostream>
#include <cstring>
#include<fstream>
#include"book.h"
#include"menu.h"
#include"user.h"
using namespace std; 
int div0(int c){
	if(c!=1&&c!=2&&c!=3)
		throw c;
}
int main(){
	while(1){
	menu11();
	int n1;
	string m1,m2;
	cin>>n1;
	try{
		div0(n1);
	}
	catch(int){
		cout<<"输入有误！"<<endl;
	}
	switch(n1){
		case 1:{//以学生身份登录 
		m1=slogin(); 
		if(m1!="0"&&m1!="-1"){
		while(1){
			menu21();
			int a1;
			cin>>a1;
			switch(a1){
				case 1:{//查看图书列表 
					list();
					break;
				}
				case 2:{//借阅图书 
					list(); 
					Book b1;
					string a1;
					int a0;
					cout<<"借阅图书"<<endl; 
					cout<<"请输入你要借阅图书的编号"<<endl;
					cin>>a1;
					try{
						div1(a1);
					}
					catch(int){
						cout<<"此书不存在"<<endl;
						break;
					}
					cout<<"您要借阅的是："<<getn(a1)<<endl;
					cout<<"确定：1"<<"取消：2"<<endl;
					cin>>a0;
					if(a0==1){
					b1.setc(a1);
					b1.jie(m1);
					}
					;
			
					break;
				}
				case 3:{//归还图书 
					mylend(m1); 
					int a0;
					Book b1;
					string a1;
					cout<<"归还图书"<<endl; 
					cout<<"请输入你要归还图书的编号"<<endl;
					cin>>a1;
					try{
						div3(m1,a1);
					}
					catch(int){
						cout<<"此书不存在"<<endl;
						break;
					}
					cout<<"您要归还的的是："<<getn(a1)<<endl;
					cout<<"确定：1"<<"取消：2"<<endl;
					cin>>a0;
					if(a0==1)
					{
					b1.setc(a1);
					b1.huan(m1); 
					}
					
					break;
				} 
				case 4:{ //查看借记记录 
					mylend(m1); 
					break;
				}	 
				case 5:{
					schange(m1);
					break;
				} 
			}
			if(a1!=0&&a1!=1&&a1!=2&&a1!=3&&a1!=4&&a1!=5){
				cout<<"输入有误！"<<endl;
			} 
			if(a1==0)
			break; 
		}				
	}
	break;
		}
		case 2:{//以管理员身份登录 
		m2=mlogin(); 
		if(m2!="0"&&m2!="-1"){
			while(1){
			menu22();
			int a2;
			cin>>a2;
		switch(a2){
			case 1:{
				list();
				break;
			}
			case 2:{//增加图书 
				int a0;
				cout<<"增加操作"<<endl;
				cout<<"当前存书："<<endl;
				list();
				string s1,s2;int s3;
				cout<<"请输入书名"<<endl;
				cin>>s1;
				cout<<"请输入编号"<<endl;
				cin>>s2;
				cout<<"请输入数量"<<endl;
				cin>>s3;
				try{
					div2(s2);
				}
				catch(int){
					cout<<"此书已存在"<<endl;
					break;
				}
				cout<<"您要增加的的是："<<s1<<' '<<s2<<' '<<s3<<"本"<<endl;
				cout<<"确定：1"<<"取消：2"<<endl;
				cin>>a0;
				if(a0==1){
				Book b1(s1,s2,s3);
				b1.add(b1);	
				}
				cout<<"当前存书："<<endl;
				list(); 
				break;
			}
			case 3:{//删除图书 
				int a0;
				cout<<"删除操作"<<endl;	
				cout<<"当前存书："<<endl;
				list();
				Book b1;
				string s2;
				cout<<"请输入指定图书编号"<<endl;
				cin>>s2;
				try{
						div1(s2);
					}
					catch(int){
						cout<<"此书不存在"<<endl;
						break;
					}
				cout<<"您要删除的的是："<<getn(s2)<<' '<<s2<<endl;
				cout<<"确定：1"<<"取消：2"<<endl;
				cin>>a0;
				if(a0==1){
				b1.setc(s2);
				b1.del();
				}
				
				break;
			}
			case 4:{//修改图书 
				cout<<"修改操作"<<endl;	
				cout<<"当前存书："<<endl;
				list();
				Book b1;
				string s2;
				cout<<"请输入指定图书编号"<<endl;
				cin>>s2;
				try{
						div1(s2);
					}
					catch(int){
						cout<<"此书不存在"<<endl;
						break;
					}
				b1.setc(s2);
				b1.xiu();
				cout<<"当前存书："<<endl;
				list();
				break;
			} 
			case 5:{//查看借记列表 
				 lendlist(); 
				break;
			} 
			case 6:{
				mchange(m2);
				break;
			}
		}
		if(a2!=0&&a2!=1&&a2!=2&&a2!=3&&a2!=4&&a2!=5&&a2!=6){
				cout<<"输入有误！"<<endl;
			}
		if(a2==0)
			break; 
	}
		break;
		}
		break;
	}
		case 3:{//注册 
				menu12();
				int n2;
				
				
				cin>>n2;
				if(n2==1){
					srigister();
				}
				else if(n2==2){
					mrigister();
				}
				else{
					cout<<"输入有误"<<endl;
				break;
				}
				
		}
		case 0:{
			cout<<"谢谢使用"<<endl;
			exit(0);
			break;
		}
		
	} 
	}
}

 
 

