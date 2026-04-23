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

const int MAX_VAL = 20'000;

bool is_prime[MAX_VAL + 1];

void init() {
    is_prime[1] = true;
    fill(is_prime + 2, is_prime + MAX_VAL + 1, true);
    for (int i = 2; i * i <= MAX_VAL; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_VAL; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    init();

    int ans = -1, max_div = 0;
    REP(input()) {
        int x = input();
        for (int i = x; i > max_div; i--) {
            if (is_prime[i] && !(x % i)) {
                ans = x;
                max_div = i;
                break;
            }
        }
    }

    print(ans);
}