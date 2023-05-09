#include <climits>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int x = 1147483649;
	int rev = 0;
	int flag = 0;
	while(x){
		int temp = x%10;
		x/=10;
		if(rev>INT_MAX/10 || (rev == INT_MAX/10 && temp>7)){
			cout<<"0"<<endl;
			flag = 1;
			break;
		}
		if(rev<INT_MIN/10 || (rev == INT_MIN/10 && temp < -8)){
			cout<<"0"<<endl;
			flag = 1;
			break;
		}
		rev=rev*10 + temp;
	}
	if(flag == 0)
		cout<<rev<<endl;


	return 0;
}
