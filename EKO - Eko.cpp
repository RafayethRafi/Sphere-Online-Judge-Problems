#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int N = 1e6 + 10;
int n;
long long m;
long long trees[N];

bool isWoodSufficient(int h)
{
    long long wood =0;
    for(int i=0;i<n;i++)
    {
        if(trees[i]>h) wood += (trees[i] - h);
    }

    return wood >= m;
}

int main()
{
    optimize();
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>trees[i];

    long long lo = 0,hi = 1e9,mid;

    while(hi-lo > 1)
    {
        // T T T T F F F F
        mid = (hi+lo)/2;
        if(isWoodSufficient(mid))
            lo = mid;
        else hi = mid-1;


    }

    if(isWoodSufficient(hi)) cout<<hi<<endl;
    else cout<<lo<<endl;

    return 0;
}
