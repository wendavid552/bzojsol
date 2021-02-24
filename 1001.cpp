# include <bits/stdc++.h>
# define pb push_back
# define fi first
# define se second
# define mp make_pair
# define ll long long
# define fo(i,a,b) for (int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 2010*2010;
int dis[maxn];
priority_queue<pair<int,int>,vector<int,int>,greater<pair<int,int> > > Q;
vector<int> g[maxn];
vector<int> c[maxn];
void Dij(){
    while(!Q.empty()){
        int x = Q.top().se;
        for(int i=0;i<g[x].size();++i){
            int v = g[x][i];
            if(dis[v] > dis[x] + c[i]){
                dis[v] = dis[x] + c[x][i];
                Q.push(mp(dis[v],v));
            }
        }
    }
}
int main(){
    
    return 0;
}