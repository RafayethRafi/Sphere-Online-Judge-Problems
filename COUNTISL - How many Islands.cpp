#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};

const int mx = 1e4;
string s;
vector<string>v;
bool vis[mx][mx];
int n,m;
void dfs(int x,int y)
{
    vis[x][y] = 1;

    for(int i=0;i<8;i++)
    {
        int p = x + dx[i];
        int q = y + dy[i];

        if(p>=0 && p<n && q>=0 && q<m && !vis[p][q] && v[p][q]=='#')
        dfs(p,q);
    }

}
int main()
{
    optimize();
    int t,i;
    cin>>t;
    while(t--)
    {
        int j,cnt=0;
        cin>>n>>m;

        for(i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='#' && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
        memset(vis,0,sizeof(vis));
        v.clear();
    }
    return 0;
}
