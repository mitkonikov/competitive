#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;
    while (n % 2 == 0) {
        result++;
        n /= 2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            n /= i;
            result++;
        }
    }
 
    if (n > 2) result++;
    
    cout << result << endl;
    
    return 0;
}