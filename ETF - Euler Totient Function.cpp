#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int MX = 1e7+123;
int ans[MX];
bitset<MX>is_prime;
vector<int>prime;
 
void primeGen(int n)
{
    int i,j;
    n+=100;
    for(i=3;i<=n;i+=2) is_prime[i] =1;
 
    int sq = sqrt(n);
 
    for(i=3;i<=sq;i+=2)
    {
        if(is_prime[i])
        {
            for(j=i*i;j<=n;j+=(i+i))
            is_prime[j] = 0;
        }
    }
    is_prime[2] =1;
    prime.push_back(2);
 
    for(i=3;i<=n;i+=2)
    {
        if(is_prime[i]) prime.push_back(i);
    }
}

int phi(int n)
{
    int ret = n;
    for(auto p:prime)
    {
        if(1LL*p*p>n || n==0) break;

        if(n%p==0)
        {
            ret/=p;
            ret*= (p-1);

            while(n%p==0) n/=p;
        }
    }
    if(n>1)
    {
        ret /=n;
        ret *= (n-1);
    }

    return ret;
}

int main()
{
    optimize();
    primeGen(1e6);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<phi(n)<<endl;
    }
    
    return 0;
}
