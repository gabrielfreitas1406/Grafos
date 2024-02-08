    #include<bits/stdc++.h>

    using namespace std;

    int n;
    char AM[1010][1010];
    vector<int> LA[1010];
    int comp[1010];
    vector<int> vertices_componentes[1010];

    void dfs(int u){
        vertices_componentes[comp[u]].push_back(u);
        for (int v: LA[u]){
            if (comp[v] == 0){
                comp[v] = comp[u];
                dfs(v);
            }
        }
    }

    bool checkComplete(int c){
        for(int u: vertices_componentes[c]){
            for(int v: vertices_componentes[c]){
                if(AM[u][v] != 'S') return false;
            }
        }
        return true;
    }

    int main(){
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                cin >> AM[i][j];
                if (AM[i][j] == 'S') LA[i].push_back(j);
            }
        }

        int c_componentes = 0;
        for (int i=0; i<n; i++){
            if (comp[i] == 0){
                comp[i] = ++c_componentes;
                dfs(i);
            }
        }

        int valid = 1;
        vector<int> resp;
        for(int i=1; i<=c_componentes; i++){
            if(checkComplete(i)) {
                resp.push_back(vertices_componentes[i].size());
            }
            else{
                valid = 0;
            }
        }

        if (valid){
            sort(resp.begin(),resp.end(),greater<int>());

            cout << resp.size() << "\n";
            for(int i=0; i<resp.size(); i++){
                cout << resp[i];
                if (i != resp.size() -1)  cout << " ";
            }
            cout << "\n";       
        }else{
            cout << "-1\n";
        }
    }