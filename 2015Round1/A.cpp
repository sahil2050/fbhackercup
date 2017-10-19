#include<bits/stdc++.h>

using namespace std;
#define pb push_back
int const N = 1e7+10;
int const NP = 1e6;

bool isPrime[N];
vector<int> primes;
int primality[N];

void init(){
    isPrime[1] = 0;
    for(int i = 2; i < N; i++)isPrime[i] = 1;
    memset(primality, 0, sizeof primality);
    for(int i = 2; i < N; i++)
        if(isPrime[i]){
        primes.pb(i);
        primality[i] = 1;
        for(int j = 2; i*j < N; j++){
            primality[i*j]++;
            isPrime[i*j] = 0;
        }
    }
}

int main(){
    init();
    //cout<<"hello"<<endl;
    int t;cin>>t;
    for(int i = 1; i <= t; i++){
        int A,B,k;cin>>A>>B>>k;
        int ans = 0;
        for(int a = A; a <= B; a++)
            if(primality[a] == k)ans++;
        cout<<"Case #" << i <<": " << ans<<endl;
    }
}