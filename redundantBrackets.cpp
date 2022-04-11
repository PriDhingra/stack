#include<stack>

bool findRedundantBrackets(string &s)
{
    // Write your code here.
	stack<char> st;
	
	for(int i = 0;i < s.length();i++) {
		if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			char ch = s[i];
			st.push(ch);
		} else {
			if(s[i] == ')') {
				bool isRedundant = true;
				while(st.top() != '(') {
					char top = st.top();
					if(top == '+' || top == '-' || top == '*' || top == '/') {
						isRedundant = false;
					}
					st.pop();
				}
				if(isRedundant == true) {
					return true;
				} 
				st.pop();
			}
			
		}
	}
	return false;
}
