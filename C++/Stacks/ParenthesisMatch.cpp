#include<bits/stdc++.h>
using namespace std;
void main() {
	stack <char> s;
	bool flag=1;
	string a = "(((a+b)))*)(a-b))";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') {
			s.push(a[i]);
		}
		else if (a[i] == ')') {
			if (!s.empty()) {
				s.pop();
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	flag ? cout << "Matching paranthesis" : cout << "Wrong expression";
}