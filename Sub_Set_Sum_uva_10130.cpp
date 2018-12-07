#include<bits/stdc++.h>
using namespace std;


int knapSack(int W, int weight[], int prize[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= w)
                 K[i][w] = max(prize[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,n,price[1000],weight[1000],q,x;
    int  W;
    //freopen("input.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>price[i]>>weight[i];

        }

        cin>>q;
        int sum=0;
        while(q--)
        {
            cin>>W;
            sum+=knapSack(W, weight, price, n);
        }
        cout<<sum<<endl;
    }

    return 0;
}
