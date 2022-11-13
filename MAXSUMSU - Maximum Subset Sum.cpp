#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;

        long long sum=0,ans = INT_MIN;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            sum+=x;

            ans = max(ans,sum);
            if(sum<0) sum=0;
        }

        cout<<sum<<endl;
    }
    return 0;
}
