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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int n;
pii arr[1000]; // <weight, value>
int dp[1000][10'001];

long calls;
long hits;

/*
2 7
1 1
2 2
*/

int f(int i, int cap) {
    cout << "f(" << i << ", " << cap << ")\n";
    calls++;

    if (i == n) return 0;

    int &res = dp[i][cap];
    if (res != -1) {
        hits++;
        return res;
    }

    for (int x = 0; cap >= arr[i].first * x; x++) {
        upmax(res, x * arr[i].second + f(i + 1, cap - arr[i].first * x));
    }
    return res;
}

int f2(int i, int cap) {

    cout << "f(" << i << ", " << cap << ")\n";
    calls++;

    if (i == n || cap == 0) {
        return 0;
    }

    int& res = dp[i][cap];
    if (res != -1) {
        hits++;
        return res;
    }


    // Do not use this item.
    res = f2(i + 1, cap);

    // Use one copy, then potentially use it again.
    auto [weight, value] = arr[i];

    if (weight <= cap) {
        res = max(res, value + f2(i, cap - weight));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    int cap = input();
    
    FOR(i, n) {
        fill(dp[i], dp[i] + cap + 1, -1);
        input(arr[i].first, arr[i].second);
    }

    print(f(0, cap));
    DBG(hits)
    DBG(calls)

    print();

    hits = 0;
    calls = 0;
    memset(dp, -1, sizeof dp);

    print(f2(0, cap));
    DBG(hits)
    DBG(calls)

}