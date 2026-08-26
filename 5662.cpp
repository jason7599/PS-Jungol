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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n = input();

    int mx, mn, mx_cur, mn_cur, tot;
    mx = mn = mx_cur = mn_cur = tot = input();

    REP(n - 1) {
        int x = input();
        tot += x;

        if (mx_cur > 0) {
            mx_cur += x;
        } else {
            mx_cur = x;
        }

        if (mn_cur < 0) {
            mn_cur += x;
        } else {
            mn_cur = x;
        }

        upmax(mx, mx_cur);
        upmin(mn, mn_cur);
    }

    if (mn == tot) { 
        print(mx);
    } else {
        print(max(mx, tot - mn));
    }
}