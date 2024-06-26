#include<iostream>
using namespace std;
void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
void heapify(int A[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right =2*i+2;
	if(left<n&& A[left]>A[largest]){
		largest = left;
	}
	
	if(right<n&& A[right]>A[largest]){
		largest = right;
	}
	if(largest!=i){
		swap(A[i],A[largest]);
		heapify(A,n,largest);
	}
}
void heapsort(int A[],int n){
	for (int i=n/2-1;i>=0;i--){
		heapify(A,n,i);
	
	}
		printArray(A,n);
	for(int i=n-1;i>=0;i--){
		swap(A[0],A[i]);
		heapify(A,i,0);
//		printArray(A,n);
	}
}


int main(){
	int A[]={1,12,9,5,6,10};
	int n=6;
	heapsort(A,n);
	cout<<"After Sorting\n";
	printArray(A,n);
}

