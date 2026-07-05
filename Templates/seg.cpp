#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Glory ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Test int t; cin>>t;while(t--)
#define ll   long long
#define yes  cout <<"YES\n";
#define no   cout<<"NO\n";
#define L    <<'\n';
#define For  for (int i =0 ;i<n;i++)
#define FoR  For {cin>>arr[i];}
#define all(v)  v.begin(),v.end()
#define loop(a,b,c) for(int c=a;c<b;c++)
#define ARR  int n;  cin>>n; int arr[n]; FoR
#define Glory ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N =2e5+4;
const int INF = 0x3f3f3f3f; 
bool vis[N];
vector<int>adj[N];

struct SegTree {
    vector<ll> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0LL);
    }
    void build(vector<int>&a, int x, int lx, int rx) {
        if(rx-lx==1){
            if(lx<(int)a.size()){
                tree[x]= a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]= tree[2*x+1]+tree[2*x+2];

    }

    void build(vector<int>&a){
        build(a,0,0,size);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]);
    }

    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        ll m1 = sum(l, r, 2 * x + 1, lx, m);
        ll m2 = sum(l, r, 2 * x + 2, m, rx);
        return m1+m2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    Glory
    int n, m;
    cin >> n >> m;
    SegTree seg;
    seg.init(n);
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    seg.build(a);
    while (m--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            seg.set(x, y);
        } else {
            cout << seg.sum(x, y) << '\n'; 
        }
    }
}
