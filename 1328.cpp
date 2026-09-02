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

int n;
int ans[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    stack<pii> stk; // buildings who haven't yet seen anything
    FOR(i, input(n)) {
        int h = input();

        while (stk.size() && stk.top().first < h) {
            ans[stk.top().second] = i + 1;
            stk.pop();
        }

        stk.push({h, i});
    }

    FOR(i, n) {
        print(ans[i]);
    }
}