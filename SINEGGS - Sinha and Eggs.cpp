#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define endl '\n'
map<long long,bool> perSqr;

int main()
{
    optimize();
    int lim = 32e4, i;

    for(i=1;i<=lim;i++)
    {
        perSqr[1LL*i*i] =1;
    }

    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;

        if(perSqr[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
