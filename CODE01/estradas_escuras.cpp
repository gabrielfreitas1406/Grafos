#include <bits/stdc++.h>

using namespace std;
int n, m, u, v, w;
vector <pair<int,int>> LA[200010];
int in_mst[200010];

int main(){
    while (1){
        cin >> n >> m;
        if (n ==0 && m == 0) break;

        for(int i=0; i<n; i++){
            LA[i].clear();
            in_mst[i] = 0;
        }

        int sm_a = 0;

        for (int i=0; i<m; i++){
            sm_a+=w;
            cin >> u >> v >> w;
            LA[u].push_back({w,v});
            LA[v].push_back({w,u});
        }    
    

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;
        in_mst[0] = 1;
        for (auto &[v, w]: LA[0]){
            fila.push({w, v});
        }

        int c_mst = 0;
        while (!fila.empty()){
            auto &[v, w] = fila.top();
            fila.pop();

            if (in_mst[v] == 0){
                in_mst[v] = 1;
                c_mst += w;

                for (auto &[w2, v2]: LA[v]){
                    if (in_mst[v2] == 0) fila.push({w2,v2});
                }
            }
            
        }
        cout << sm_a - c_mst << "\n";
    }
}