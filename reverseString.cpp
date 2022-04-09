#include<iostream>
#include<stack>

using namespace std;

int main() {
    string str = "prince";

    int i = 0;
    stack<char> s1;

    while(i < str.length()) {
        // char ch = s
        s1.push(str[i]);
        i++;
    }

    string ans = "";

    while(!s1.empty()) {
        ans.push_back(s1.top());
        s1.pop();
    }

    cout<<"Reverse string is "<<ans;
    return 0;
}
