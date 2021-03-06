#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void PrintPreorder(int Nodes[],int start,int end){
    if(start>end)
        return;
    cout<<Nodes[start]<<" ";             //Printing present value
    PrintPreorder(Nodes,start*2+1,end);   //Executing the left subtree
    PrintPreorder(Nodes,start*2+2,end);   //Executing the right subtree
}

int main(){
    int Tree[] = {4, 2, 6, 1, 3, 5, 7};
    int n = sizeof(Tree)/sizeof(int);

    cout<<"The Preorder Traversal is:"<<endl;
    PrintPreorder(Tree,0,n-1);
    return 0;
}

