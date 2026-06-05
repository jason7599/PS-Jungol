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

int pos[25];
bool marked[5][5];
int ord[25];

bool chk(int y, int x, int dy, int dx) {
    for (; min(y, x) >= 0 && max(y, x) < 5; y += dy, x += dx) {
        if (!marked[y][x]) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, 25) {
        pos[input() - 1] = i;
    }

    FOR(i, 25) {
        ord[i] = input() - 1;
    }

    int cnt = 0;
    FOR(i, 25) {
        int y = pos[ord[i]] / 5, x = pos[ord[i]] % 5;

        marked[y][x] = true;

        cnt += chk(y, 0, 0, 1);
        cnt += chk(0, x, 1, 0);

        if (y == x) cnt += chk(0, 0, 1, 1);
        if (y + x == 4) cnt += chk(4, 0, -1, 1); 

        if (cnt >= 3) {
            print(i + 1);
            break;
        }
    }
}