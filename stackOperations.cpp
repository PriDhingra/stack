#include<iostream>

using namespace std;

class Stack {
    public: 
        int *arr;
        int top;
        int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if(top < size - 1) {
            top++;
            arr[top] = data;
        } else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peak() {
        if(top >= 0 && top < size)
            return arr[top];
        else {
            cout<<"Stack is empty";
            return 0;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Stack st(5);

    st.push(22);
    st.push(20);
    st.push(18);
    st.pop();
    st.pop();
    st.pop();
    // st.pop();
    // st.push(22);
    // st.push(20);
    // st.push(101);

    if(st.isEmpty())
        cout<<"Stack is empty";
    else 
        cout<<"Stack is not empty";

    return 0;
}
