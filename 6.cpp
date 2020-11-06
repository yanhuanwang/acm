#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <cassert>
#include <iostream>
#include <sstream>
#include <utility>
#include <bitset>
#include <iomanip>
#include <random>
using namespace std;


//output overload BEGIN
// using uint = unsigned int;
// using ll = long long;
// using ull = unsigned long long;
// constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
// template <class T> using V = vector<T>;
// template <class T> using VV = V<V<T>>;

// #define LOCAL
// #ifdef LOCAL

// ostream& operator<<(ostream& os, __int128_t x) {
//     if (x < 0) {
//         os << "-";
//         x *= -1;
//     }
//     if (x == 0) {
//         return os << "0";
//     }
//     string s;
//     while (x) {
//         s += char(x % 10 + '0');
//         x /= 10;
//     }
//     reverse(s.begin(), s.end());
//     return os << s;
// }
// ostream& operator<<(ostream& os, __uint128_t x) {
//     if (x == 0) {
//         return os << "0";
//     }
//     string s;
//     while (x) {
//         s += char(x % 10 + '0');
//         x /= 10;
//     }
//     reverse(s.begin(), s.end());
//     return os << s;
// }

// template <class T, class U>
// ostream& operator<<(ostream& os, const pair<T, U>& p);
// template <class T> ostream& operator<<(ostream& os, const V<T>& v);
// template <class T> ostream& operator<<(ostream& os, const deque<T>& v);
// template <class T, size_t N>
// ostream& operator<<(ostream& os, const array<T, N>& a);
// template <class T> ostream& operator<<(ostream& os, const set<T>& s);
// template <class T, class U>
// ostream& operator<<(ostream& os, const map<T, U>& m);

// template <class T, class U>
// ostream& operator<<(ostream& os, const pair<T, U>& p) {
//     return os << "P(" << p.first << ", " << p.second << ")";
// }

// template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
//     os << "[";
//     bool f = false;
//     for (auto d : v) {
//         if (f) os << ", ";
//         f = true;
//         os << d;
//     }
//     return os << "]";
// }

// template <class T> ostream& operator<<(ostream& os, const deque<T>& v) {
//     os << "[";
//     bool f = false;
//     for (auto d : v) {
//         if (f) os << ", ";
//         f = true;
//         os << d;
//     }
//     return os << "]";
// }
// template <class T, size_t N>
// ostream& operator<<(ostream& os, const array<T, N>& a) {
//     os << "[";
//     bool f = false;
//     for (auto d : a) {
//         if (f) os << ", ";
//         f = true;
//         os << d;
//     }
//     return os << "]";
// }

// template <class T> ostream& operator<<(ostream& os, const set<T>& s) {
//     os << "{";
//     bool f = false;
//     for (auto d : s) {
//         if (f) os << ", ";
//         f = true;
//         os << d;
//     }
//     return os << "}";
// }

// template <class T, class U>
// ostream& operator<<(ostream& os, const map<T, U>& s) {
//     os << "{";
//     bool f = false;
//     for (auto p : s) {
//         if (f) os << ", ";
//         f = true;
//         os << p.first << ": " << p.second;
//     }
//     return os << "}";
// }

// struct PrettyOS {
//     ostream& os;
//     bool first;

//     template <class T> auto operator<<(T&& x) {
//         if (!first) os << ", ";
//         first = false;
//         os << x;
//         return *this;
//     }
// };
// template <class... T> void dbg0(T&&... t) {
//     (PrettyOS{cerr, true} << ... << t);
// }
// #define dbg(...)                                            \
//     do {                                                    \
//         cerr << "LINE("<<__LINE__ << ")" << " : " << #__VA_ARGS__ << " = "; \
//         dbg0(__VA_ARGS__);                                  \
//         cerr << endl;                                       \
//     } while (false);
// #else
// #define dbg(...)
// #endif
//output overload END
#define ll long long
#define int ll
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ALL(a) begin(a), end(a)

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

const ll mod=1000000007;

template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) {
	return a<b?a=b, 1:0;
}

// ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
// 	while(lb<rb) {
// 		ll mb=(lb+rb)/2;
// 		f(mb)?rb=mb:lb=mb+1;
// 	}
// 	return lb;
// }
// ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
// 	while(lb<rb) {
// 		ll mb=(lb+rb+1)/2;
// 		f(mb)?lb=mb:rb=mb-1;
// 	}
// 	return lb;
// }

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

template<class T> string to_string(T v);
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class H, class T> string to_string(pair<H,T> p){
    string res="P{";
    res+=to_string(p.first)+","+to_string(p.second)+"}";
    return res;
}

template<class H, class T> string to_string(map<H,T> m){
    bool f=1;
    string res="map{";
    EACH(x, m) {
        if(!f)
			res+=',';
		f=0;
        res+=to_string(x.first)+":"+to_string(x.second);
    }
    res+="}";
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res="{";
    EACH(x, v) {
		if(!f)
			res+=',';
		f=0;
		res+=to_string(x);
	}
    res+="}";
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
    cout<<x;
}
template<class H, class... T> void write(const H& h, const T&... t) {
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
    // cerr << h;
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_random() {
    static uniform_int_distribution<int> dist(0, 1e9 + 6);
    return dist(rng);
}
template<class T>
void make_unique(T & v) {
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
}
void lower(string &s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
void upper(string &s){
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node{
    int val;
    node*left;
    node*right;
    node(int a){
        val=a;
        left=NULL;
        right=NULL;
    }
};

// ostream& operator<<(ostream& os, const node p) {
//     cout<<"node: ";
//     return os << p.val;
// }
// ostream& operator<<(ostream& os, const node* p) {
//     cout<<"node*: ";
//     return os << p->val;
// }
signed main(){
    fast_io();
    // string s;
    vector<int>a={1,2,3,4};
    // read(a);
    // cout<<a<<endl;
    dbg(a);
    // dbg0(a);

    // int b=3,c=3;
    // cout<<b<<c<<endl;
    // dbg(b,c);
    // // dbg1(b,c);

    pair<int,string>d={11,"ddd"};
    dbg(d);

    set<char>s={'a','c'};
    dbg(s);

    set<vector<int>>ss;
    ss.insert({1,2,3});
    ss.insert({3,4,5});
    dbg(ss);

    map<int,int>m;
    m[2]=3;
    dbg(m);

    map<int,vector<string>>mm;
    mm[2].push_back("sss");
    mm[3].push_back("www");
    dbg(mm);

    // node aa(1);
    // node* bb=new node(33);
    // // cout<<aa;
    // // cout<<bb;
    // print(aa,bb);
    // dbg(aa,bb);
    return 0;
}