#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    //pop 
    st.pop();
    cout<<"printing top element: "<< st.top()<<endl;
    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Size of stack is "<<st.size()<<endl;
    return 0;
}