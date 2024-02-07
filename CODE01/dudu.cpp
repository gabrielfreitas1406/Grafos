#include<iostream>
#include<vector>

using namespace std;


int t,n,m,a,b;
vector<int> g[10010];

// 0 - Branco, 1 - Cinza, 2 - Preto
int color[10010];

int checkCycle(int u){
    color[u] = 1; // Preto

    int cycle = false;
    for(int v: g[u]){
        if(color[v] == 1) return true;

        if(color[v] == 0){
            if(checkCycle(v)) cycle = true;
        }
    }

    color[u] = 2; // Cinza

    return cycle;
}


int main(){
    cin >> t;

    while(t--){
        cin >> n >> m;
        
        //Reseta o Grafo.
        for(int i = 1;i<=n;i++){
            g[i].clear();
            color[i] = 0;
        }

        //Le e constrói o grafo.
        for(int i=0;i<m;i++){
            cin >> a >> b;
            g[b].push_back(a);
        }

        // Checa se existe ciclo.
        int hasCycle = 0;
        for(int i=1;i<=n;i++){
            if(color[i] == 0 && checkCycle(i)){
                hasCycle = 1;
            }
        }

        if(hasCycle) cout << "SIM\n";
        else cout << "NAO\n";
    }
}
