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

int n, arr[300];

bool chk(int mx, int n_groups) {
    int sm = 0;
    n_groups--;
    FOR(i, n) {
        if (sm + arr[i] > mx) {
            if (!n_groups--) {
                return false;
            }
            sm = arr[i];
        } else {
            sm += arr[i];
        }
    }
    
    return true;
}

void show(int mx, int n_groups) {
    int sm = 0;
    int cnt = 1;

    FOR(i, n) {
        // Must start a new group if:
        // 1. adding arr[i] exceeds mx
        // 2. remaining elements must each occupy their own group
        if ((sm + arr[i] > mx || n - i == n_groups)) {
            OUT(cnt); SP;
            n_groups--;
            sm = 0;
            cnt = 0;
        }

        sm += arr[i];
        cnt++;
    }

    print(cnt);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(n);
    int n_groups = input();
    int sm = 0;
    int mn = 0;

    FOR(i, n) {
        sm += input(arr[i]);
        upmax(mn, arr[i]);
    }

    int ans{};
    for (int l = mn, r = sm; l <= r;) {
        int m = (l + r) >> 1;
        if (chk(m, n_groups)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    print(ans);
    show(ans, n_groups);
}