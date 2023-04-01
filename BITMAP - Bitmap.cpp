#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int N = 200; 
int n,m;
vector<vector<int>> dist;
string s[N];

bool isValid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs()
{
    queue<pair<int,int>> q;
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='1')
            {
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(i=0;i<4;i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if(isValid(u,v) && (dist[u][v]==-1))
            {
                dist[u][v] = dist[x][y] + 1;
                q.push({u,v});
            }
        }
    }
}

int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        dist.assign(n, vector<int> (m,-1));
        int i,j;

        for(i=0;i<n;i++) cin>>s[i];

        bfs();

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
