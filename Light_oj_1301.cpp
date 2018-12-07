#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("inpt.txt","r",stdin);
int t,m=1;
vector<int>first,last;
cin>>t;
while(t--)
{
int n;
cin>>n;
while(n--)
{
int x,y;
cin>>x>>y;
first.push_back(x);
last.push_back(y);
}
sort(first.begin(),first.end());
sort(last.begin(),last.end());
int i=0,j=0,c=0;
while(i<first.size())
{
// cout<<i<<first.size()<<endl;
while(first[i]<=last[j])
{
// cout<<first[i]<<" "<<last[j]<<endl;
c++;
i++;
if(i>=first.size())break;

}
i++;
j++;
}
cout<<"Case "<<m<<": "<<c<<endl;
m++;
first.clear();
last.clear();

}
return 0;

}
