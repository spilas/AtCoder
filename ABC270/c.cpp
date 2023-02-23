#include <bits/stdc++.h>
using namespace std;

// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;
using msi = map<string,int>;
#define pb push_back
#define mp make_pair

#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define INF (1e9)

const int MAXN = 300000;

typedef pair<int,int> Edge;
#define to first
#define cost second
vector<Edge> G[MAXN];

typedef pair<int,int> pii;
#define A top().first
#define B top().second

int V,E;
int dist[MAXN];
int previous[MAXN]; // vi の直前の vertex を記憶するための配列 (追加 1/4)

void dijkstra(int s) {
    fill(dist, dist+MAXN, INF);
    fill(previous, previous+MAXN, -1); // 追加 2/4
    dist[s] = 0;

    priority_queue<pii,vector<pii>,greater<pii> > pq; // greater: pair.first が小さい順
    pq.push(pii(0,s)); // cost, vertex

    while(!pq.empty()) {
        int cost = pq.A;
        int v = pq.B;
        pq.pop();
        if(cost > dist[v]) continue;
        for(int i = 0; i < (int)G[v].size(); ++i) {
            Edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                previous[e.to] = v; // 追加 3/4
                pq.push(pii(dist[e.to], e.to));
            }
        }
    }
}

vector<int> get_path(int t) { // 追加 4/4
    vector<int> path;
    for(; t != -1; t = previous[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}


int main(void){
    int x,y,n;
    
    cin >> n >> x >> y;
    rep (i,n-1) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(Edge(b,10));
        G[b].push_back(Edge(a,10));
    }
    
    dijkstra(x); 
    vector<int> path = get_path(y);
    for(int j = 0; j < (int)path.size(); ++j) {
        cout << path[j];
        if(j != (int)path.size() - 1) cout << " ";
    }
    cout << endl;
    

    return 0;
}

