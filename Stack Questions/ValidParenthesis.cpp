#include<iostream> 
#include<stack>
using namespace std;
bool isvalidParenthesis(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        //if open bracket ,push to stack
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        //if closing bracket ,check for matching opening bracket
        else{
            if(!s.empty()){//check for empty stack
                char top=s.top();
                if((ch == ')' && top == '(') || (ch=='}' && top=='{')||(ch==']' && top == '[')){
                    s.pop();
                } else{
                    return false;
                }
            } else{
                false;
            }
        }
    }
    return s.empty(); //should be empty if balanced

}
int main() {
    string str = "{[()]}";
    if (isvalidParenthesis(str)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}