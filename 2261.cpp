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

int n, bl;
int arr[1001];
int prevs[1001];
unordered_map<int, int> idxs;

void bt(int src, int dst) {
    if (src != dst) {
        bt(src, prevs[dst]);
    }
    OUT(dst); SP;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    input(n, bl);
    RANGE(i, 1, n) {
        int v = stoi(input<string>(), nullptr, 2);
        arr[i] = v;
        idxs[v] = i;
    }

    auto [src, dst] = inputs<int, 2>();
    prevs[src] = -1;

    for (queue<int> q({src}); q.size();) {
        int x = q.front();
        q.pop();

        if (x == dst) {
            break;
        }

        for (int b = 0; b < bl; b++) {
            int nxt = arr[x] ^ (1 << b);
            if (idxs.count(nxt)) {
                int nxt_i = idxs[nxt];
                if (!prevs[nxt_i]) {
                    prevs[nxt_i] = x;
                    q.push(nxt_i);
                }
            }
        }
    }

    if (!prevs[dst]) {
        print(-1);
    } else {
        bt(src, dst);
        NL;
    }
}