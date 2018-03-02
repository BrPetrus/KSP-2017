#include <vector>
#include <iostream>

using namespace std;

// Cislo suseda, dlzka hrany
vector<vector<pair<int,int>> > G;
vector<int> D, V; // Nespracovane a spracovane

const int INF = 2000000000;

int n = 5;

int main() {
    vector<pair<int, int>> tmp;
    tmp.push_back({2, 5});
    tmp.push_back({1, 2});
    G.push_back(tmp);
    tmp.clear();

    tmp.push_back({0, 2});
    tmp.push_back({3, 6});
    G.push_back(tmp);
    tmp.clear();

    tmp.push_back({0, 5});
    tmp.push_back({3, 1});
    tmp.push_back({4, 3});
    G.push_back(tmp);
    tmp.clear();

    tmp.push_back({1, 6});
    tmp.push_back({2, 1});
    tmp.push_back({4, 1});
    G.push_back(tmp);
    tmp.clear();

    tmp.push_back({2, 3});
    tmp.push_back({3, 1});
    G.push_back(tmp);
    tmp.clear();

    D.resize(n, INF);
    V.resize(n, INF);

    int a = 4; // Zaciatocny vrchol
    D[a] = 0;

    // Postupne prechadzame cez vrcholy a spracuvavame ich
    for (int i = 0; i < n; i++) {
        // Najdime vrchol s najmensou vzdialenostou
        int v = 0;
        for (int j = 1; j < n; j++) {
            if(D[j] < D[v]) v = j;
        }

        if(D[v] == INF) break; // Nesuvisly graf

        // Vrchol vyhlasime za spracovany a upravime hodnoty
        V[v] = D[v];
        D[v] = INF;
        for (int j = 0; j < G[v].size(); j++) {
            int w = G[v][j].first, dlz = G[v][j].second; // Sused vrchola a jeho vzdialenost
            if(V[w] != INF) continue; // Tento uz je spracovany
            D[w] = min(D[w], V[v] + dlz);
        }  
    }

    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << "\n";
    }
    return 0;
}