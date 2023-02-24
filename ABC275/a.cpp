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


int main(void){
    int n,a;
    cin >> n;
    
    vll brig;
    rep(i,n){
        cin >> a;
        brig.pb(a);
    }
    auto iter = max_element(brig.begin(), brig.end());
    size_t index = distance(brig.begin(), iter);
    
    cout << index+1 << endl;

    return 0;
}

