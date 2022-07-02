#include "bits/stdc++.h"

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str; 

typedef pair<int,int> pi;
typedef pair<pi, int> pii;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
template<class T> using V = vector<T>; 
template<class T, size_t SZ> using AR = array<T,SZ>; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define revs(x) reverse(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

template<class T> bool ckmin(T& a, const T& b) { 
        return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
        return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) { 
        // note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
        hi ++; assert(lo <= hi); // assuming f is increasing
        while (lo < hi) { // find first index such that f is true 
                T mid = half(lo+hi);
                f(mid) ? hi = mid : lo = mid+1; 
        } 
        return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
        lo --; assert(lo <= hi); // assuming f is decreasing
        while (lo < hi) { // find first index such that f is true 
                T mid = half(lo+hi+1);
                f(mid) ? lo = mid : hi = mid-1;
        } 
        return lo;
}
template<class T> void remDup(vector<T>& v) { 
        sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
        #ifdef LOCAL
                return b ? "true" : "false"; 
        #else 
                return ts((int)b);
        #endif
}
template<class A> str ts(complex<A> c) { 
        stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
        str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
        res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
        str res = ""; F0R(i,SZ) res += char('0'+b[i]);
        return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
        #ifdef LOCAL
                bool fst = 1; str res = "{";
                for (const auto& x: v) {
                        if (!fst) res += ", ";
                        fst = 0; res += ts(x);
                }
                res += "}"; return res;
        #else
                bool fst = 1; str res = "";
                for (const auto& x: v) {
                        if (!fst) res += " ";
                        fst = 0; res += ts(x);
                }
                return res;

        #endif
}
template<class A, class B> str ts(pair<A,B> p) {
        #ifdef LOCAL
                return "("+ts(p.f)+", "+ts(p.s)+")"; 
        #else
                return ts(p.f)+" "+ts(p.s);
        #endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
        pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
        pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cerr << ts(h); if (sizeof...(t)) cerr << ", ";
        DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
        #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
        #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
                 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
        #define dbg(...) 0
        #define chk(...) 0
#endif

int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
int max(int a,int b, int c){return max(a,max(b,c));}
int min(int a,int b, int c){return min(a,min(b,c));}
ll max(ll a,ll b, ll c){return max(a,max(b,c));}
ll min(ll a,ll b, ll c){return min(a,min(b,c));}
void dbga(int arr[], int n){vi v;For(i,n)v.pb(arr[i]);dbg(v);}
void dbga(ll arr[], int n){vi v;For(i,n)v.pb(arr[i]);dbg(v);}

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
        unsyncIO();
        // cin.exceptions(cin.failbit); 
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
// 576743 29995400689069LL
const int MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());


const int SZ = 16;
const int SZ2 = 4;
int board[SZ];
vi bWD(16);

pi coord(int z){
    return {z/SZ2,z%SZ2};
}
int bkCoord(pi z){
    return z.f*SZ2+z.s;
}
bool in(pi z){
    return z.f>=0 && z.f<SZ2 && z.s>=0 && z.s<SZ2;
}
int findBlank(){
    For(i,SZ)if(board[i]==SZ-1)return i;
    assert(false);
    return -1;
}
int findBlank(vi v){
    For(i,SZ)if(v[i]==SZ-1)return i;
    assert(false);
    return -1;
}
bool moves(int dir){
    pi c1=coord(findBlank());
    pi c2={c1.f+xd[dir],c1.s+yd[dir]};
    if(in(c2)){
        int realRow=board[bkCoord(c2)]/4;
        int curRow=c2.f;
        int gotoRow=c1.f;
        bWD[curRow*4+realRow]--;
        bWD[gotoRow*4+realRow]++;
        swap(board[bkCoord(c1)],board[bkCoord(c2)]);
        return true;
    }
    return false;
}
void shuffle(){
    For(i,3000){
        moves(rng()%4);
    }
}
void print(){
    For(i,SZ2){
        For(j,SZ2){
            if(board[bkCoord({i,j})]==15)cout<<0;
            else cout<<board[bkCoord({i,j})]+1;
            cout<<" ";
        }
        cout<<endl;
    }
}
int manhattanDist(){
    vi v=vi(SZ);
    For(i,SZ)v[board[i]]=i;
    int sum=0;
    For(i,SZ-1){
        pi c1=coord(i);
        pi c2=coord(v[i]);
        sum+=abs(c1.f-c2.f)+abs(c1.s-c2.s);
    }
    return sum;
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

unordered_map<vector<int>,int,VectorHasher> WD;

void genWalk(){
    //FAST and INDEPENDENT
    queue<vector<int>> Q;
    Q.push({4,0,0,0,0,4,0,0,0,0,4,0,0,0,0,3});
    WD[{4,0,0,0,0,4,0,0,0,0,4,0,0,0,0,3}]=1;
    while(sz(Q)){
        auto x = Q.front(); Q.pop();
        vi cnt(4,0);
        For(i,16)cnt[i/4]+=x[i];
        int rowBlank=-1;
        For(i,4)if(cnt[i]==3)rowBlank=i;
        For(i,4){//move tile to rowBlank
            vi z={-4,4};
            trav(z2,z){
                vi x2;trav(tmp,x)x2.pb(tmp);
                if(rowBlank*4+i+z2>=0 && rowBlank*4+i+z2<=15 && x2[rowBlank*4+i+z2]){
                    x2[rowBlank*4+i]++;
                    x2[rowBlank*4+i+z2]--;
                    if(!WD[x2]){
                        WD[x2]=WD[x]+1;
                        Q.push(x2);
                    }
                }
            }
        }
    }   
    assert(sz(WD)==24964);
}

int walkingDist(){
    vi cnt(16);
    For(i,16){
        int x=board[i];
        if(x==15)continue;
        int curRow=i/4;
        int realRow=x/4;
        cnt[curRow*4+realRow]++;
    }
    For(i,16)bWD[i]=cnt[i];
    return WD[cnt];
}

ll fac[SZ+1];
ll permToInt(){
    long long ret = 0;
    set<int> pre;
    for(int i=0;i<SZ;i++){
        //can be optimized with a bit
        int bef = distance(pre.begin(),pre.lower_bound(board[i]));
        ret += fac[SZ-1-i]*(board[i]-bef);
        pre.insert(board[i]);
    }
    return ret;
}
vi intToPerm(int x){
    vi ret;
    vb used(SZ);
    int toGo=x;
    For(i,SZ){
        int need=toGo/fac[SZ-1-i];
        dbg(need,toGo,fac[SZ-1-i],i,used);
        For(j,SZ){
            if(!used[j])need--;
            if(need==-1){
                used[j]=1;
                ret.pb(j);
                break;
            }
        }
        toGo%=fac[SZ-1-i];
    }
    return ret;
}

set<ll> succ;
vl path;
vi dirs;
bool isGoal(int x){
    return x==0;
}

int search(int g, int bound){
    ll node=path.bk;
    // int estim = g+walkingDist();
    int estim = g+WD[bWD];
    if(isGoal(node)) return -1;
    if(estim>bound) return estim;
    int mn=MOD;//min of estimated cost out of subtrees
    For(i,4){
        bool revs = moves(i);
        if(succ.count(i)){
            moves((i+2)%4);
            continue;    
        } 
        dirs.pb(i);
        path.pb(permToInt());
        int rets = search(g+1,bound);
        if(rets==-1){
            return -1;
        }
        ckmin(mn,rets);
        dirs.pop_back();
        path.pop_back();
        if(revs)moves((i+2)%4);//sketch
    }
    return mn;
}

int WALKING_DISTANCE = 0;

int ida_star(){
    int bound=WALKING_DISTANCE;
    path.pb(permToInt());
    while(true){
        dbg(bound);
        print();
        int x=search(0,bound);
        if(x==-1){
            return bound;
        }
        if(x==MOD){
            return -2;
        }
        bound=x;
    }
}

void solve(){
    For(i,SZ)board[i]=i;//0-14 r #s, 15 is blank tile
    vi v={0,1,2,15,4,5,6,7,8,9,10,11,12,13,14,3};
    For(i,16)board[i]=v[i];
    genWalk();
    shuffle();
    print();
    fac[0]=1;
    FOR(i,1,SZ+1)fac[i]=fac[i-1]*i;
    WALKING_DISTANCE = walkingDist();
    dbg("WALKING DIST", WALKING_DISTANCE);
    ps("SHORTEST DIST:",ida_star());
    dbg(path);
    trav(x,dirs){
        vs v={"S","E","N","W"};
    }
}

int main() {
        setIO();
        int t=1;
        // re(t);
        while(t--)solve();
        // you should actually read the stuff at the bottom
}

/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
*/
