#include<iostream>
using namespace std;
int main()
{
    int a[10],n,i,j,temp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=n-1;i>0;i--)
    {
       for(j=0;j<i;j++)
       {
           if(a[j]>a[j+1])
            {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
       }

    }

    for(i=0;i<n;i++)
    cout<<a[i];
}
