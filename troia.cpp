#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int no, vector<vector<int>>& adj, vector<bool>& visitado){
    visitado[no] = true;
    for(int vizinho : adj[no]){
        if(!visitado[vizinho]){
            dfs(vizinho, adj, visitado);
        }
    }
}

int main(){

int n, m;
cin >> n >> m;

    vector < vector <int>> adj(n+1);


    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visitado(n+1, false);

    int familias = 0;

    for(int i = 1; i <= n; i++){
        if(!visitado[i]){
            familias++;

            dfs(i, adj, visitado);
        }
    }
    cout << familias << endl;
}