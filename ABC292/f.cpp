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

#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;}while(0)

using namespace std;

int main() {
    double a, b;
    
    cin >> a >> b;
    
    if(a<b) SWAP(double, a, b);
    
    double t = 4*a*a + 4*b*b - 4*sqrt(3)*a*b;
    
    if(b <= (a/2*sqrt(3))) printf("%.10lf",(2*b)/sqrt(3));
    else printf("%.10lf", sqrt(t));
    
    return 0;
}
