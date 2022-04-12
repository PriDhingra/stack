#include<stack>

vector<int> nextSmallest(vector<int> &heights) {
	stack<int> s;
	s.push(-1);
	vector<int> ans(heights.size());
	
	for(int i = heights.size() - 1;i >= 0;i--) {
		int curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr) {
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	
	return ans;
} 

vector<int> prevSmallest(vector<int> &heights) {
	stack<int> s;
	s.push(-1);
	vector<int> ans(heights.size());
	
	for(int i = 0;i < heights.size();i++) {
		int curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr) {
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	
	return ans;
} 

int largestRectangle(vector < int > & heights) {
   // Write your code here.
	int n = heights.size();
	
	vector<int> next(n);
	next = nextSmallest(heights);
	
	vector<int> prev(n);
	prev = prevSmallest(heights);
	
	int area = -999999;
	
	for(int i = 0;i < n;i++) {
		int l = heights[i];
		
		if(next[i] == -1) {
			next[i] = n;
		}
		int b = next[i] - prev[i] - 1;
		
		int newArea = l * b;
		
		area = max(newArea, area);
	}
	return area;
 }
