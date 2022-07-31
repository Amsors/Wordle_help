#include<bits/stdc++.h>
using namespace std;
int n;
string data[20000];
int judge(string s,string o,int sta[]){
	for(int i=0;i<5;i++){
		if(sta[i]==0){
			if(s.find(o[i])!=s.npos){
				return 0;
			}
		}else if(sta[i]==1){
			if(s.find(o[i])==i){
				return 0;
			}
			if(s.find(o[i])==s.npos){
				return 0;
			}
		}else if(sta[i]==2){
			if(s[i]!=o[i]){
				return 0;
			}
		}
	}
	return 1;
}
int check(string ss){
	for(int i=1;i<n;i++){
		if(data[i]==ss){
			return 1;
		}
	}
	return 0;
}
int main(){//0 wrong ; 1 wrong pos ; 2 correct
	int illegal=0;
	int mark[20000];
	for(int i=0;i<20000;i++){
		mark[i]=1;
	}
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
	for(int iii=0;iii<1000;iii++){
		cout<<"round "<<iii+1<<endl;
		cout<<"input guess str : ";
		string guess;
		cin>>guess;
		if(guess=="--end"){
			break;
		}
		cout<<"input status : ";
		int status[5];
		for(int i=0;i<5;i++){
			cin>>status[i];
		}
		for(int i=1;i<n;i++){
			if(mark[i]==0){
				continue;
			}
			if(judge(data[i],guess,status)==0){
				mark[i]=0;
				illegal++;
			}
		}
		for(int i=1;i<n;i++){
			if(mark[i]==1){
				cout<<data[i]<<" ";
			}
		}
		cout<<endl<<"round "<<iii+1<<" total "<<illegal<<" illegal"<<endl;
		cout<<endl;
	}
	return 0;
}
