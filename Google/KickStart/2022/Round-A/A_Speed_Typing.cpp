#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        string P,I;
        cin>>I>>P;
        int n=I.length();
        int m=P.length();
        bool flag = false;
        for(int i=0,j=0;j<n && i<m;i++)
        {
            // cout<<i<<" "<<j<<endl;
            if(I[j]==P[i])
            {
                j++;
            }
            if(j==n)
            {
                flag = true;
            }
        }
        if(flag)
        {
            printf("Case #%d: %d\n",t,m-n);
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE\n",t);
        }
    }
}
