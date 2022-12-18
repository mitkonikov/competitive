#include <string>
#include <vector>
#include <queue>
using namespace std;

class DemonLord
{
    inline void umin(int &a, int b) {
        if (b < a) a = b;
    }
  public:
    int minimumManaCost(int S, int N, int P, vector<string> spells, vector<string> paths)
    {
        auto split = [](string& s) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ';') {
                    return make_pair<string, string>(s.substr(0, i), s.substr(i+1));
                }
            }
            return make_pair<string, string>("", "");
        };
        auto intize = [](pair<string, string> p) {
            return make_pair(stoi(p.first), stoi(p.second));
        };
        vector<pair<int, int>> sp(S);
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < S; i++) {
            sp[i] = intize(split(spells[i]));
        }
        for (int i = 0; i < paths.size(); i++) {
            auto p1 = split(paths[i]);
            auto p2 = split(p1.second);
            int u = stoi(p1.first); u--;
            int v = stoi(p2.first); v--;
            int c = stoi(p2.second);
            adj[u].push_back({ v, c });
            adj[v].push_back({ u, c });
        }
        const int MX = 60010;
        const int INF = 1e9;
        vector<vector<int>> dp(S+1, vector<int>(MX, INF));
        dp[0][0] = 0;
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < MX; j++) {
                umin(dp[i+1][j], dp[i][j]);
                if (j+sp[i].second < MX) {
                    umin(dp[i][j+sp[i].second], dp[i][j] + sp[i].first);
                    umin(dp[i+1][j+sp[i].second], dp[i][j] + sp[i].first);
                }
            }
        }
        int b = dp[S][MX-1];
        for (int i = MX - 1; i >= 0; i--) {
            b = min(b, dp[S][i]);
            umin(dp[S][i], b);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(N, INF);
        dist[0] = 0;
        pq.push({ 0, 0 });
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (auto v: adj[top.second]) {
                int cost = dp[S][v.second];
                if (dist[v.first] > dist[top.second] + cost) {
                    dist[v.first] = dist[top.second] + cost;
                    pq.push({ dist[v.first], v.first });
                }
            }
        }
        return (dist[N-1] == INF ? -1 : dist[N-1]);
    }
};
