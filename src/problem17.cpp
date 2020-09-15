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


vector<vector<bool>> f(9,vector<bool>(9,true));

void draw(int x, int y, int vx, int vy) {
    if(0 <= x && x < 9 && 0<= y && y < 9) {
	f[y][x] = false;
	draw(x+vx,y+vy,vx,vy);
    }
}



int main(){
    int n;
    cin >> n;
    rep(i,n) {
	int x,y;
	cin >> x >> y;
	rep(i,4) {
	    rep(j,4) {
		if(dx[i] == 0 && dy[j] == 0) continue;
		draw(x,y,dx[i],dy[j]);
	    }
	}
	f[y][x] = true;
    }

    



    

    rep(i,9) {
	rep(j,9) {
	    if(f[i][j]) cout << 'Q';
	    else cout << '.';
	}
	cout << endl;
    }
    
    return 0;
}

