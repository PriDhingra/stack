#include<stack>

int findMinimumCost(string str) {
  // Write your code here
	if(str.length() % 2 == 1)
		return -1;
	
	stack<char> st;
	
	for(int i = 0;i < str.length();i++) {
		char ch = str[i];
		if(ch == '{') {
			st.push(ch);
		} else {
			if(!st.empty()) {
				char top = st.top();
				if(top == '{') {
					st.pop();
				} else {
					st.push(ch);
				}
			} else {
				st.push(ch);
			}
		}
	}
	
	int a = 0;
	int b = 0;
	while(!st.empty()) {
		if(st.top() == '{') {
			b++;
		} else {
			a++;
		}
		st.pop();
	}
	int ans = (a + 1)/2 + (b + 1)/2;
	return ans;
}
