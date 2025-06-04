#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x) {
    // Base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    
    // Recursive case
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
}