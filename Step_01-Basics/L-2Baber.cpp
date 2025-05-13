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
