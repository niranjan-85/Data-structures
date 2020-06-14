#include<bits/stdc++.h>
using namespace std;

int precedence(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else
	{
		return 3;
	}
}
void main() {
	stack <char> s;
	string infix = "14/7*3-4+9/2",postfix="";
	char ch;
	for (int i = 0; i < infix.length(); i++) {
		if (s.empty()) { 
			s.push(infix[i]); 
		}
		else if (precedence(s.top()) < precedence(infix[i])) {
			s.push(infix[i]);
		}
		else
		{
			while (!s.empty() && (precedence(infix[i])<=precedence(s.top()))) {
				ch = s.top();
				s.pop();
				postfix += ch;

			}
			s.push(infix[i]);
		}
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	cout << postfix;
}