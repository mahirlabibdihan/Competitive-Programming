#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        string s;
        cin>>s;
        int n=s.length();
        int sum=0;
        for(char c:s)
        {
            sum+=c-'0';
        }

        char tmp = (9-(sum%9))%9+'0';
        //cout<<sum<<" "<<tmp<<endl;
        int j = -1;
        if(tmp=='0')
        {
            s.insert(1,string(1,tmp));
        }
        else
        {

            for(int i=0;i<n;i++)
            {
                if(s[i]>tmp)
                {
                    s.insert(i,string(1,tmp));
                    break;
                }
            }
            if(s.length()==n)
            {
                s.insert(n,string(1,tmp));
            }
        }

        cout<<"Case #"<<t<<": "<<s<<endl;
        //printf("Case #%d: %s%d\n",t,s,int(9*ceil(sum/9.0)-sum));
    }
}

