#include<bits/stdc++.h>
#include <sys/resource.h>

using namespace std;

#define pb push_back
#define vi vector<int>
int const N = 2e5+10;
int const LOGN = 20;

vi tree[N];
int dp[N][LOGN];
int n, p;

void dfs(int u, int c){
    if(dp[u][c])return;
    dp[u][c] = c;
    for(int v: tree[u]){
        int temp = INT_MAX;
        for(int d = 1; d < LOGN; d++){
            dfs(v,d);
            if(d != c)temp = min(temp, dp[v][d]);
        }
        dp[u][c] += temp;
    }
}

int main(){
    const rlim_t kStackSize = 512 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }


    int t;cin>>t;
    for(int T = 1; T <= t; T++){
        cin>>n;
        //cout<<n<<endl;
        for(int i = 0; i < N; i++)tree[i].clear();
        for(int i = 1; i <= n; i++){
            cin>>p;
            tree[p].pb(i);
        }
        int ans = 2*n;
        memset(dp,0,sizeof dp);
        for(int i = 1; i < LOGN; i++)dfs(1, i);
        for(int i = 1; i < LOGN; i++)ans = min(ans, dp[1][i]);
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
}