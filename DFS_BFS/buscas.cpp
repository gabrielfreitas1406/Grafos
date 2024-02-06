#include <bits/stdc++.h>

using namespace std;


const int BRANCO = 0;
const int CINZA = 0;
const int PRETO = 0;

vector<int> LA[100];
int vis[100];
int n, m, u, v;


void dfs(int u){
    vis[u] = CINZA;
    for(int v: LA[u]){
        if (vis[v] == BRANCO){
            dfs(v);
        }
        
    }
}

int main(){
    /*cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> u >> v;
        LA[u].push_back(v);
        LA[v].push_back(u);
    }*/
    //BFS
    queue<int> fila;
    fila.push(0);

    while (!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v: LA[u]){
            if (vis[v] == BRANCO){
                vis[u] = CINZA;
                fila.push(v);
            } 
        }

        vis[u] = PRETO;
    }
}

