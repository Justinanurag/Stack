/*
//Brute force Approch

#include <iostream>
#include <stack>
#include <vector>  
using namespace std;

void reverseStack(stack<int> &st) {
    vector<int> temp;
    // Pop all elements from stack and store in vector
    while(!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    } 
    // Push elements back to stack from vector
    for(int i=0;i<temp.size();i++) {
        st.push(temp[i]);
    }
}

int main() {
    stack<int> st;
    // Add test data
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << "Original stack (top to bottom): ";
    // Create a copy to print original stack
    stack<int> temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    
    reverseStack(st);
    
    cout << "Reversed stack (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}*/
//Recrsive approach
#include <iostream>
#include <stack> 
using namespace std;

void reverseStack(stack<int> &st) {

}

int main() {
    stack<int> st;
    // Add test data
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << "Original stack (top to bottom): ";
    // Create a copy to print original stack
    stack<int> temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    
    reverseStack(st);
    
    cout << "Reversed stack (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}