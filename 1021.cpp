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

vector<pii> reqs[101]; // <pre, cnt>
int ans[101];

void f(int n, int mult) {
    if (reqs[n].empty()) {
        ans[n] += mult;
    } else {
        for (auto [pre, cnt] : reqs[n]) {
           f(pre, mult * cnt);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_nodes = input();
    REP(input()) {
        auto [n, p, c] = inputs<int, 3>();
        reqs[n].push_back({p, c});
    }

    f(n_nodes, 1);

    RANGE(i, 1, n_nodes - 1) {
        if (ans[i]) {
            print(i, ans[i]);
        }
    }
}