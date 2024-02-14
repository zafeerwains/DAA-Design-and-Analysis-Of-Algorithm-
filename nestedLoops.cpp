#include<iostream>
using namespace std;
int main (){
	cout<<" First Nested Loop \n";
	for(int i=0 ;i<5;i++){
		for(int j=1 ;j<=5-i;j++){
			cout<<" "<<j;
	}
	cout<<endl;
	}
	cout<<"\n Second Nested Loop \n";
	for(int i=0 ;i<5;i++){
		for(int j=1 ;j<=1+i;j++){
			cout<<" "<<j;
	}
	cout<<endl;
	}
	
		cout<<"\n Third Nested Loop \n";
		
		for(int i=5 ;i>=1;i--){
		for(int j=i;j>0;j--){
			cout<<" "<<j;
	}
	cout<<endl;
	}
	
		cout<<"\n Fourth Nested Loop \n";
		
		for(int i=4 ;i>=0;i--){
		for(int j=5 ;j>=5-i;j--){
			cout<<" "<<j;
	}
	cout<<endl;
	}
		cout<<"\n Fifth Nested Loop \n";
		
		for(int i=0 ;i<=4;i++){
		for(int j=1 ;j<=5-i;j++){
			cout<<" "<<j+i;
	}
	cout<<endl;
	}
	
		cout<<"\n Sixth Nested Loop \n";
		for(int i=0 ;i<5;i++){
		for(int j=1 ;j<=5;j++){
			cout<<" "<<j;
	}
	cout<<endl;
	}
}
