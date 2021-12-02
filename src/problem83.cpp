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
    int N,M;
    cin >> N >> M;
    vector<int> P(M);
    rep(i,M) {
	int p;
	cin >> p;
	p--;
	P[i] = p;
    }
    vector<ll> A(N-1);
    vector<ll> B(N-1);
    vector<ll> C(N-1);    
    rep(i,N-1) {
	cin >> A[i] >> B[i] >> C[i];
    }
    vector<ll> table(N);
    rep(i,M-1) {
	int s = min(P[i], P[i+1]);
	int g = max(P[i], P[i+1]);
//	cout << s << g << endl;
	table[s]++;
	table[g]--;
    }
    rep(i,N) {
	if(i == 0) continue;
	table[i] += table[i-1];
    }
    ll ans = 0;
    rep(i,N) {
	// その線路を利用する回数
	ll cnt = table[i];
	ll fare = min(C[i] + cnt*B[i], A[i]*cnt);
	ans += fare;
    }
    cout << ans << endl;
    
}

