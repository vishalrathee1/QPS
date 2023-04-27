#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//question link  :   https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

int main(){
	//size of array
	int n,m;
	cin>>n>>m;

	int x = n^m;

	//count set bits in x 
	
	int ct=0;
	while(x){
		if(x&1) ct++;
		x>>=1;
	}

	cout<<ct<<endl;


	
	return 0;
}
