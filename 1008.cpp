#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n';
#define OUT(x) cout << x;
#define SP cout << ' ';
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

int grid[100][100];
int d_map[100][100][5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [g_sz, t_cap] = inputs<int, 2>();

    pii src, dst;
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            int t = input();
            switch (t) {
            case -1:
                src = {y, x};
                break;
            case -2:
                dst = {y, x};
                break;
            case 0:
                grid[y][x] = -1;
                break;
            default:
                grid[y][x] = t;
            }

            fill(d_map[y][x], d_map[y][x] + t_cap + 1, INT_MAX);
        }
    }

    priority_queue<pair<int, pair<pii, int>>> pq;
    pq.push({0, {src, 0}});
    d_map[src.first][src.second][0] = 0;

    while (pq.size()) {
        int cur_d = -pq.top().first;
        auto [y, x] = pq.top().second.first;
        int steps = pq.top().second.second;
        pq.pop();

        if (d_map[y][x][steps] < cur_d) {
            continue;
        }

        if (make_pair(y, x) == dst) {
            print(cur_d);
            return 0;
        }

        if (steps == t_cap) {
            continue;
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (min(ny, nx) < 0 || max(ny, nx) >= g_sz || grid[ny][nx] == -1) {
                continue;
            }

            int nxt_d = cur_d + grid[ny][nx];
            if (nxt_d < d_map[ny][nx][steps + 1]) {
                d_map[ny][nx][steps + 1] = nxt_d;
                pq.push({-nxt_d, {{ny, nx}, steps + 1}});
            }
        }
    }

    print(-1);
}