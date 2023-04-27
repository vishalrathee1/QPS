#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>> n;
	int arr[n];
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}
	int ans[n];
	stack<pair<int,int>> st;
	for(int i = 0; i<n ; i++){
		int ct = 1;
		while(!st.empty() && st.top().first <= arr[i]){
			ct += st.top().second;
			st.pop();
		}
		ans[i] = ct;
		st.push({arr[i],ct});
	}

	for(int i =0; i<n ; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
