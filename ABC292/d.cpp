#include <bits/stdc++.h>
using namespace std;

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


vector<int> graph[200001];
bool visited[200001];

// DFSで連結成分を求める関数
void dfs(int v, int& vertex_count, int& edge_count) {
    visited[v] = true;
    vertex_count++;
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        edge_count++;
        if (!visited[u]) {
            dfs(u, vertex_count, edge_count);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // グラフの入力
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 連結成分を求める
    for (int v = 1; v <= N; v++) {
        if (!visited[v]) {
            int vertex_count = 0;
            int edge_count = 0;
            dfs(v, vertex_count, edge_count);
            edge_count /= 2;  
            if(vertex_count!=edge_count){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}