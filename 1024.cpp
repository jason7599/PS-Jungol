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
int grid[500][500];
int mem[500][500];

int f(int y, int x) {
    if (y == g_h - 1 && x == g_w - 1) return 1;

    int &res = mem[y][x];
    if (res != -1) return res;
    
    res = 0;
    
    for (const auto &[dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        if (min(ny, nx) >= 0 && ny < g_h && nx < g_w && grid[y][x] > grid[ny][nx]) {
            res += f(ny, nx);
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
            mem[y][x] = -1;
        }
    }

    print(f(0, 0));
}