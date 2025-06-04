#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            st.push(ch);
        } else if (ch == ')') {
            bool isOperator = false;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/' || top == '%') {
                    isOperator = true;
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // remove '('

            if (!isOperator) return true; // redundant
        }
    }

    return false; // no redundant brackets
}

int main() {
    string expr;
    getline(cin, expr);  // read full expression
    cout << (findRedundantBrackets(expr) ? "true" : "false") << endl;
    return 0;
}
