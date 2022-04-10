bool isValidParenthesis(string expression)
{
	stack<char> s;
    int i = 0;
	
	while(i < expression.length()) {
		char ch = expression[i];
		if(ch == '[' || ch == '(' || ch == '{') {
			s.push(ch); 
		} else {
			if(!s.empty()) { 
				char top = s.top();
				if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
					s.pop();
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		i++;
	}
	
	if(s.empty()) {
		return true;
	} else {
		return false;
	}
}
