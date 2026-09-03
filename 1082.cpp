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

int g_h, g_w;
bool vis[50][50];

bool is_oob(int y, int x) {
    return min(y, x) < 0 || y >= g_h || x >= g_w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(g_h, g_w);
    
    pii src, dst;
    queue<pii> fire_q;

    FOR(y, g_h) {
        FOR(x, g_w) {
            switch (input<char>()) {
            case 'S':
                src = {y, x};
                break;
            case 'D':
                dst = {y, x};
                break;

            case '*':
                fire_q.push({y, x});
                // fall thru, treat fire as obstacle
            case 'X':
                vis[y][x] = true;
            }
        }
    }

    queue<pii> q({src});
    vis[src.first][src.second] = true;
    for (int moves = 0; q.size(); moves++) {
        int t = fire_q.size();
        REP(t) {
            auto [y, x] = fire_q.front();
            fire_q.pop();

            for (auto [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (!is_oob(ny, nx) && !vis[ny][nx] && make_pair(ny, nx) != dst) {
                    vis[ny][nx] = true;
                    fire_q.push({ny, nx});
                }
            }
        }

        t = q.size();
        REP(t) {
            auto [y, x] = q.front();
            q.pop();

            for (auto [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (!is_oob(ny, nx) && !vis[ny][nx]) {
                    vis[ny][nx] = true;
                    q.push({ny, nx});

                    if (q.back() == dst) {
                        print(moves + 1);
                        return 0;
                    }
                }
            }
        }
    }

    print("impossible");
}