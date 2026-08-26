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

bool chk(const vector<int>& arr, int n, int k) {
    if (arr.empty()) {
        return n - 1 >= k;
    }

    int left = 2;

    int gap = arr.front();
    if (gap >= 2 * k) {
        return true;
    }

    if (gap >= k) {
        --left;
    }

    // Internal gaps.
    for (int i = 1; i < (int)arr.size(); i++) {
        gap = arr[i] - arr[i - 1];

        // existing -- new -- new -- existing
        if (gap >= 3 * k) {
            return true;
        }

        // existing -- new -- existing
        if (gap >= 2 * k) {
            if (!--left) {
                return true;
            }
        }
    }

    // Right edge.
    gap = n - 1 - arr.back();

    if (gap >= 2 * k) {
        return true;
    }

    if (gap >= k) {
        if (!--left) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n = input();

    vector<int> arr;
    int mn = n - 1;

    FOR(i, n) {
        if (input<char>() == '1') {
            if (!arr.empty()) {
                upmin(mn, i - arr.back());
            }

            arr.push_back(i);
        }
    }

    int ans = 0;

    for (int l = 1, r = mn; l <= r;) {
        int m = (l + r) / 2;

        if (chk(arr, n, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    print(ans);
}