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
    ll N,M;
    cin >> N >> M;
    N++;
    ll P[N];
    P[N-1] = 0;
    rep(i,N-1) {
	cin >> P[i];
    }
    sort(P,P+N);

    ll R[N*N];
    rep(i,N) {
	rep(j,N) {
	    R[i*N + j] = P[i] + P[j];
	}
    }
    sort(R,R+N*N);

    
    ll ans = 0;
    rep(i,N*N) {
	ll rest = M - R[i];
	if(rest < 0) break;
	auto key = upper_bound(R,R+N*N,rest) - R - 1;
	rest -= R[key];
	ans = max(ans,M-rest);
    }
    cout << ans << endl;
    // for(auto itr : P) cout << itr << " ";
    // cout << endl;
    return 0;
}






// O(N^3logN)解放 想定解にするにはO(N^2logN)にする必要がある
// int main(){
//     ll N,M;
//     cin >> N >> M;
//     N++;
//     ll P[N];
//     P[N-1] = 0;
//     rep(i,N-1) {
// 	cin >> P[i];
//     }
//     sort(P,P+N);

//     ll ans = 0;
//     rep(i,N) {
// 	rep(j,N) {
// 	    rep(k,N) {
// 		ll rest = M - (P[i] + P[j] + P[k]);
// 		if(rest < 0) break;
// 		int key = upper_bound(P,P+N,rest) - P - 1;
// 		rest -= P[key];
// 		ans = max(ans,M - rest);
// 	    }
// 	}
//     }
//     cout << ans << endl;
//     return 0;
// }

