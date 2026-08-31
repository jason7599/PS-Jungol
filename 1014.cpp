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

string pattern;
string texts[2];

int dp[20][100][2]; // [pattern idx][text char idx][text arr idx]

int f(int p_idx, int c_idx, int t_idx) {
    if (p_idx == pattern.length()) {
        return 1;
    }

    if (c_idx == texts[0].length()) {
        return 0;
    }

    int& res = dp[p_idx][c_idx][t_idx];
    if (res != -1) {
        return res;
    }

    res = f(p_idx, c_idx + 1, t_idx);

    if (pattern[p_idx] == texts[t_idx][c_idx]) {
        res += f(p_idx + 1, c_idx + 1, !t_idx);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(pattern, texts[0], texts[1]);

    memset(dp, -1, sizeof dp);

    print(f(0, 0, 0) + f(0, 0, 1));
}