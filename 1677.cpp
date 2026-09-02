#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define RANGE(i, s, e) for (int i = (s), _e = (e); i <= _e; ++i)
#define REP(n) for (int _ = 0, _n = (n); _ < _n; ++_)
#define DBG(x) cerr << #x << " = " << (x) << '\n'
#define OUT(x) cout << (x)
#define SP cout << ' '
#define NL cout << '\n'
using namespace std;
using pii = pair<int, int>;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); cout << '\n'; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }

const pii DIRS[] = {{1, 0}, {0, -1}, {0, 1}}; // d, l, r

int g_sz;
int grid[1000][1000];
int dp[1000][1000][3];

int f(int y, int x, int d) { 
    if (y == g_sz - 1 && x == y) {
        return grid[y][x];
    }

    int& res = dp[y][x][d];
    if (res != INT_MIN) {
        return res;
    }

    FOR(nxt_d, 3) {
        // going in the opposite direction means revisiting the previous tile
        if (d + nxt_d == 3) { 
            continue;
        }

        // when in last row should only go right
        if (y == g_sz - 1 && nxt_d != 2) {
            continue;
        }

        int ny = y + DIRS[nxt_d].first;
        int nx = x + DIRS[nxt_d].second;

        if (nx < 0 || nx == g_sz) {
            continue;
        }

        upmax(res, f(ny, nx, nxt_d));
    }

    return res += grid[y][x];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_sz);
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            grid[y][x] = input();
            FOR(i, 3) {
                dp[y][x][i] = INT_MIN; // safe sentinel
            }
        }
    }

    print(f(0, 0, 0));
}