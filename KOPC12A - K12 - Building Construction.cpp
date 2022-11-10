#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int lim = 1e4+5;

long long n;
long long h[lim],c[lim];

long long f(long long ht)
{
    long long cost =0,i;

    for(i=0;i<n;i++)
    {
        cost += abs(h[i]-ht)*c[i];
    }

    return cost;
}

int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        int i;
        cin>>n;

        for(i=0;i<n;i++) cin>>h[i];
        for(i=0;i<n;i++) cin>>c[i];

        long long lo =0,hi = 1e9;

    while((hi-lo)>=3)
    {
        long long m1 = lo + (hi-lo)/3;
        long long m2 = hi - (hi-lo)/3;

        if(f(m1)>f(m2)) lo = m1;
        else hi = m2;
    }

    long long ans = 1e12;
    for(i=lo;i<=hi;i++) ans = min(ans,f(i));

    cout<<ans<<endl;
   }

    return 0;
}
