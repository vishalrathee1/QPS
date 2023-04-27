#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Question link : https://leetcode.com/problems/single-number-iii/

int main(){
	//size of array
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}
	int x=0;
	for(int i =0; i<n; i++){
		x^=arr[i];
	}
	int set =0, unset = 0;
	int ct=0;
	while(x){
		if(x & 1) break;
		ct++;
		x>>=1;
	}
	int mask = 1;
	mask<<=ct;
	for(int i = 0; i<n; i++){
		if(arr[i] & mask) set^=arr[i];
		else unset^=arr[i];
	} 

	cout<<endl<<set<<" "<<unset<<endl;
	return 0;
}
