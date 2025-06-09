#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr,int n){
    stack<int> s; //ek stack bna lete  h 
    s.push(-1);//pahle se -1 dal do
    vector<int> ans(n);// ek answer nam ka vector bna lo
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}
int main() {
    vector<int> arr = {2, 1, 4, 3};
    int n = 4; 
    vector<int> result = nextSmallerElement(arr, n);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}