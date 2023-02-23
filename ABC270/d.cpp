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

#define ALL(a)  (a).begin(),(a).end()
#define max(p,q)((p)>(q)?(p):(q))

int a[100000];
int dp[100000];

int main(void){
    int n,k;  
    cin >> n >> k;
    
    rep(i,k) cin >> a[i];
    
    rep(i,n+1){
        rep(j,k){
            if(a[j]>i) break;
			dp[i] = max(dp[i],i-dp[i-a[j]]);
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
