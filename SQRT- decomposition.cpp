#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("fast-math")
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
template <class T> using Pair_indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long INF = 2000000000000000000;
const long long Maxll = 9223372036854775807;
const long long MOD = 1000000000000037;
const long long MOD2 = 1000000000 + 7;
const long long q0 = 239;
const int differ = 'a' - 'A';
template <class T>
istream& operator >> (istream &in, vector <T> &a)
{
    for (T &i: a) in >> i;
    return in;
}
template <class T>
ostream& operator << (ostream &out, vector <T> &a)
{
    for (T &i: a) out << i;
    out << '\n';
    return out;
}
template <class T>
ostream& operator << (ostream &out, set <T> &a)
{
    //out << a.size() << '\n';
    for (T i: a) out << i << ' ';
    return out;
}
/// Actual code starts here
int t, m, n;

string str;

ll iron_branch[1000];

ll vec[100005];

int sz;

void make_sz() {
    sz = (int) sqrt(n) + 1;
}

void make_iron_branch() {
    for (int i = 0;i < n;i++)
        iron_branch[i / sz] += vec[i];
}

void update(int l, int r)  {
    iron_branch[l / sz] -= vec[l];
    iron_branch[l / sz] += r;
    vec[l] = r;
}

ll get(int l, int r) {
    ll ans = 0;
    while (l <= r) {
        if (l % sz == 0 && l + sz - 1 <= r) {
            ans += iron_branch[l / sz];
            l += sz;
        }
        else {
            ans += vec[l];
            l++;
        }
    }
    return ans;
}

void Kloynada() {
    freopen ("rsq.in", "r", stdin);
    freopen ("rsq.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++)
        cin >> vec[i];
    make_sz();
    make_iron_branch();
    for (int i = 0;i < m;i++) {
        int l, r;
        bool f;
        cin >> f >> l >> r;
        l--;
        if (!f) {
            r--;
            cout << get(l, r) << '\n';
        }
        else
            update(l, r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    // cin >> t;
    while (t--)
        Kloynada();
}

