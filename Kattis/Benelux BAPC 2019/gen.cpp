#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    int n;
    cin >> n;

    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        arr1[i] = i+1; arr2[i] = i+1;
    }

    shuffle(arr1.begin(), arr1.end(), std::default_random_engine(seed));
    shuffle(arr2.begin(), arr2.end(), std::default_random_engine(seed + 10));

    cout << n << endl;
    for (auto i : arr1) cout << i << " ";
    cout << endl;
    for (auto i : arr2) cout << i << " ";
    cout << endl;

    return 0;
}