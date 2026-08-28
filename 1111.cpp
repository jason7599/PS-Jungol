#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
#define OUT(x) cout << x
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

int grid[100][100];
int dmap[100][100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int g_sz = input();
    auto [dst_y, dst_x] = inputs<int, 2>();
    dst_y--, dst_x--;

    priority_queue<pair<int, pii>> pq;
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            input(grid[y][x]);
            if (min(y, x) == 0 || max(y, x) == g_sz - 1) {
                int c = grid[y][x] * grid[y][x];
                dmap[y][x] = c;
                pq.push({-c, {y, x}});
            } else {
                dmap[y][x] = INT_MAX;
            }
        }
    }

    while (pq.size()) {
        int cur_d = -pq.top().first;
        auto [y, x] = pq.top().second;
        pq.pop();

        if (cur_d > dmap[y][x]) {
            continue;
        }

        if (y == dst_y && x == dst_x) {
            break;
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (min(ny, nx) < 0 || max(ny, nx) == g_sz) {
                continue;
            }

            int nxt_d = cur_d;

            int delta = grid[ny][nx] - grid[y][x];
            if (delta > 0) {
                nxt_d += delta * delta;
            } else {
                nxt_d += -delta;
            }

            if (dmap[ny][nx] > nxt_d) {
                dmap[ny][nx] = nxt_d;
                pq.push({-nxt_d, {ny, nx}});
            }
        }
    }

    print(dmap[dst_y][dst_x]);
}