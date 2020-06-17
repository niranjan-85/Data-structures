#include<bits/stdc++.h>
using namespace std;

// precedences should be defined for each operator.
// however the precedence for ')' should be lowest.
int precedence(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else if(x=='^')
	{
		return 3;
	}
	else
	{
		return -1;
	}
}
void main() {
	stack <char> s;
	string infix = "a+b*(c^d-e)^(f+g*h)-i",postfix="";
	char ch;
	for (int i = 0; i < infix.length(); i++) {
		// if our expression has an operand, append it to our string.
		// else if it equals '(', we will push it into the stack.

		if (infix[i] == '(') {
			s.push(infix[i]);
		}

		// if our expression has an operator :

		else if (infix[i]=='+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			// first check precedences, if it is high, push it into the stack.
			// else pop the element and add into the string. (keep doing this till there exists an element with higher precedence present)
			while (!s.empty()  &&  precedence(infix[i]) <= precedence(s.top())) {
				ch = s.top();
				s.pop();
				postfix += ch;
			}
			s.push(infix[i]);
		}

		// if our expression has ')' then it should match "(".
		else if (infix[i] == ')') {
			while (s.top() != '(' && !s.empty()) {
				ch = s.top();
				s.pop();
				postfix += ch;
			}s.pop();
		}
		else{
			postfix += infix[i];
		}
	}
	//empty the stack.
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	cout << postfix;
}