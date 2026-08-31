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
int dmap[1000][1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);

    queue<pii> q;
    REP(input()) {
        auto [y, x] = inputs<int, 2>();
        y--, x--;
        dmap[y][x] = 1;
        q.push({y, x});
    }

    for (int q_sz, dist = 2; (q_sz = q.size()); dist++) {
        REP(q_sz) {
            auto [y, x] = q.front();
            q.pop();

            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;
                
                if (min(ny, nx) < 0 || ny == g_h || nx == g_w) {
                    continue;
                }

                if (dmap[ny][nx] == 0) {
                    dmap[ny][nx] = dist;
                    q.push({ny, nx});
                }
            }
        }
    }

    FOR(y, g_h) {
        FOR(x, g_w) {
            OUT(dmap[y][x] - 1);
            SP;
        }
        NL;
    }
}