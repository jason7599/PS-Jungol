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

int n;
int arr[2][1000];
int dp[2][1000][16];

int f(int i, int j, int k) {
    if (k == 0) return 0;
    if (i == n) return 0;

    int& res = dp[j][i][k];
    if (res != -1) return res;

    res = arr[j][i] + f(i + 1, j, k - 1);
    if (k > 1) {
        upmax(res, arr[j][i] + arr[!j][i] + f(i + 1, !j, k - 2));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    int k = input();

    FOR(i, 2) {
        FOR(j, n) {
            input(arr[i][j]);
            fill(dp[i][j], dp[i][j] + k + 1, -1);
        }
    }

    print(f(0, 1, k));
}