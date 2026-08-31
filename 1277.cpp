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

int g_sz;
bool obstacle[50][50];
bool is_main_path[50][50];

int vis[50][50]; // timestamp

bool is_oob(int y, int x) {
    return min(y, x) < 0 || max(y, x) >= g_sz;
}

bool mark_main_path(pii src, pii dst) {
    if (src == dst) return true;

    auto [y, x] = src;
    vis[y][x] = 1; // init timestamp is 1

    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (!is_oob(ny, nx) && !obstacle[ny][nx] && !vis[ny][nx]) {
            if (mark_main_path({ny, nx}, dst)) {
                is_main_path[y][x] = true;
                return true;
            }
        }
    }

    return false;
}

bool path_exists(pii src, pii dst, int vis_id) {
    if (src == dst) return true;

    auto [y, x] = src;
    vis[y][x] = vis_id;

    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (!is_oob(ny, nx) && !obstacle[ny][nx] && vis[ny][nx] != vis_id) {
            if (path_exists({ny, nx}, dst, vis_id)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_sz);

    pii src, dst;
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            switch (input<char>()) {
            case 'S':
                src = {y, x};
                break;
            case 'E':
                dst = {y, x};
                break;
            case '#':
                obstacle[y][x] = true;
            }
        }
    }

    mark_main_path(src, dst);

    int nxt_vis_id = 2;
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            if (make_pair(y, x) == src) OUT('S');
            else if (make_pair(y, x) == dst) OUT('E');
            else if (obstacle[y][x]) OUT('#');
            else if (!is_main_path[y][x]) OUT('.');
            else {
                obstacle[y][x] = true;
                OUT(path_exists(src, dst, nxt_vis_id++) ? '.' : 'o');
                obstacle[y][x] = false;
            }
        }
        NL;
    }
}