#include <climits>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Question link : https://leetcode.com/problems/largest-rectangle-in-histogram/ 

int main(){
	//size of array
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}

	stack<int> st;
	int ans=INT_MIN;
	int l_e[n];
	int r_e[n];
	//filling left extension
	for(int i =0; i<n; i++){
		while(!st.empty() && arr[st.top()]>=arr[i]){
			st.pop();
		}

		if(st.empty() == true) l_e[i] = 0;
		else l_e[i] = st.top()+1;
		st.push(i);
	}
	while(!st.empty()) st.pop();

	//filling right extension
	
	for(int i = n-1; i>=0; i--){
		
		while(!st.empty() && arr[st.top()]>=arr[i]){
			st.pop();
		}
		if(st.empty() == true) r_e[i] = n;
		else r_e[i] = st.top();
		st.push(i);
	}
	cout<<endl;
	for(int i =0; i<n ; i++){
		ans = max(ans, ((r_e[i] - l_e[i] )*arr[i]));
	}
	for(int i =0; i<n ; i++){
		cout<<l_e[i]<<" "<<r_e[i]<<endl;
	}
	cout<<ans;

	ans = 0;

	//using only stack no array
	stack<pair<int,int>> st2;
	cout<<endl;
	for(int i =0; i<n; i++){
		int ind = i;
		while(!st2.empty() && arr[st2.top().first]>=arr[i]){
			//pop but before we have to store its contributing area
			int w = i-st2.top().first;
			int h = st2.top().second;
			cout<<h<<w<<endl;
			ans = max(ans, h*w);
			ind = st2.top().first;
			st2.pop();
		}
		st2.push({ind, arr[i]});
	}

	while(!st2.empty()){
		int w = n-st2.top().first;
		int h = st2.top().second;
		cout<<h<<" "<<w<<endl;
		ans = max(ans, h*w);
		st2.pop();
	}

	cout<<endl<<ans<<endl;

	
	return 0;
}
