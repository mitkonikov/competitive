#define ll long long

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    const int N = gridSize;
    const int M = gridColSize[0];
    int after_mod = grid[0][0] % x;
    int ok = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ok &= (grid[i][j] % x == after_mod);
        }
    }
    if (!ok) return -1;
    const int MX = 10050;
    int* events = calloc(MX, sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            events[grid[i][j]]++;
        }
    }
    ll count_right = N * M;
    ll count_left = 0;
    ll operations = 0;
    ll current_count = 0;
    for (int i = after_mod; i < MX; i += x) {
        operations += current_count * events[i];
        current_count++;
    }
    ll ans = 1e9 + 100;
    for (int i = after_mod; i < MX; i += x) {
        if (operations < ans) ans = operations;
        count_left += events[i];
        operations += count_left;
        count_right -= events[i];
        operations -= count_right;
    }
    free(events);
    return (int)ans;
}