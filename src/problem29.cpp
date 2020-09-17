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


vector<string> c(50);
vector<vector<int>> cost(50,vector<int>(50));

int main(){
    int R,C;
    int sy,sx,gy,gx;
    cin >> R >> C;
    cin >> sy >> sx >> gy >> gx;
    sy--;sx--;gy--;gx--;
    c[sy][sx] = '.';
    rep(i,R) {
	string s;
	cin >> s;
	c[i] = s;
    }

    queue<P> q;
    q.push(make_pair(sy,sx));

    while(!q.empty()) {
	int y = q.front().first;
	int x = q.front().second;
	q.pop();
	rep(i,4) {
	    int ny = y + dy[i];
	    int nx = x + dx[i];
	    if(ny < 0 || ny > R || nx < 0 || nx > C || c[ny][nx] == '#' || cost[ny][nx] != 0) continue;
	    cost[ny][nx] = cost[y][x] + 1;
	    q.push(make_pair(ny,nx));
	}
    }
    
    // rep(i,R) {
    // 	rep(j,C) {
    // 	    cout << cost[i][j] << "   ";
    // 	}
    // 	cout << endl;
    // }

    cout << cost[gy][gx] << endl;
    
    return 0;
}

