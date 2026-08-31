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

int roots[200'000];
int sizes[200'000];

int find_root(int i) {
    return roots[i] == i ? i : roots[i] = find_root(roots[i]);
}

bool make_union(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    if (a == b) return false;

    if (sizes[a] > sizes[b]) {
        roots[b] = a;
        sizes[a] += sizes[b];
    } else {
        roots[a] = b;
        sizes[b] += sizes[a];
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes = input();
    
    priority_queue<pair<int, pii>> pq;

    int total = 0;
    REP(input()) {
        auto [a, b, w] = inputs<int, 3>();
        pq.push({-w, {a, b}});
        total += w;
        roots[a] = a;
        roots[b] = b;
        sizes[a] = sizes[b] = 1;
    }

    int cost_sum = 0;
    for (int conn = 0; conn < n_nodes - 1;) {
        int w = -pq.top().first;
        auto [a, b] = pq.top().second;
        pq.pop();

        if (make_union(a, b)) {
            conn++;
            cost_sum += w;
        }
    }

    print(total - cost_sum);
}