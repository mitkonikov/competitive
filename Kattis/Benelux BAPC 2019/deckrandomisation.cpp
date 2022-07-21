// Deck Randomization
// DFS, DP, ReverseGCD, Chinese Remainder Theorem

#include <bits/stdc++.h>

#define ll long long

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

template<typename T>
pair<T, pair<T,T> > reverseGCD(T a, T b) {
    // returns (g,(x,y))
    pair<T,pair<T,T>> ret;
    if (a == 0) {
        ret.first = b;
        ret.second.first = 0;
        ret.second.second = 1;
    } else {
        T g, x, y;
        pair<T,pair<T, T>> temp = reverseGCD(b%a, a);
        g = temp.first;
        x = temp.second.first;
        y = temp.second.second;
        ret.first = g;
        ret.second.first = y - (b/a)*x;
        ret.second.second = x;
    }
    return ret;
}

template<typename T>
T CRT(vector<T> n, vector<T> a) {
    // n divisor, a is the remainder
    
    T Di = n[0], remainder = a[0];
    int k = n.size();

    for (int i = 1; i < k; ++i) {
        T di = n[i];
        T bi = a[i];
        auto rGCD = reverseGCD(Di, di);
        T x = rGCD.second.first, y = rGCD.second.second;

        T c = bi - remainder;
        
        if (c % rGCD.first) // indicates that no result
            return LLONG_MAX;

        T D = di / rGCD.first;
        remainder += Di * (((c / rGCD.first * x)%D+D)%D);

        if (remainder > 1e12) {
            return LLONG_MAX;
        }

        Di *= D;
    }
 
    // represents the remainder of all zeros
    if (!remainder) {
        remainder = 1;
        for(int i = 0; i < k; ++i) {
            remainder = remainder * n[i] / gcd(remainder, n[i]);
            if (remainder > 1e12) {
                return LLONG_MAX;
            }
        }
    }

    return remainder;
}

int n;
vector<int> alice, bob;
vector<int> count_alice, count_bob;
vector<int> temp_count_alice, temp_count_bob;
vector<int> cycle_alice, cycle_bob;
map<int, int> cycle_len;
set<int> alice_len;
set<pair<ll, ll>> bob_len;

// returns the length of the cycle
// while storing the dp values of shortest paths to each node from the startNode
int dfs(int node, bool turn, int depth, int startNode) {
    if (turn) { // this is alice's turn
        cycle_alice[node] = startNode;
        temp_count_alice[node] = depth - 1;
        if (alice[node] == startNode && count_bob[startNode] == -1) {
            count_bob[startNode] = depth;
        }
        
        if (depth == 1 || node != startNode) return 1 + dfs(alice[node], false, depth+1, startNode);
        else return 0;
    } else {
        cycle_bob[node] = startNode;
        temp_count_bob[node] = depth - 1;

        return 1 + dfs(bob[node], true, depth+1, startNode);
    }
}

ll getLCM(const set<int> &lcm_set) {
    ll result = 1;
    for (auto it = lcm_set.rbegin(); it != lcm_set.rend(); it++) {
        result = (ll)(*it) / gcd(result, (ll)(*it)) * result;
        if (result > (ll)1e12) {
            result = LLONG_MAX;
            break;
        }
    }

    return result;
}

bool solve() {
    count_alice.resize(n, -1);
    count_bob.resize(n, -1);
    cycle_alice.resize(n, -1);
    cycle_bob.resize(n, -1);
    temp_count_alice.resize(n, -1);
    temp_count_bob.resize(n, -1);

    bool can_bob = true;
    for (int i = 0; i < n; i++) {
        if (cycle_alice[i] == -1) {
            int len = dfs(i, true, 1, i);
            cycle_len[i] = len;
            alice_len.insert(len);
            count_alice[i] = cycle_len[i];
        }

        if (cycle_alice[i] != cycle_bob[i]) can_bob = false;
    }

    return can_bob;
}

int main() {
    cin >> n;

    alice.resize(n, 0);
    bob.resize(n, 0);

    bool solved = true;
    for (int i = 0; i < n; i++) {
        cin >> alice[i];
        alice[i]--;
        if (alice[i] != i) solved = false;
    }

    for (int i = 0; i < n; i++) {
        cin >> bob[i];
        bob[i]--;
    }

    if (solved) {
        cout << 1 << endl;
        return 0;
    }

    // O(2n) - we never visit a node twice
    bool can_bob = solve(); // dfs + dp
    ll aliceLCM = getLCM(alice_len);
    ll bobLCM = LLONG_MAX;

    if (aliceLCM > 1 && can_bob) {
        // O(n*log(count_of_cycles))
        for (int i = 0; i < n; i++) {
            // length of the cycle which visits the node bob[i]
            int currentLen = cycle_len[cycle_bob[i]];

            // if we first arrive at alice and then at bob
            int diff = temp_count_bob[i] - temp_count_alice[i];
            if (diff < 0) diff = INT_MAX;
            
            int isCycleStart = INT_MAX;
            if (cycle_bob[i] == i) isCycleStart = temp_count_bob[i];

            int backwards = currentLen - temp_count_alice[i] + temp_count_bob[i];

            int solution = min({
                isCycleStart,
                diff,
                backwards
            });

            // cout << "{" << solution << " " << currentLen << "}" << endl;
            bob_len.insert({ solution, currentLen });

            count_bob[i] = solution;
        }

        if (bob_len.size() == 1) {
            bobLCM = (*bob_len.begin()).first;
        } else {
            int cycles = bob_len.size();
            vector<ll> n(cycles), a(cycles);

            int i = 0;
            for (auto it = bob_len.begin(); it != bob_len.end(); it++, i++) {
                n[i] = (*it).second;
                a[i] = (*it).first;
            }
            
            bobLCM = CRT<ll>(n, a);
        }
    }
    
    if (aliceLCM == LLONG_MAX && bobLCM == LLONG_MAX) {
        cout << "huge" << endl;
        return 0;
    }

    if (bobLCM == LLONG_MAX) {
        cout << aliceLCM << endl;
    } else if (aliceLCM == LLONG_MAX) {
        cout << bobLCM << endl;
    } else {
        cout << min(aliceLCM, bobLCM) << endl;
    }
    
    return 0;
}