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



// Print keypad combinations (To optimize space) :

#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = { ".,","abc","def","ghi","jkl","mno","pqrs","tu","uvx","yz" };

void combination(string inputString,string answer) {

	if (inputString.length() == 0) {
		cout << answer << endl;
		return;
	}

	string substring = inputString.substr(1);
	int index = (int)(inputString[0] - 48);
	string keyseq = keypad[index];
	for (int i = 0; i < keyseq.length(); i++) {
		combination(substring, answer + keyseq[i]);
	}
}


int main() {
	string s;
	string ans = "";
	cin >> s;
	combination(s,ans);
}
