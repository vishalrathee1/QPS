#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main(){
	string s="ADOBECADEBAND", t = "ABC";

	//creating map
	unordered_map<char, int> m;
	//creating a map for t
	for(int i =0; i<t.size(); i++){
		m[t[i]]++;
	}
	//chars required for matching
	int req = t.size();
	int i = 0, j =0;
	int left =0, minLen = INT_MAX;

	while(j<s.size()){
		//req reduced
		if(m[s[j]]>0) req--;
		//updated map
		m[s[j]]--;
		//moved right pointer
		j++;
		while(req == 0){
			//checking ans length
			if(j-i<minLen){
				left = i;
				minLen = j-i;
			}
			//adding removed value in map
			m[s[i]]++;
			if(m[s[i]]>0)
				req++;
			//moving left pointer
			i++;
		}
	}
	if(minLen != INT_MAX){
		cout<<s.substr(left, minLen)<<" ";
	}
	else cout<<"Not Found"<<endl;

	return 0;
}
