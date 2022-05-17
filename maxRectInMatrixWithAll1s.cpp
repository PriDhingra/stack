// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
    vector<int> nextSmallest(int *M, int n) {
        vector<int> arr(n);
    
        stack<int> s;
        s.push(-1);
        
        for(int i = n - 1;i >= 0;i--) {
            while(s.top() != -1 && M[s.top()] >= M[i]) {
                s.pop();
            }
            arr[i] = s.top();
            s.push(i);
        }
        
        return arr;
    }
    
    vector<int> prevSmallest(int *M, int n) {
        vector<int> arr(n);
    
        stack<int> s;
        s.push(-1);
        
        for(int i = 0;i < n;i++) {
            while(s.top() != -1 && M[s.top()] >= M[i]) {
                s.pop();
            }
            arr[i] = s.top();
            s.push(i);
        }
        
        return arr;
    }
    
    int largestRectangle(int* M, int n) {
        vector<int> next(n);
        next = nextSmallest(M, n);
        vector<int> prev(n);
        prev = prevSmallest(M, n);
        
        int maxi = INT_MIN;
        
        for(int i = 0;i < n;i++) {
            int length = M[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            
            int width = next[i] - prev[i] - 1;
            
            maxi = max(maxi, length * width);
        }
        
        return maxi;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxi = largestRectangle(M[0], m);
        
        for(int i = 1;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(M[i][j] != 0) {
                    M[i][j] = M[i][j] + M[i - 1][j];
                } else {
                    M[i][j] = 0;
                }
            }
            
            maxi = max(maxi, largestRectangle(M[i], m));
        }
        
        return maxi;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
