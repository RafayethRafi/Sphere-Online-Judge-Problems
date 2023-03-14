#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int N = 1e5+123;
int n,cows;
int positions[N];


bool canPlaceCows(int minDist)
{
    int lastPos = -1;
    int cnt_cows = cows;
    for(int i=0;i<n;i++)
    {
        if(positions[i] - lastPos >=minDist  || lastPos==-1)
        {
            lastPos = positions[i];
            cnt_cows--;
        }
        if(cnt_cows == 0) break;
    }
    
    return cnt_cows ==0;
}

int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>cows;
        for(int i=0;i<n;i++) cin>>positions[i];

        sort(positions,positions+n);
        int lo = 0,hi = 1e9;

        while(hi-lo>1)
        {
            int mid = (lo + hi)/2;

            if(canPlaceCows(mid)) lo = mid;
            else hi = mid -1;
        }
        if(canPlaceCows(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    return 0;
}
