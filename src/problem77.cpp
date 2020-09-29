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
const ll mod=1e5;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    int N,m;
    cin >> N >> m;
    int a[m];
    int dis[N];
    dis[0] = 0;
    rep(i,N-1) {
	int b;
	cin >> b;
	dis[i+1] = dis[i] + b;
    }
    rep(i,m) cin >> a[i];
    int ans = 0;
    int now = 0;
    rep(i,m) {
	ans += abs(dis[now + a[i]] - dis[now]);
	now += a[i];
	ans %= mod;
    }
    cout << ans << endl;
    
    return 0;
}

