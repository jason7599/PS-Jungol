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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul | senw

struct State {
    int y, x;
    int d;
};

int parse_dir(int d) {
    switch (d) {
    case 1: return 1;
    case 2: return 3;
    case 3: return 0;
    case 4: return 2;
    }
    assert(0);
}

State input_state() {
    auto [y, x, d] = inputs<int, 3>();
    return State{--y, --x, parse_dir(d)};
}

int g_h, g_w;
bool grid[100][100];
bool vis[100][100][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            input(grid[y][x]);
        }
    }

    State src = input_state(), dst = input_state();
    queue<State> q({src});
    vis[src.y][src.x][src.d] = true;

    for (int q_sz, moves = 0; (q_sz = q.size()); moves++) {
        REP(q_sz) {
            auto [y, x, d] = q.front();
            q.pop();

            if (y == dst.y && x == dst.x && d == dst.d) {
                print(moves);
                return 0;
            }

            auto [dy, dx] = DIRS[d];
            for (int ny = y + dy, nx = x + dx, t = 1; t <= 3 && 0 <= min(ny, nx) && ny < g_h && nx < g_w && !grid[ny][nx]; t++, ny += dy, nx += dx) {
                if (!vis[ny][nx][d]) {
                    vis[ny][nx][d] = true;
                    q.push({ny, nx, d});
                }
            }

            for (int nd : {(d + 1) % 4, (d + 3) % 4}) {
                if (!vis[y][x][nd]) {
                    vis[y][x][nd] = true;
                    q.push({y, x, nd});
                }
            }
        }
    }

    assert(0);
}