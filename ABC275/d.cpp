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

int dp[11111111];

ll yet(ll aa){
    if(aa<11111111){
        if(dp[aa]!=0) return dp[aa];
        else{
            dp[aa] = yet(aa/3)+yet(aa/2);
            return dp[aa];
        }
    }
    else return yet(aa/3)+yet(aa/2);
}


int main(void){
    ll n;
    cin >> n;
    dp[2] = 3;
    dp[1] = 2;
    dp[0] = 1;
    
    ll res = yet(n);
   
    cout << res << endl;

    return 0;
}

