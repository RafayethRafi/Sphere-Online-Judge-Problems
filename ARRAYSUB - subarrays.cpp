#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    int n,k,i;
    cin>>n;
    int a[n];

    for(i=0;i<n;i++) cin>>a[i];

    cin>>k;

    for(i=0;i<=n-k;i++)
    {
        cout<<*max_element(a+i,a+i+k)<<" ";
    }
    cout<<endl;
    
    return 0;
}
