#include<bits/stdc++.h>

using namespace std;
#define pb push_back

#define ll long long
int const N = 2010;
ll const mod = 1e9+7;
ll stress_free[N][N], stress_full[N][N];


void dp(){
    memset(stress_free, 0, sizeof stress_free);
    for(int i = 1; i < N; i++)stress_free[i][0] = 1ll;
    for(int j = 1; j < N; j++){
        for(int i = j+1; i < N; i++){
            stress_free[i][j] = (stress_free[i-1][j] + stress_free[i][j-1])%mod;
        }
    }

    memset(stress_full, 0, sizeof stress_full);
    for(int i = 0; i < N; i++)stress_full[0][i] = 1;
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j++){
            if(j == i)stress_full[i][j] = stress_full[i-1][j];
            else stress_full[i][j] = (stress_full[i-1][j] + stress_full[i][j-1])%mod;
        }
    }


}

int main(){
    int t;cin>>t;
    dp();
    for(int T = 1; T <= t; T++){
        string s;cin>>s;
        int a = 0, b = 0;
        int i = 0;
        while(s[i] != '-'){
            a *= 10;
            a += s[i++] - '0';
        }
        i++;
        while(i < s.length()){
            b *= 10;
            b += s[i++] - '0';
        }
        //cout<<a<<" "<<b<<endl;
        cout<<"Case #"<<T<<": "<<stress_free[a][b]<<" "<<stress_full[b][b]<<endl;
    }
}