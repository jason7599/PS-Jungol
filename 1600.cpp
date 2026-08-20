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
int grid[300][300];

int vis[300][300];

void dfs(int y, int x, int vis_id) {
    vis[y][x] = vis_id;
    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        // oob check unnecessary due to constraint
        if (grid[ny][nx] > 0 && vis[ny][nx] != vis_id) {
            dfs(ny, nx, vis_id);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);

    queue<pii> q;
    FOR(y, g_h) {
        FOR(x, g_w) {
            if (input(grid[y][x])) {
                q.push({y, x});
            }
        }
    }

    int ans = 0;
    for (int time = 1; q.size(); time++) {
        queue<pii> chk_q;
        
        for (int q_size = q.size(); q_size > 0; q_size--) {
            auto [y, x] = q.front();
            q.pop();

            int cnt = 0;
            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;
                if (grid[ny][nx] == 0) {
                    if (++cnt > grid[y][x]) {
                        break;
                    }
                }
            }

            if (grid[y][x] > cnt) {
                grid[y][x] -= cnt;
                q.push({y, x});
            } else {
                grid[y][x] = -1;
                chk_q.push({y, x});
            }
        }

        int vis_id = 1;
        while (chk_q.size()) {
            auto [y, x] = chk_q.front();
            chk_q.pop();

            grid[y][x] = 0;

            int v = 0;
            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (grid[ny][nx] <= 0) {
                    continue;
                }

                if (vis[ny][nx] == 0) {
                    if (v != 0) {
                        ans = time;
                        goto brk;
                    }
                    dfs(ny, nx, vis_id);
                    v = vis_id++;
                } else {
                    if (v) {
                        if (v != vis[ny][nx]) {
                            ans = time;
                            goto brk;
                        }
                    } else {
                        v = vis[ny][nx];
                    }
                }
            }
        }

        memset(vis, 0, sizeof vis);
    }

brk:
    print(ans);
}