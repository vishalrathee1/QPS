#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int nums[n];
	for(int i =0; i< n; i++){
		cin>>nums[i];
	}

	stack<int> st;
	int ans[n];

	for(int i = 2*n-1; i>=0; i--){
		while(!st.empty() && st.top()<=nums[i%n]){
			st.pop();
		}
		if(i<n){
			if(!st.empty()) ans[i] = st.top();
			else ans[i] = -1;
		}
		st.push(nums[i%n]);
	}

	for(int i = 0; i<n; i++){
		cout<<ans[i]<<endl;
	}

	return 0;

}
