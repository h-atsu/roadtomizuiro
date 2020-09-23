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
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

vector<vector<int>> f(100,vector<int>(100,0));

int m,n;
int ans = 0;

void dfs(int y, int x, int val) {
    if(f[y][x] == 1) {
	val++;
	ans = max(ans,val);
	f[y][x] = 0;
	rep(i,4) {
	    dfs(y + dy[i], x + dx[i], val);
	}
	f[y][x] = 1;
    }

}

int main(){
    cin >> m >> n;
    rep(i,m) {
	rep(j,n) cin >> f[i+1][j+1];
    }


    rep(i,m) {
	rep(j,n) {
	    dfs(i+1,j+1,0);
//	    cout << i+1 << j+1 << " ";
	}
    }
    cout << ans << endl;

    // rep(i,m+2) {
    // 	rep(j,n+2) {
    // 	    cout << f[i][j] ;
    // 	}
    // 	cout << endl;
    // }

    
    return 0;
}

