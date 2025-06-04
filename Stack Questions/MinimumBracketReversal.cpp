#include<iostream>
#include<stack>
#include<string>
using namespace std;
int findMinimumCost(string str) {
    // If the length of the string is odd, it's impossible to balance
    if (str.length() % 2 != 0) {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];  // Declare ch here

        if (ch == '{') {
            s.push(ch);
        } else {
            // ch is ')'
            if (!s.empty() && s.top() == '{') {
                s.pop();  // valid pair
            } else {
                s.push(ch);  // unbalanced ')'
            }
        }
    }

    // Now the stack has only unbalanced brackets
    int a = 0, b = 0;//left parenthesis and right parentehsis

    while (!s.empty()) {
        if (s.top() == '}') {
            a++;
        } else {
            b++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string test1 = "{{{{}}"; // Example input
    string test2 = "{{{{}}}}"; // Example input
    string test3 = "}{{}}{{{"; // Example input

    cout << "Minimum reversals for \"" << test1 << "\": " << findMinimumCost(test1) << endl;
    cout << "Minimum reversals for \"" << test2 << "\": " << findMinimumCost(test2) << endl;
    cout << "Minimum reversals for \"" << test3 << "\": " << findMinimumCost(test3) << endl;

    return 0;
}