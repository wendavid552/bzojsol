/*
BZOJ4504
Status:Programming
思路：二分第k大的和是多少，然后看有多少子串的和比这个数小？
等价于pre[r]-pre[l-1]<sum，如果l-1固定，那么pre[r]<pre[l-1]+sum，右边可以看做常数，很明显可以排序然后做
只需要进行分治，每次只需要考虑跨过中心点的子串的答案即可，到两边数的和分别排序，然后可以筛出范围（用双指针）计数
另一种想法是：
利用树状数组。注意到如果l-1是我们正在枚举的，那么就相当于求下标pre[r]的前缀和!
不过这个样子的话就需要离散化
二分总觉得有点麻烦呢
*/
# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
# define LL long long
using namespace std;
const int maxn = 1e5+10;
int n,k;
int a[maxn];
LL pr[maxn];
bool cmp(int x,int y){
    return pr[x] < pr[y];
}
int T[maxn*4];
inline int lowbit(int x){return x&-x;}
inline void add(int x){
    for(;x<=n+n;x+=lowbit(x))T[x]++;
}
inline LL gsum(int x){
    LL res = 0; for(;x;x-=lowbit(x))res+=T[x]; return res;
}
int perm[maxn*2];
LL solve(LL sum){
    fo(i,1,n) pr[i+n] = pr[i] + sum;
    fo(i,1,n+n) perm[i] = i;
    sort(perm+1,perm+n+n+1,cmp);

    LL ans = 0;
    for(int i=n;i;--i){
        add(perm[i]);
        ans += gsum(perm[i-1+n]);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    fo(i,1,n) scanf("%d",a+i),pr[i] = pr[i-1]+a[i];
    LL ans = 0; fo(i,1,n) ans += a[i];
    LL l=0,r=ans;
    while(l<r){
        LL m = l+r>>1;
        if(solve(m) > k) l=m+1;
        else r=m;
    }
    printf("%lld\n",r);
    return 0;
}