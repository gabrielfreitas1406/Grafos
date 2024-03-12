
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#define INF 999999
using namespace std; 

int dist[4000][26];
vector< vector<pair<int,string> > > adj;
map<string, int> m;
long long n;
string origem, destino, l1, l2, p;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while (true)
    {
        cin >> n;
        if (!n) break;
        int vt = 1;
        cin >> origem >> destino;
        m[origem] = 1;
        m[destino] = 2;
        vt = 3;
        adj.assign((2 * n + 10), vector<pair<int,string> > ());
        for (int i = 0; i < n; i++){
            cin >> l1 >> l2 >> p;
            int x, y;
            if (!m.count(l1)){
                m[l1] = vt;
                x = vt;
                vt++;
            }else x = m[l1];
            if (!m.count(l2)){
                m[l2] = vt;
                y = vt;
                vt++;
            } else y = m[l2];
            adj[x].push_back(make_pair(y, p));
            adj[y].push_back(make_pair(x, p));
        }
        for (int i = 0; i < 4000; ++i) for (int j = 0; j < 26; ++j) dist[i][j] = INF;

        for (int i = 0; i < 26; ++i) dist[1][i] = 0;

        priority_queue< pair <int, pair<int, char> >, vector<pair<int,pair<int,char> > >, greater<pair<int, pair<int, char> > > > pq;
        pq.push(make_pair(0,make_pair(1,'a')));

        while (!pq.empty()){
            pair<int, pair<int, char> > front = pq.top();
            pq.pop();
            int d = front.first;
            int v = front.second.first;
            char cx = front.second.second;
            for (int i = 0; i < adj[v].size(); ++i){
                char c = adj[v][i].second[0];

                if (v != 1 && c == cx) continue;
                if (dist[adj[v][i].first][c - 'a'] >= dist[v][cx - 'a']
                + adj[v][i].second.size()){
                    dist[adj[v][i].first][c - 'a'] = dist[v][cx - 'a']
                    + adj[v][i].second.size();
                    pq.push(make_pair(dist[adj[v][i].first][c - 'a'],
                    make_pair(adj[v][i].first, c)));
                }
            }

        }
        int ans = INF;
        for (int i = 0; i < 26; ++i) ans = min(ans, dist[2][i]);
        if (ans == INF) {
            cout << "impossível\n";
        }
        else{
            cout << ans << "\n";
        }
        m.clear();
        adj.clear();
    }   
}
