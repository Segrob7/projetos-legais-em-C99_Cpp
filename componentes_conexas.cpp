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
int total_nos = 10;

    vector< pair <int, int >> arestas = {{1,2},{1,4}, {2,3},{2,6}, {3,4}, {3,6}, {6,5}, {8,7}};
    vector < vector <int>> adj(total_nos);

    for(auto  aresta  : arestas){
        adj[aresta.first].push_back(aresta.second);
        adj[aresta.second].push_back(aresta.first);
    }
    vector<bool> visitado(total_nos, false);

    int familias = 0;

    for(int i = 1; i <= 9; i++){
        if(!visitado[i]){
            familias++;

            dfs(i, adj, visitado);
        }
    }
    cout << familias << endl;
}