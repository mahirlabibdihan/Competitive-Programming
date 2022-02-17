#include<stdio.h>
#include<math.h>

void merge(long long int x[],long long int l,long long int m,long long int h)
{  long long int i=l, j=m+1, k=l, y[h+1];
    while(i<=m&&j<=h)
    { if(x[i]<=x[j]) y[k++]=x[i++]; else y[k++]=x[j++];}
    while(j<=h) y[k++]=x[j++]; while(i<=m) y[k++]=x[i++];
    for(i=l;i<=h;i++)  x[i]=y[i]; }

void sort(long long int x[],long long int l,long long int h)
{    if(l<h) { long long int m=(l+h)/2;
   sort(x,l,m);  sort(x,m+1,h);  merge(x,l,m,h);} }


int main()

{
    long long int n,i,j,k,min,c=0,s,o,m,sum=0;

    scanf("%lld %lld",&n,&m);
    o=(-1+sqrt(1+8*m))/2;
    long long int x[n],y[o];

    for(i=0;i<n;i++)
        scanf("%lld",&x[i]);

    sort(x,0,n-1);

    for(j=0; j<n&&sum<=m; j++)
    {

        if(j) s=x[j-1]+1;
        else s=1;

            for(;s<x[j]&&sum+s<=m;s++)
            {sum=sum+s;   y[c]=s;   c++;}
    }


        for(s=x[n-1]+1;sum+s<=m;s++)
        {sum=sum+s;  y[c]=s;   c++;}


    printf("%lld\n",c);
    for(i=0; i<c; i++)
        printf("%lld ",y[i]);

}








