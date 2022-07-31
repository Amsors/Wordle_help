#include<bits/stdc++.h>
using namespace std;
int n;
string data[20000];
int check(string ss){
	if(ss.length()!=5){
		cout<<"invalid input !\n";
		cout<<"please try again : ";
		return 0;
	}
	for(int i=1;i<n;i++){
		if(data[i]==ss){
			return 1;
		}
	}
	cout<<"invalid input !\n";
	cout<<"please try again : ";
	return 0;
}
int main(){
	n=1;
	string tmp;
	ifstream fin("dataset111.txt");
	while(fin>>tmp){
		if(tmp=="--end"){
			break;
		}
		data[n]=tmp;
		n++;
	}
	fin.close();
	cout<<"successfully input strings "<<n-1<<" in total\n";
	srand((unsigned)time(0));
	int wtf=rand();
	int num=rand()%(n-1)+1;
	cout<<"word num is "<<num<<endl;
//	cout<<"word is "<<data[num]<<endl;
	string word=data[num];
	for(int i=1;i<10000;i++){
		cout<<"round "<<i<<endl;
		cout<<"guess word is : ";
		do{
			cin>>tmp;
			if(tmp=="--end"){
				return 0;
			}
		}while(check(tmp)==0);
		int success=0;
		for(int i=0;i<5;i++){
			if(tmp[i]==word[i]){
				cout<<2<<" ";
				success++;
			}else if(word.find(tmp[i])!=word.npos){
				cout<<1<<" ";
			}else cout<<0<<" ";
		}
		cout<<endl<<endl;
		if(success==5){
			cout<<"you win in round "<<i;
			cout<<endl<<endl<<"press any key to exit"<<endl;
			char exi;
			cin>>exi;
			return 0;
		} 
	}
	return 0;
}
