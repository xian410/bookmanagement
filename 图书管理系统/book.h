#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Book{
	string name,code;
	int num;
	public:
		Book(string a="0",string b="0",int c=0){
			name=a;
			code=b;
			num=c;
		}
		void setc(string a){
			code=a;
		}
		string getn(){
			return name;
		}
		string getc(){
			return code;
		}
		int getnu(){
			return num;
		}
		void add(Book b);
		string del();
		void xiu();
		void cha();
		void jie(string n);
		void huan(string c1);
		friend ostream & operator<<(ostream &out, Book &obj);	
};
void list();
void mylend(string c); 
void lendlist(); 
string getn(string c); 
int div1(string c); 
int div2(string c);
int div3(string n,string c);  
void modifyContentInFile(char *fileName,int lineNum,char *content);
string charToStr(char *contentChar);
 
