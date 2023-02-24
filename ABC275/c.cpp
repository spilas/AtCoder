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

char c[10][10];
bool valid(ll x,ll y){return x>0&&x<10&&y>0&&y<10&&c[x][y]=='#';}

int main(){
	set<set<pair<ll,ll> > > sq;
	reps(i,1,10) reps(j,1,10) cin >> c[i][j];
	reps(x,1,10) reps(y,1,10){
		reps(dx,-8,9) reps(dy,-8,9){
			if(dx==0&&dy==0) continue;
			ll u = x+dx, v = y+dy;
			ll X = u-dy, Y = v+dx;
			ll U = X-dx, V = Y-dy;
			if(valid(x,y)&&valid(u,v)&&valid(X,Y)&&valid(U,V)){
				set<pair<ll,ll> > s;
				s.insert(make_pair(x,y));
				s.insert(make_pair(U,V));
				s.insert(make_pair(X,Y));
				s.insert(make_pair(u,v));
				sq.insert(s);
			}
		}
	}
	cout << sq.size() << endl; 
	return 0;
}