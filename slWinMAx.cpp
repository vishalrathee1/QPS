#include <deque>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n;
	cin>>k;
	int arr[n];
	for(int i =0; i<n ; i++){
		cin>>arr[i];
	}
	//index store of decreasing elements from left to right
	deque<int> q;
	int ans[n];
	for(int i =0; i<n; i++){
		//i-k>q.front()
		if(i-k==q.front()) q.pop_front();
		while(!q.empty() && arr[q.back()]<=arr[i]){
			q.pop_back();
		}
		q.push_back(i);
		if(i>=k-1){
			ans[i-k+1] = arr[q.front()];
		}

	}
	cout<<endl;
	for(int i =0; i<n-k+1; i++){
		cout<<ans[i]<<'\t';
	}

	return  0;
}
