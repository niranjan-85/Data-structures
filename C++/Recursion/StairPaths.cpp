#include<bits/stdc++.h>
using namespace std;


vector<string> stairpaths(int n) {

	if (n == 0) {
		vector<string>op;
		op.push_back("");
		return op;
	}
	else if (n < 0) {
		vector<string>op;
		return op;
	}
	
	vector<string>s1 = stairpaths(n - 1);
	vector<string>s2 = stairpaths(n - 2);
	vector<string>s3 = stairpaths(n - 3);

	vector<string>res;

	for (string x : s1) {
		res.push_back(x + "1");
	}
	for (string x : s2) {
		res.push_back(x + "2");
	}
	for (string x : s3) {
		res.push_back(x + "3");
	}

	return res;
}


int main() {
	int n;
	cin >> n;
	for (string x : stairpaths(n)) {
		cout << x << endl;
	}
}





// print stair paths ( To optimize space )






#include<bits/stdc++.h>
using namespace std;


void stairpaths(int n,string answer) {

	if (n == 0) {
		cout << answer << endl;
		return;
	}
	else if (n < 0) {
		return;
	}

	stairpaths(n - 1, answer + char(49));
	stairpaths(n - 2, answer + char(50));
	stairpaths(n - 3, answer + char(51));
	
}


int main() {
	int n;
	string ans = "";
	cin >> n;
	stairpaths(n,ans);
}
