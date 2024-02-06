#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int BRANCO = 0;
const int CINZA = 0;
const int PRETO = 0;

vector<int> LA[10010];
int vis[10010];
int n, m, u, v;
int hasCycle = 0;


void dfs(int u){
    vis[u] = CINZA;
    for(int v: LA[u]){
        if (vis[v] == BRANCO){
            dfs(v);
        }
        else if (vis[v] == CINZA){
            hasCycle = 1;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        hasCycle = 0;

        for(int i=1; i<=n; i++){
            vis[i] = BRANCO;
            LA[i].clear();
        }

        for(int i=0;i<m;i++){
            cin >> u >> v;
            LA[u].push_back(v);
        }

        for(int i=1; i<=n; i++){
            if (vis[i] == BRANCO){
                dfs(i);
                if (hasCycle) break;
            }
        }

        if (hasCycle) cout << "SIM\n";
        else cout << "NÃO\n";
    }

}
