#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    long long n,i;
    cin>>n;
    vector<long long>a(n),b(n),c(n),d(n),sum;

    for(i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    long long ans=0;

    for(auto u:a)
    {
        for(auto v:b)
        {
            sum.push_back(u+v);
        }
    }

    sort(sum.begin(),sum.end());

    for(auto u:c)
    {
        for(auto v:d)
        {
            long long need = -(u+v);

            if(binary_search(sum.begin(),sum.end(),need))
            {
                ans += upper_bound(sum.begin(),sum.end(),need) - lower_bound(sum.begin(),sum.end(),need);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
