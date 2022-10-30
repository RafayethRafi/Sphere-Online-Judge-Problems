#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);



bool vis[8][8];
int lvl[8][8];

int dx[] = {-1,1,-1,1,2,2,-2,-2};
int dy[] = {2,2,-2,-2,-1,1,-1,1};


void reset()
{
    memset(vis,0,sizeof(vis));
    memset(lvl,0,sizeof(lvl));
}
void bfs(int x,int y)
{
    queue<pair<int,int>>q;

    q.push({x,y});
    vis[x][y] = 1;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int u = p.first, v = p.second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            int childx = u + dx[i];
            int childy = v + dy[i];

            if(childx>=0 && childx<8 && childy>=0 && childy<8 && !vis[childx][childy])
            {
                q.push({childx,childy});
                lvl[childx][childy] = lvl[u][v] + 1;
                vis[childx][childy] = 1;
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
        reset();
        string s,t;
        cin>>s>>t;
        int x1,y1,x2,y2;
        x1 = s[1] - '1';
        y1 = s[0] - 'a';

        x2 = t[1] - '1';
        y2 =  t[0] - 'a';

        bfs(x1,y1);

        cout<<lvl[x2][y2]<<endl;
    }
    return 0;
}
