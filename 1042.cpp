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

int conv10(const string &str, int base) {
    int res = 0;

    for (int i = str.length() - 1, b = 1; i >= 0; i--, b *= base) {
        int v;
        if (isdigit(str[i])) v = str[i] - '0';
        else v = str[i] - 'A' + 10;
        res += v * b;
    }

    return res;
}

string convb(int val, int base) {
    string res;

    for (; val; val /= base) {
        int t = val % base;
        if (t < 10) res += '0' + t;
        else res += 'A' + t - 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [base, lhs, rhs] = inputs<int, string, string>();

    int sm = conv10(lhs, base) + conv10(rhs, base);
    print(sm);
    print(convb(sm, base));
}