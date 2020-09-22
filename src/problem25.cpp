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

int w,h;
vector<vector<int>> isl(50,vector<int>(50));
vector<vector<int>> label(50,vector<int>(50));



void dfs(int y, int x, int num) {
    if(x >= 0 && x < w && y >= 0 && y < h && isl[y][x] == 1 && label[y][x] != num) {
	label[y][x] = num;
	rep(i,4) {
	    rep(j,4) {
		dfs(y+dy[i],x+dx[j],num);
	    }
	}
    }
}


int main(){
    while(cin >> w >> h) {
	if(w == 0 || h == 0) break;
	rep(i,h) {
	    rep(j,w) cin >> isl[i][j], label[i][j] = -1;

	}


	int ans = 0;
       
	rep(i,h) {
	    rep(j,w) {
		if(isl[i][j] == 0) continue;
		if(label[i][j] == -1) dfs(i,j,++ans);
	    }
	    
	    // rep(i,h) {
	    // 	rep(j,w) cout << label[i][j] <<  "  ";
	    // 	cout << endl;
	    // }
	}


	cout << ans << endl;
	

	
    }
    return 0;
}

