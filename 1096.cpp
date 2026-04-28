#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n';
#define OUT(x) cout << x << ' ';
#define NL cout << '\n';
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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int g_h, g_w;
int grid[700][700];
bool vis[700][700];

bool is_peak(int iy, int ix) {
    const int h = grid[iy][ix];
    vis[iy][ix] = true;

    bool res = true;
    for (queue<pii> q({{iy, ix}}); q.size(); q.pop()) {
        auto [y, x] = q.front();

        for (int ny = max(y - 1, 0); ny <= min(y + 1, g_h - 1); ny++) {
            for (int nx = max(x - 1, 0); nx <= min(x + 1, g_w - 1); nx++) {
                if (grid[ny][nx] > h) {
                    // explore the whole cluster even if we already know the result is false. 
                    // no early termination so that we always mark visited on a given cluster
                    res = false; 
                } else if (grid[ny][nx] == h && !vis[ny][nx]) {
                    q.push({ny, nx});
                    vis[ny][nx] = true; // vis check is only for equal height cluster
                }
            }
        }
    }
    
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            input(grid[y][x]);
        }
    }

    int ans = 0;
    FOR(y, g_h) {
        FOR(x, g_w) {
            ans += !vis[y][x] && is_peak(y, x);
        }
    }

    print(ans);
}