#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Question link :   https://leetcode.com/problems/permutation-in-string/


int main(){
	string s1="ab", s2 = "eidbaooo";
	vector<int> s1Count(26,0), s2Count(26,0);
	for(int i =0; i<s1.size(); i++){
		s1Count[s1[i]-'a']++;
		s2Count[s2[i]-'a']++;
	}
	int matches = 0;
	for(int i =0; i<26; i++){
		if(s1Count[i]==s2Count[i])
			matches++;
	}
	int left = 0;
	for(int i = s1.size(); i<s2.size(); i++){
		if(matches==26){
			cout<<"True"<<endl;
			break;
		}
		int ind = s2[i]-'a';
		s2Count[ind]++;
		if(s2Count[ind] == s1Count[ind]){
			matches++;
		}
		else if(s2Count[ind] == s1Count[ind]+1){
			matches--;
		}
		ind = s2[left]-'a';
		s2Count[ind]--;
		if(s2Count[ind] == s1Count[ind]){
			matches++;
		}
		else if(s2Count[ind] == s1Count[ind]-1){
			matches--;
		}
		left++;
	}

	if(matches == 26){
		cout<<"True"<<endl;
	}
	else cout<<"False"<<endl;


	return 0;
}
