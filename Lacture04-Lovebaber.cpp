//Questio N -stack in array
#include<iostream>
class NStack
{
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freeSpot; 
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        //initilaze top
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        //initalisze next
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        //Update last index value to -1;
        next[s-1]=-1;
        //Initilaize free spot
        freeSpot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow 
        if(freeSpot==-1){
            return false;
        }
        //find index
        int index=freeSpot;
        //Update freeSpot
        freeSpot=next[index];
        //insert element into array
        arr[index]=x;
        //update next
        next[index]=top[m-1];
        //update top
        top[m-1]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if(top[m-1]==-1){
            return -1;
        }

        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }
};
int main() {
    int N = 3; // Number of stacks
    int S = 10; // Size of each stack
    NStack ns(N, S);

    // Push elements into the stacks
    ns.push(10, 1);
    ns.push(20, 1);
    ns.push(30, 2);
    ns.push(40, 3);

    // Pop elements from the stacks
    std::cout << "Popped from stack 1: " << ns.pop(1) << std::endl; // Should return 20
    std::cout << "Popped from stack 2: " << ns.pop(2) << std::endl; // Should return 30
    std::cout << "Popped from stack 3: " << ns.pop(3) << std::endl; // Should return 40

    return 0;
}