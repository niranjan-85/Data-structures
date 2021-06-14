#include<bits/stdc++.h>
using namespace std;

string a[10] = { "??","abc","def","ghi","jkl","mnop","qrst","uv","wxyz",",;" };

vector<string> gets(int i,int n,string s) {
	if (i>n) {
		vector<string>output;
		output.push_back("");
		return output;
	}
	vector<string>main_arr=gets(i + 1, n, s);
	vector<string>res;
	for (char x : a[(int)s[i] - 48]) {
		for (int i = 0; i < main_arr.size(); i++) {
			res.push_back(x + main_arr[i]);
		}
	}
	return res;
}


int main() {
	string s;
	cin >> s;
	for (string x : gets(0,s.length()-1,s)) {
		cout << x <<endl;
	}
}