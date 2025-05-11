/*#include<iostream>
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
}*/

#include<iostream>
#include<stack>
using namespace std;
class Stack{
    //Properties
    public:
    int *arr;
    int size;
    int top;
    //Constructor
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    //Push
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    };
    //pop
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is Empty i.e UnderFlow"<<endl;
        }

    }
    //peek
    int peek(){
         if(top>=0){
             return arr[top];
         }
         else{
            cout<<"Stack is empty"<<endl;
            return -1;
         }

    }
    //Check for empty
    bool isEmpty(){
        if(top==-1){
            return true;
        }
       else{
        return false;
       }
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<"After poping one element the peek element is : "<<st.peek()<<endl;
    st.pop();
    cout<<"After poping one element the peek element is : "<<st.peek()<<endl;
    st.pop();
    cout<<"After poping one element the peek element is : "<<st.peek()<<endl;
    return 0;
}