#include<bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define pb push_back
int const N = 1e5+10;

struct trieNode{
    trieNode* child[26];
    trieNode(){
        for(int i = 0; i < 26; i++)child[i] = NULL;
    }
};

string find_prefix(trieNode* trie, string &word){
    string prefix = "";
    bool found = 0;
    for(int i = 0; i < word.length(); i++){
        if(!found)prefix.pb(word[i]);
        if(trie->child[word[i] - 'a'] == NULL){
            trie->child[word[i] - 'a'] = new trieNode();
            found = 1;;
        }
        trie = trie->child[word[i] - 'a'];
        //cout<<i<<endl;
    }
    return prefix;
}

string words[N];
trieNode* trie;

int main(){
    int t;cin>>t;
    for(int T = 1; T <= t;T++){
        int n;cin>>n;
        for(int i = 0; i < n; i++)cin>>words[i];

        int ans = 0;
        trie = new trieNode();
        string prefix;
        for(int i = 0; i < n; i++){
            prefix  = find_prefix(trie,words[i]); 
            ans += prefix.length();
            //cout<<words[i] << " "<<prefix<<endl;
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
}