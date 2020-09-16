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
    int N;
    cin >> N;
    ll H[N];
    ll S[N];
    ll maxs = 0;
    ll maxh = 0;
    rep(i,N) {
	cin >> H[i] >> S[i];
	maxh = max(maxh,H[i]);
	maxs = max(maxs,S[i]);
    }

    ll rest[N];
    ll ans = 0;

    // To reduce computation time using binary search

    ll ok = maxh + N*maxs;
    ll ng = maxh - 1;
    
    while(abs(ok-ng) > 1) {
	ll mid = (ok+ng)/2;
	
	rep(i,N) {
	    rest[i] = (mid - H[i])/S[i];
	}
	sort(rest,rest+N);
	bool f = true;
	rep(i,N) {
//	    cout << "i" << i << ": rest[i]" << rest[i] << endl;
	    if(rest[i] < i) f = false;
	}

	if(f) ok = mid;
	else ng = mid;
	
    }

    cout << ok << endl;
    
    
    

    
    return 0;
}

