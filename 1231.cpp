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

struct PhoneNum {
    string country_code;
    string area_code;
    string local_num;

    friend ostream &operator<<(ostream &os, const PhoneNum &pn) {
        os << pn.country_code << '-' << pn.area_code << '-' << pn.local_num;
        return os;
    }
};

PhoneNum parse_num(const string& str) {
    size_t t = str.find('-', 4);
    return PhoneNum{str.substr(0, 3), str.substr(4, t - 4), str.substr(t + 1)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    unordered_map<string, int> country_ranks;

    int n_numbers = input();
    FOR(i, 6) {
        country_ranks[string("01") + input<char>()] = i;
    }

    vector<PhoneNum> phone_nums(n_numbers);
    for (auto &pn : phone_nums) {
        pn = parse_num(input<string>());
    }

    sort(phone_nums.begin(), phone_nums.end(), [&](const PhoneNum &lhs, const PhoneNum &rhs) {
        int lr = country_ranks[lhs.country_code];
        int rr = country_ranks[rhs.country_code];

        if (lr == rr) {
            if (lhs.area_code == rhs.area_code) {
                return lhs.local_num < rhs.local_num;
            }
            if (lhs.area_code.length() != rhs.area_code.length()) {
                return lhs.area_code.length() == 4;
            }
            return lhs.area_code < rhs.area_code;
        }

        return lr < rr;
    });

    for (auto &pn : phone_nums) {
        print(pn);
    }
}