//Approach :- Stack me dalo char ko fir char ke top ko ek empty ans(jab tk stack khali na ho jye) nam k string me le lo for stack ko pop kr do
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str="Anurag ";
    stack<char> s;
    int n =str.length();
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
    cout<<"Reverse Sytack :"<<ans<<endl;
    return 0; 
}