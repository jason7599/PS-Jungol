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

int n, len;
int arr[100'001];
unordered_map<int, int> idxs; // val -> idx
int prevs[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n, len);
    RANGE(i, 1, n) {
        int v = stoi(input<string>(), nullptr, 2);
        arr[i] = v;
        idxs[v] = i;
    }

    queue<int> q;
    q.push(1);
    prevs[1] = -1;

    while (q.size()) {
        int cur_i = q.front();
        q.pop();
        for (int b = 0; b < len; b++) {
            int nxt = arr[cur_i] ^ (1 << b);
            if (idxs.count(nxt)) {
                int nxt_i = idxs[nxt];
                if (!prevs[nxt_i]) {
                    prevs[nxt_i] = cur_i;
                    q.push(nxt_i);
                } 
            }
        }
    }

    REP(input()) {
        int dst = input();
        if (prevs[dst]) {
            stack<int> path;
            for (int i = dst; i != -1; i = prevs[i]) {
                path.push(i);
            }
            for (; path.size(); path.pop()) {
                OUT(path.top()); SP;
            }
            NL;
        } else {
            print(-1);
        }
    }
}