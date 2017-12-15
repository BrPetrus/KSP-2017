#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Cislo suseda, dlzka hrany
vector<vector<pair<int,int>> > G;
vector<pair<int, int>> V; // Spracovane; vzd, kolko hran

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


    V.resize(n, {-1, 0});
    int a = 4; // Zaciname vo vrchole a
    int koniec = 1;

    // Nespracovane vrcholy; First=vzdialenost Second=Vrchol
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > D;

    // Start
    D.push({0, a});
    while(!D.empty()) {
        // Vymazeme uz spracovane vrcholy
        while(!D.empty() && V[D.top().second].first != -1)
            D.pop();
        if(D.empty())
            break;

        // Prvy v queue
        int v = D.top().second;
        int vzd = D.top().first;
        V[v].first = vzd;

        if(v == koniec) {
            cout << "KONIEC" << V[v].first << "\t" << V[v].second << "\n";
        }

        //V[v].second = V[v].second + 1;

        // Upravime susedov
        for (int i = 0; i < G[v].size(); i++) {
            int w = G[v][i].first, dlz = G[v][i].second;

            // Ak uz je sused spracovany, netreba nic robit
            if (V[w].first != -1)
                continue;
            V[w].second = V[v].second + 1;
             
            // // Ciel
            // if (w == koniec) {
            //     cout << "KONIEC" << V[i].first << "\t" << V[i].second << "\n";
            // }
            D.push({vzd + dlz, w});
        }
    }


    for (int i = 0; i < V.size(); i++) {
        cout << V[i].first << "\t" << V[i].second << "\n";
    }
    return 0;
} 