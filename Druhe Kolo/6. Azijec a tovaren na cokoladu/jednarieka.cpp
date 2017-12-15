// medzi dvoma vrcholmi je len jedna rieka
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Cislo suseda, dlzka hrany
vector<vector<pair<int,int>> > G;
vector<int> V; // Nespracovane a spracovane

int djikstra(int a, int e, ) {

}

int main() {
    int n, m, q; // Pocet vrcholov, hran, otazok
    cin >> n >> m >> q;
    V.resize(n, -1);
    G.resize(n);

    for (int i = 0; i < m; i++) {
        int vrchol, sused, vzd;
        cin >> vrchol >> sused >> vzd;
        G[vrchol-1].push_back({sused, vzd});
    }

    for (int i = 0; i < q; i++) {

    }

    int a = 0; // Zaciname vo vrchole a

    // Nespracovane vrcholy; First=vzdialenost Second=Vrchol
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > D;

    // Start
    D.push({0, a});
    while(!D.empty()) {
        // Vymazeme uz spracovane vrcholy
        while(!D.empty() && V[D.top().second] != -1)
            D.pop();
        if(D.empty())
            break;

        // Prvy v queue
        int v = D.top().second;
        int vzd = D.top().first;
        V[v] = vzd;

        // Upravime susedov
        for (int i = 0; i < G[v].size(); i++) {
            int w = G[v][i].first, dlz = G[v][i].second;

            // Ak uz je sused spracovany, netreba nic robit
            if (V[w] != -1)
                continue;
            D.push({vzd + dlz, w});
        }
    }


    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << "\n";
    }
    return 0;
} 