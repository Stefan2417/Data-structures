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
const long long MOD2 = 1000000000000037;
const int MOD = 1000000007;
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

int h[100005];
int q[100005];


int mul (int a, int b) {
    return (int) (1LL * a * b % MOD);
}

int sub (int a, int b) {
    if (a - b < 0)
        return a - b + MOD;
    else
        return a - b;
}

int add (int a,int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    else
        return a + b;
}


void Russian_hash(string str) {
    ll curh = 0;
    for (int i = 0; i < str.size(); i++) {
        curh = add(mul(curh, q0), str[i]);
        h[i] = curh;
    }
    q[0] = 1;
    for (int i = 1; i <= str.size(); i++)
        q[i] = mul(q[i - 1], q0);
}

int get(int l, int r) {
    int ans = h[r];
    if (l)
        ans = sub(ans, mul(h[l - 1], q[r - l + 1]));
    return ans;
}

void VOLK() {
    string str;
    cin >> str;
    Russian_hash(str);
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
