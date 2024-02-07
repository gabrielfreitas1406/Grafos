#include<bits/stdc++.h>

using namespace std;

int t,s,a,v;

const int N = 51;
const int CINZA = -2;
const int BRANCO = -1;

vector<int> vis(N,BRANCO);
vector<int> LA[N];

int dfs(int x){
    vis[x] = CINZA;

    int cnt_linha = 0;

    for(int v: LA[x]){
        if(vis[v] == BRANCO){
            cnt_linha += 2 + dfs(v);
        }
    }

    return cnt_linha;
}

int main(){
    cin >> t;

    while(t--){
        cin >> s;

        cin >> v >> a;

        for(int i=0;i<=v;i++){
            LA[i].clear();
            vis.assign(N,BRANCO);
        }


        for(int i=0;i<a;i++){
            int u,v;
            cin >> u >> v;

            LA[u].push_back(v);
            LA[v].push_back(u);
        }

        cout << dfs(s) << "\n";

    }
}
