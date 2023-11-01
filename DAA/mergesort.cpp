#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int q, int r){
	int s1=q+1-l, s2=r-q;
	int a1[s1], a2[s2];

	for(int i=l;i<=q;i++){
		a1[i-l]=arr[i];
	}
	for(int i=q+1; i<=r; i++){
		a2[i-q-1]=arr[i];
	}

	int i=0,j=0;
	while(i<s1 && j<s2){
		if(a1[i] <= a2[j])
			arr[l]=a1[i], i+=1;
		else
			arr[l]=a2[j], j+=1;
		l+=1;
	}
	while(i<s1){
		arr[l] = a1[i];
		i+=1;
		l+=1;
	}
	while(j<s2){
		arr[l] = a2[j];
		j+=1;
		l+=1;
	}
}


void mergesort(int arr[], int l, int r){
	if(l >= r)
		return;
	int q=(l+r)/2;
	mergesort(arr, l, q);
	mergesort(arr, q+1, r);
	merge(arr, l, q, r);
}


int main(){
	int n;
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Sorting elements :-)\n";
	mergesort(arr, 0, n-1);
	cout<<"Elements in sorted order are : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
