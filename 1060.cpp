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

int roots[100], sizes[100];

int find_root(int n) {
    return roots[n] == n ? n : roots[n] = find_root(roots[n]);
}

bool make_union(int i, int j) {
    i = find_root(i);
    j = find_root(j);

    if (i == j) return false;

    // keep i the bigger tree
    if (sizes[i] < sizes[j]) {
        swap(i, j);
    }

    roots[j] = i;
    sizes[i] += sizes[j];

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes = input();
    FOR(i, n_nodes) {
        roots[i] = i;
        sizes[i] = 1;
    }

    priority_queue<pair<int, pii>> pq;

    FOR(i, n_nodes) {
        FOR(j, n_nodes) {
            int w = input();
            if (i < j) {
                pq.push({-w, {i, j}});
            }
        }
    }

    int res = 0;
    for (int con = 0; con < n_nodes - 1;) {
        // assert(!pq.empty()); btw the CP website apparently disallows cassert??

        int w = -pq.top().first;
        auto [i, j] = pq.top().second;
        pq.pop();

        if (make_union(i, j)) {
            res += w;
            con++;
        }
    }

    print(res);
}