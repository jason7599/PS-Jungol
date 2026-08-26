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

int g_h, g_w;
bool grid[100][100];
bool vis[100][100];

pii raycast(int y, int x, int dy, int dx) {
    do {
        y += dy;
        x += dx;
    } while (0 <= min(y, x) && y < g_h && x < g_w && !grid[y][x]);
    return {y, x};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            grid[y][x] = input<char>() == '#';
        }
    }

    auto [iy, ix] = raycast(0, 0, 0, 1);
    if (ix == g_w) {
        print(0);
        return 0;
    }

    ix--;

    queue<pii> q({{iy, ix}});
    vis[iy][ix] = true;

    for (int q_sz, moves = 1; (q_sz = q.size()); moves++) {
        REP(q_sz) {
            auto [y, x] = q.front();
            q.pop();

            for (const auto& [dy, dx] : DIRS) {
                auto [ny, nx] = raycast(y, x, dy, dx);

                if (nx == g_w) {
                    print(moves);
                    return 0;
                }

                if (min(ny, nx) < 0 || ny == g_h) {
                    continue;
                }

                ny -= dy;
                nx -= dx;
                
                if (!vis[ny][nx]) {
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    print(-1);
}