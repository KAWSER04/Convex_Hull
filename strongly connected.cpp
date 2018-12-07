#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,i,j,k,counter=0;
    cin>>m;
    long A[m][m],A2[m][m],A3[m][m],A4[m][m],B4[m][m],P[m][m];

    cout<<m<<"x"<<m<<" size:"<<endl;

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    cout<<endl;

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            A2[i][j]=0;
            for(k=0;k<m;k++){
                A2[i][j]=A2[i][j]+A[i][k]*A[k][j];
            }
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            A3[i][j]=0;
            for(k=0;k<m;k++){
                A3[i][j]=A3[i][j]+A2[i][k]*A[k][j];

            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            A4[i][j]=0;
            for(k=0;k<m;k++){
                A4[i][j]=A4[i][j]+A2[i][k]*A2[k][j];
            }
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            B4[i][j]=A[i][j]+A2[i][j]+A3[i][j]+A4[i][j];
            if(B4[i][j]!=0)P[i][j]=1;
            else{
                P[i][j]=0;
                counter++;
            }
            cout<<B4[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cout<<P[i][j]<<" ";

        }
       cout<<endl;

    }
    cout<<endl;

      if(counter!=0)cout<<"This is not Strongly Connected."<<endl;
    else cout<<"This is Strongly Connected."<<endl;
    cout<<endl;


    return 0;
}
