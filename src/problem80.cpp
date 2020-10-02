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
    int H,W;
    ll K,V;
    cin >> H >> W >> K >> V;
    ll A[200][200];
    ll cum[200][200];
    
    rep(i,H) {
	rep(j,W) {
	    cin >> A[i][j];
	}
    }

    rep(i,H) {
	rep(j,W) {
	    cum[i+1][j+1] = A[i][j] + cum[i][j+1] + cum[i+1][j] - cum[i][j];
	}
    }


    ll ans = 0;
    int z=0;

    for(int a=1; a<=H; a++) {
	for(int c = a; c<=H; c++) {
	    for(int b = 1; b<=W; b++) {
		for(int d = b; d<=W; d++) {
		    ll num = ll(c-a+1)*ll(d-b+1);
		    ll val = cum[c][d] - cum[a-1][d] - cum[c][b-1] + cum[a-1][b-1];
		    ll tmp = num * K + val;
		    if(tmp <= V) ans = max(num,ans);
		}
	    }
	}
    }


    cout << ans << endl;


    // rep(i,H+1) {
    // 	rep(j,W+1) {
    // 	    cout << cum[i][j] << "  ";       
    // 	}
    // 	cout << endl;
    // }
    
    
    return 0;
}

