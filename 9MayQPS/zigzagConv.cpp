#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string s = "PAYPALISHIRING";
	int n = 3;

	string res="";

	for(int i =0; i<n; i++){
		//toprow
		//bottom row
		int inc =(n-1)*2;
		for(int j = i; j<s.size(); j+=inc){
			res+=s[j];
			//inbetween characters left
			//(n-i-1)*2
			if(i>0 && i<n-1 && j+(n-i-1)*2 < s.size()){
				res+=s[j+(n-i-1)*2];
			} 
		}
	}
	cout<<res<<endl;

	return 0;
}
