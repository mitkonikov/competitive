#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> result;
    for (int photo = 1; photo <= k; photo++) {
        int s; cin >> s;

        set<int> dp_front;
        set<int> dp_back;

        vector<int> people(s);
        for (int i = 0; i < s; i++) cin >> people[i];

        for (int i = s-1; i >= 1; i--) dp_back.insert(people[i]);
        dp_front.insert(people[0]);

        bool matches = false;
        for (int i = 1; i < s-1; i++) {
            dp_back.erase(people[i]);

            auto alice = dp_front.upper_bound(people[i]);
            if (alice != dp_front.end() && *alice) {
                auto bob = dp_back.upper_bound(*alice);
                if (bob != dp_back.end() && *bob) {
                    matches = true;
                    break;
                }
            }

            dp_front.insert(people[i]);
        }

        if (matches) result.push_back(photo);
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}