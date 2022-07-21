#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> animals;
    vector<vector<string>> all(26);

    for (int i = 0; i < n; i++) {
        string animal;
        cin >> animal;
        if (animal[0] == s.back()) {
            // we can say that animal
            animals.push_back(animal);
        }

        all[animal[0] - 'a'].push_back(animal);
    }

    if (animals.size() == 0) {
        cout << "?" << endl;
    } else {
        for (int i = 0; i < animals.size(); i++) {
            if (all[animals[i].back() - 'a'].size() == 0 || (all[animals[i].back() - 'a'].size() == 1 && all[animals[i].back() - 'a'][0] == animals[i])) {
                cout << animals[i] << "!" << endl;
                return 0;
            }
        }

        cout << animals[0] << endl;
    }

    return 0;
}