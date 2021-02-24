/*
BZOJ 2100
Status:Accepted
*/
# include <bits/stdc++.h>
# define pb push_back
# define mp make_pair
# define fi first
# define se second
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std; 
const int maxn = 1e5+10;
vector<int> g[maxn];
vector<int> c[maxn];
int n,m;
int s,t1,t2;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
int dis[maxn];
int dis12[maxn];
int main(){
    scanf("%d%d",&m,&n);
    scanf("%d%d%d",&s,&t1,&t2);
    fo(i,1,m){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        g[u].pb(v); c[u].pb(d);
        g[v].pb(u); c[v].pb(d);
    }
    fo(i,1,n) dis[i] = 0x3f3f3f3f;
    dis[s] = 0;
    Q.push(mp(0,s));
    while(!Q.empty()){
        int x = Q.top().se; Q.pop();
        for(int i=0;i<g[x].size();++i){
            int v = g[x][i];
            if(dis[v] > dis[x] + c[x][i]){
                dis[v] = dis[x] + c[x][i];
                Q.push(mp(dis[v],v));
            }
        }
    }

    fo(i,1,n) dis12[i] = 0x3f3f3f3f;
    dis12[t1] = 0;
    Q.push(mp(0,t1));
    while(!Q.empty()){
        int x = Q.top().se; Q.pop();
        for(int i=0;i<g[x].size();++i){
            int v = g[x][i];
            if(dis12[v] > dis12[x] + c[x][i]){
                dis12[v] = dis12[x] + c[x][i];
                Q.push(mp(dis12[v],v));
            }
        }
    }

    printf("%d\n",min(dis[t1],dis[t2])+dis12[t2]);
    return 0;
}