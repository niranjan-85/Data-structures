#include<bits/stdc++.h>
using namespace std;


vector<string> mazepaths(int sr,int sc,int dr,int dc ) {

	if (sr == dr && sc == dc) {
		vector<string>op;
		op.push_back("");
		return op;
	}
	else if (sr > dr || sc > dc) {
		vector<string>op;
		return op;
	}

	vector<string>path1 = mazepaths(sr+1,sc,dr,dc);
	vector<string>path2 = mazepaths(sr,sc+1,dr,dc);

	vector<string>res;

	for (string x : path1) {
		res.push_back("v" + x);
	}
	for (string x : path2) {
		res.push_back("h" + x);
	}
	
	return res;
}


int main() {
	int sr,sc,dr,dc;
	cin >> sr>>sc>>dr>>dc;
	for (string x : mazepaths(sr,sc,dr,dc)) {
		cout << x << endl;
	}
}