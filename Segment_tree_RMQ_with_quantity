#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
 
#define y1 y3278
#define sz(v) int(v.size())
#define y2 y4368
#define y y4368232
#define x x43682322
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define tm tm3278
#define left left3278
#define right right3278
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class T> using Pair_indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long INF = 2000000000000000000;
const long long Maxll = 9223372036854775807;
const long long MOD = 1000000000000037;
const int MOD2 = 1100000009;
const int inf = 1000000000;
const long long q0 = 31;
const int differ = 'a' - 'A';
 
template<class T>
istream &operator>>(istream &in, vector<T> &a) {
    for (T &i: a) in >> i;
    return in;
}
 
template<class T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (T &i: a) out << i << ' ';
    out << '\n';
    return out;
}
 
template<class T>
ostream &operator<<(ostream &out, set<T> &a) {
    out << a.size() << '\n';
    for (T i: a) out << i << ' ';
    return out;
}
 
/// Actual code starts here
int t, n, m, k;
 
pair<int, int> tr[400000];
 
int left_son(int v) {
    return v * 2 + 1;
}
 
int right_son(int v) {
    return v * 2 + 2;
}
 
pair<int, int> comb(pair<int, int> x, pair<int, int> y) {
    if (x.ff > y.ff)
        return x;
    else if (x.ff < y.ff)
        return y;
    return make_pair(x.ff, x.ss + y.ss);
}
 
void relax(int v) {
    tr[v] = comb(tr[left_son(v)], tr[right_son(v)]);
}
 
void build(const vector<int> &base, int v = 0, int L = 0, int R = n) {
    if (R - L == 1) {
        tr[v] = make_pair(base[L], 1);
        return;
    }
    int M = (L + R) / 2;
    build(base, left_son(v), L, M);
    build(base, right_son(v), M, R);
    relax(v);
}
 
 
void upd(int pos, int val, int v = 0, int L = 0, int R = n) {
    if (R - L == 1) {
        tr[v] = make_pair(val, 1);
        return;
    }
    int M = (L + R) / 2;
    if (pos < M)
        upd(pos, val, left_son(v), L, M);
    else
        upd(pos, val, right_son(v), M, R);
    relax(v);
}
 
pair<int,int> get(int l, int r, int v = 0, int L = 0, int R = n) {
    if (l == L && r == R)
        return tr[v];
    int M = (L + R) / 2;
    pair<int, int> ans = make_pair(-inf, 0);
    if (M > l)
        ans = comb(ans, get(l, min(r, M), left_son(v), L, M));
    if (M < r)
        ans = comb(ans, get(max(l, M), r, right_son(v), M, R));
    return ans;
}
 
void VOLK() {
    cin >> n;
    vector<int> vec(n);
    cin >> vec;
    cin >> m;
    build(vec);
    for (int i = 0; i < m; i++) {
        int x, y;
        char type;
        cin >> type >>  x >> y;
        if (type == 'u')
            upd(x - 1, y);
        else {
            pair<int, int> ans = get(x - 1, y);
            cout << ans.ss << ' ';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    t = 1;
    //cin >> t;
    while (t--)
        VOLK();
}
