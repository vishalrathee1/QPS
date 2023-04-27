#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	//size of array
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}
	int m=1;
	m<<=n;
	vector<vector<int>> ds;
	for(int i =1; i<=m; i++){
		vector<int> temp;
		for(int bit = 1; bit<=n; bit++){
			if((i-1)&(bit-1)){
				temp.push_back(arr[bit-1]);
			}
		}
		ds.push_back(temp);
	}
	
	for(int i =0; i<m; i++){
		for(int j =0; j<ds[i].size(); j++){
			cout<<ds[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
