/*
#include<iostream> 
#include<stack> 
using namespace std;
void sortedInsert(stack<int> &stack, int num){
    //base case
    if(stack.empty() || (!stack.empty()  && stack.top()<num)){
        stack.push(num);
        return;
    }
    int n=stack.top();//side me rkho aur pop kr do
   stack.pop(); 
   //recursive call
   sortedInsert(stack,num);
   stack.push(n);

}
void sortStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return ;
    }
    //top wale element ko sise me rkh dena 
    int num=stack.top();
    stack.pop();
    //recussive call mar do
    sortStack(stack);
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
*/
//Approach is stack-> arr-> sort array using STL
#include<iostream> 
#include<stack> 
#include<vector>
#include<algorithm>
using namespace std;
void sortStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }
    //stack ko array me convert kro
    vector<int> arr;
    while(!stack.empty()){
        arr.push_back(stack.top());
        stack.pop();
    }
    //sort kr do array ko 
    sort(arr.begin(),arr.end());
    //again convert arr to stack
    for(int i=0;i<arr.size();i++){
        stack.push(arr[i]);
    }
}
int main() {
    stack<int> s;
    
    // Add elements to the stack
    s.push(40);
    s.push(10);
    s.push(30);
    s.push(20);
    
    cout << "Stack before sorting (top to bottom): ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Sort the stack
    sortStack(s);

    cout << "Stack after sorting (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}