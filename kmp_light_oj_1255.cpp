#include <bits/stdc++.h>
using namespace std;

void LPS(char pat[],int M,int lps[]);

void knuth_moris_pratt(char pat[],char txt[])
{
    int M = strlen(pat);
    int N =strlen(txt);

    int lps[M],count=0;;
    LPS(pat,M,lps);

    int i=0,j=0;

    while(i<N)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            count++;
            j=lps[j-1];
        }
        else if(i<N && pat[j] != txt[i])
        {
            if(j != 0 ) j=lps[j-1];
            else i=i+1;
        }
    }
    cout<<count<<endl;

}
void LPS(char pat[],int M,int lps[])
{
    int len=0;
    lps[0] = 0;
    int i = 1;
    while(i < M)
    {
        if(pat[i] == pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len != 0)
            {
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    int t,i;
    char txt[1000008],pat[1000008];
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>txt>>pat;
        cout<<"Case "<<i<<": ";
        knuth_moris_pratt(pat,txt);
    }
    return 0;
}
