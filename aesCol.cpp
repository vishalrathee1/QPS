#include <iostream>
#include<bits/stdc++.h>	
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n ; i++){
		cin>>arr[i];
	}
	stack<int> st;
	for(int i = 0; i<n; i++){
		if(st.empty() == true || arr[i]>0){
			st.push(arr[i]);
		}
		else{
			int flag=0;
			while(!st.empty() && st.top()>0){
				int temp = arr[i] + st.top();
				if(temp<0){
					st.pop();
					if(st.empty() == true){
						st.push(arr[i]);
						flag = 1;
						break;
					}
				}
				else if(temp == 0){
					st.pop();
					flag = 1;
					break;
				}
				else {
					flag = 1;
					break;
				}
			}
			if(flag == 0){
			st.push(arr[i]);}
		}
	}
	vector<int> ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
