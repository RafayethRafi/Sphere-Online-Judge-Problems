#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e5 + 4;
int d[mx];
int trace[mx];
vector<int>adj[mx];


int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {

        int n,i;
        cin>>n;
        memset(d,-1,sizeof(d));
        
        for(i=1;i<n;i++)
        {
            int k;
            cin>>k;
            while(k--)
            {
                int x;
                cin>>x;
                adj[i].push_back(x);
            }

            sort(adj[i].begin(),adj[i].end());
        }

        queue<int>q;
        q.push(1);
        d[1] = 0;

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            for(auto u:adj[x])
            {
                if(d[u]==-1)
                {
                    d[u] = d[x] + 1;
                    trace[u] = x;
                    q.push(u);
                }
            }
        }

        if(d[n]>-1)
        {
            cout<<d[n]<<endl;

            vector<int>res;

            int u = trace[n];

            while(u)
            {
                res.push_back(u);
                u = trace[u];
            }

            reverse(res.begin(),res.end());
            for(auto u:res) cout<<u<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;

        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            d[i] = -1; trace[i] = 0;
        }


    }
    return 0;
}
