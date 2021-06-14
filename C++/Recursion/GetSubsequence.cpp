#include<bits/stdc++.h>
using namespace std;

vector<string> gets(int i,int n,string s) {
	if (i>n) {
		vector<string>output;
		output.push_back(" ");
		return output;
	}
	vector<string>main_arr=gets(i + 1, n, s);
	vector<string>res;
	for (string x : main_arr) {
		res.push_back("" + x);
	}
	for (string x : main_arr) {
		res.push_back(s[i] + x);
	}

	return res;
}


int main() {
	int n;
	cin >> n;
	for (string x : gets(n)) {
		cout << x <<endl;
	}
}