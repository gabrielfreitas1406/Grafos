#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int tipo[40][2], qtde[10];
bool match;
int m;

void solve(int p){
    if (p == m+ 1){
        match = true;
        return;
    }
    if (match) return;
    if (qtde[tipo[p][0]]){
        qtde[tipo[p][0]]--;
        solve(p + 1);
        qtde[tipo[p][0]]++;
    }
    if (qtde[tipo[p][1]]){
        qtde[tipo[p][1]]--;
        solve(p + 1);
        qtde[tipo[p][1]]++;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int testes, n;
    string s1, s2;
    cin >> testes;
    while (testes--){
        cin >> n >> m;
        for (int i = 0; i < 10; i++) qtde[i] = n / 6;

        for (int i = 1; i <= m; i++){
            cin >> s1 >> s2;
            if (s1 == "XS") tipo[i][0] = 1;
            else if(s1 == "S") tipo[i][0] = 2;
            else if(s1 == "M") tipo[i][0] = 3;
            else if(s1 == "L") tipo[i][0] = 4;
            else if(s1 == "xL") tipo[i][0] = 5;
            else  tipo[i][0] = 6;
            
            if(s2 == "XS") tipo[i][1] = 1;
            else if(s1 == "S") tipo[i][1] = 2;
            else if(s1 == "M") tipo[i][1] = 3;
            else if(s1 == "L") tipo[i][1] = 4;
            else if(s1 == "XL") tipo[i][1]= 5;
            else tipo[i][1] = 6;
        }
        match = false;
        solve(1);
        if (match) cout << "YES\n";
        else cout << "NO\n";
    }
}