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
const int logg = 20;

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
int t, n, m, k, timer;
vector<int> g[100005];
int tin[100005], tout[100005];
int up[100005][logg + 1];

void dfs(int v, int p) {
    tin[v] = timer++;
    up[v][0] = p;
    for (int i = 1; i <= logg; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto i : g[v])
        if (i != p)
            dfs(i, v);

    tout[v] = timer++;
}

bool upper(int x, int y) {
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int LCA(ll x, ll y) {
    if (upper(x, y))
        return x;
    if (upper(y, x))
        return y;
    for (int i = logg; i >= 0; i--)
        if (!upper(up[x][i], y))
            x = up[x][i];
    return up[x][0];
}


void VOLK() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    dfs(0, 0);
    ll x, y, z, v, v2;
    cin >> v >> v2 >> x >> y >> z;
    ll res = LCA(v, v2);
    ll cur = res;
    for (int i = 1; i < m; i++) {
        v = (x * v + y * v2 + z) % n;
        v2 = (x * v2 + y * v + z) % n;
        cur = LCA((v + cur) % n, v2);
        res += cur;
    }
    cout << res;
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
