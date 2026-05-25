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

vector<bool> sieve(int range) {
    vector<bool> is_prime(range + 1, true);

    is_prime[1] = false;
    for (int i = 2; i * i <= range; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= range; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_players, end_num, targ_player] = inputs<int, 3>();

    auto is_prime = sieve(end_num);

    int cnt = 0;
    RANGE(i, 1, end_num) {
        if (is_prime[i] && (i - 1) % n_players == targ_player) {
            cnt++;
        }
    }
    print(cnt);
}