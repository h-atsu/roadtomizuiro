#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    ll d;
    int n;
    int m;
    cin >> d >> n >> m;
    ll dist[n+1];
    rep(i,n-1) cin >> dist[i];
    dist[n-1] = 0;
    dist[n] = d;
    sort(dist,dist+n);
    
    ll ans = 0;
//      vector<P> K;
    rep(i,m) {
	int k;
	cin >> k;
	ll pre = *(lower_bound(dist,dist+1+n,k)-1);
	ll nxt = *lower_bound(dist,dist+1+n,k);
	ans += min(abs(pre-k),abs(nxt-k));
//	K.push_back(make_pair(pre,nxt));
    }
    cout << ans << endl;

//    for(auto itr : K) cout << itr.first << " " << itr.second << endl;;
   
    
    return 0;
}

