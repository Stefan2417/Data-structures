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
 
int tr[8000000];
int gift[8000000];
 
int left_son(int v) {
    return v * 2 + 1;
}
 
int right_son(int v) {
    return v * 2 + 2;
}
 
void relax(int v) {
    tr[v] = min(tr[left_son(v)] + gift[left_son(v)], tr[right_son(v)] + gift[right_son(v)]);
}
 
 
void Push(int v = 0) {
    tr[v] += gift[v];
    gift[left_son(v)] += gift[v];
    gift[right_son(v)] += gift[v];
    gift[v] = 0;
}
 
void add(int l, int r, int val, int v = 0, int L = 0, int R = n) {
    if (l == L && r == R) {
        gift[v] += val;
        Push(v);
        return;
    }
    int M = (L + R) / 2;
    Push(v);
    if (M > l)
        add(l, min(r, M), val, left_son(v), L, M);
    if (M < r)
        add(max(l, M), r, val, right_son(v), M, R);
    relax(v);
}
 
int get(int l, int r, int v = 0, int L = 0, int R = n) {
    if (L == l && R == r)
        return tr[v] + gift[v];
    int M = (L + R) / 2;
    int ans = inf;
    Push(v);
    if (M > l)
        ans = min(ans, get(l, min(M, r), left_son(v), L, M));
    if (M < r)
        ans = min(ans, get(max(l, M), r, right_son(v), M, R));
    return ans;
}
 
void VOLK() {
    cin >> n >> k >> m;
    fill(tr, tr + 8000000, k);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int ans = get(x, y);
        // cout << ans << '\n';
        if (ans > 0) {
            cout << 1 << '\n';
            add(x, y, -1);
        }
        else
            cout << 0 << '\n';
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
