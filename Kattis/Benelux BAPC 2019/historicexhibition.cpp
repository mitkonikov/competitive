#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e4 + 10;

int main() {
    int p, v;
    cin >> p >> v;

    map<int, vector<int>> cards;
    vector<pair<int, int>> pads(p);
    map<int, vector<int>> priority;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        pads[i] = { a, b };

        if (a == b) {
            priority[a].push_back(i+1);
            continue;
        }

        cards[min(pads[i].first, pads[i].second)].push_back(i+1);
    }

    vector<pair<int, int>> vases(v);
    for (int i = 0; i < v; i++) {
        int d; cin >> d;
        vases[i] = { d, i };
    }

    if (p < v) {
        cout << "impossible" << endl;
        return 0;
    }

    sort(vases.begin(), vases.end());

    vector<int> results(v);
    for (int i = 0; i < v; i++) {
        int cVase = vases[i].first;
        auto it = priority.find(cVase);
        if (it != priority.end() && it->second.size()) {
            results[vases[i].second] = it->second.back();
            it->second.pop_back();
        } else {
            // if there's not a vase with priority
            //    cards[cVase] or cards[cVase - 1] ? 
                // first check the prev card;
            auto it1 = cards.find(cVase - 1);
            auto it2 = cards.find(cVase);

            if (it1 != cards.end() && it1->second.size()) {
                results[vases[i].second] = it1->second.back();
                it1->second.pop_back();
            } else if (it2 != cards.end() && it2->second.size()) {
                results[vases[i].second] = it2->second.back();
                it2->second.pop_back();
            } else {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < v; i++) {
        cout << results[i] << "\n";
    }
    cout << flush;

    return 0;
}