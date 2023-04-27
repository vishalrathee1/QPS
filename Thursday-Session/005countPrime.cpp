#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Question link  :  https://leetcode.com/problems/count-primes/

bool sieve[100001];
int N=100000;
void fillSieve(){
	int i = 0;

	for(int i =2; i<=N; i++){
		sieve[i]=1;
	}

	//filling sieve
	for(i=2;i*i<=N;i++){
		//checking if i is prime or not
		if(sieve[i] == 1){
			i=i*i;
			//marking all multiples of i as non primes
			while(i<=N){
				sieve[i]=0;
				i+=i;
			}
		}
	}
}


int main(){
	//size of array
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}
	
	return 0;
}
