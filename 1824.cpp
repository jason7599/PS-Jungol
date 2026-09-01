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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

const int G_SZ = 9;

int grid[G_SZ][G_SZ];

bool row_vis[G_SZ][10];
bool col_vis[G_SZ][10];
bool box_vis[G_SZ / 3][G_SZ / 3][10];

bool can_set(int y, int x, int v) {
    return !row_vis[y][v] && !col_vis[x][v] && !box_vis[y / 3][x / 3][v];
}

void set_state(int y, int x, int v, bool b) {
    row_vis[y][v] = b;
    col_vis[x][v] = b;
    box_vis[y / 3][x / 3][v] = b;
}

bool solve(const vector<pii>& zeroes, int idx) {
    if (idx == zeroes.size()) {
        return true;
    }

    auto [y, x] = zeroes[idx];

    RANGE(i, 1, 9) {
        if (can_set(y, x, i)) {
            set_state(y, x, i, true);
            if (solve(zeroes, idx + 1)) {
                grid[y][x] = i;
                return true;
            }
            set_state(y, x, i, false);
        }
    }
    
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<pii> zeroes;
    FOR(y, G_SZ) {
        FOR(x, G_SZ) {
            int v = grid[y][x] = input();
            if (!v) {
                zeroes.push_back({y, x});
            } else {
                set_state(y, x, v, true);
            }
        }
    }

    solve(zeroes, 0);

    FOR(y, G_SZ) {
        FOR(x, G_SZ) {
            OUT(grid[y][x]); SP;
        }
        NL;
    }
}