#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

// Function to find indexes of next smaller element to the right
vector<int> nextSmallerElement(const vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);  // base case for no smaller element
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        while(s.top() != -1 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top(); // index of next smaller element
        s.push(i);
    }
    return ans;
}

// Function to find indexes of previous smaller element to the left
vector<int> prevSmallerElement(const vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        while(s.top() != -1 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top(); // index of previous smaller element
        s.push(i);
    }
    return ans;
}

// Function to calculate largest rectangle area in histogram
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int height = heights[i];

        // if there is no smaller to the right, treat as n
        if(next[i] == -1) {
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// Main function
int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << result << endl;  // Expected Output: 10
    return 0;
}
