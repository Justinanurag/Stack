/*
// reverse a string using stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str="Anurag";
    stack<char> s;
    int n=str.length();
    for(int i=0;i<n;i++){
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"Reverse of string is "<<ans<<endl;
    return 0;
}*/
/*
// Delete middle element of a stack
#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &inputStack,int count,int size){
    //base case
    if(count==size/2){
        inputStack.pop();
        return;
    }
    //Ek num ban leta hu jisme top element ko store karunga
    int num=inputStack.top();
    inputStack.pop();
    //recurssive call krunga
    solve(inputStack,count+1,size);
    //wapas top wale element ko push kr deta 
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
    int count=0;
    solve(inputStack,count,N);
}
int main() {
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    
    int N = inputStack.size();
    cout << "Original stack size: " << N << endl;
    
    deleteMiddle(inputStack, N);
    
    cout << "Stack after deleting middle element: ";
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;
    
    return 0;
}
*/
/*
//Valid Parentesis
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // If closing bracket, check for matching opening
        else {
            if (!st.empty()) {
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false; // closing bracket but stack is empty
            }
        }
    }

    return st.empty(); // stack should be empty if balanced
}
int main() {
    string str = "{[()]}";
    if (isValidParenthesis(str)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
*/
// Insert element at bottom of stack
/*
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x) {
    // Base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    // Recursive case
    int num = s.top();
    s.pop();

    solve(s, x);

    // Push the element back after recursive call
    s.push(num);
}

stack<int> pushAtBottom(stack<int>&s, int x) {
    solve(s, x);
    return s;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s = pushAtBottom(s, 4);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}*/

// Reverse the stack recurssion
#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &s, int x) {
    // Base case
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Remove the top element
    int num = s.top();
    s.pop();

    // Recursive call to insert x at the bottom
    insertAtBottom(s, x);

    // Push the previous top element back
    s.push(num);
}
/*
// Function to reverse a stack using recursion
void reverseStack(stack<int> &s) {
    // Base case
    if (s.empty()) {
        return;
    }

    // Remove the top element
    int num = s.top();
    s.pop();

    // Recursive call to reverse the rest of the stack
    reverseStack(s);

    // Insert the removed element at the bottom
    insertAtBottom(s, num);
}

int main() {
    stack<int> s;

    // Pushing elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

// Reverse the stack
reverseStack(s);

// Print the reversed stack
cout << "Reverse is : " << endl;
while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
}

    return 0;
}
*/


// Sort a stack using recursion
#include<iostream>
#include<stack>
using namespace std; 
void sortedInsert(stack<int> &stack,int num){
    if(stack.empty()|| stack.top()<=num){
        stack.push(num);
        return;
    }
    int n=stack.top();
    stack.pop();
    //Recursive call
    sortedInsert(stack,num);
    stack.push(n);
}
void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    //Recuersive call
    sortStack(stack);
    //wapas ate time sorted stack ko insert karna hai
    sortedInsert(stack,num);
}
int main(){
    stack<int> stack;
    stack.push(3);
    stack.push(5);
    stack.push(1);
    stack.push(4);
    stack.push(2);
    sortStack(stack);
    cout<<"Sorted stack is : "<<endl;
    while(!stack.empty()){
        cout<<stack.top()<<endl;
        stack.pop();
    }
    return 0;
}