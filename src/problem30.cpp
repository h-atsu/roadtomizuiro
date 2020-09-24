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

vector<string> f(1000);
vector<P> pos(10);




int main(){
    int H,W,N;
    cin >> H >> W >> N;
    f.resize(H);
    pos.resize(N+1);
    rep(i,H) {
	cin >> f[i];
	rep(j,W) {
	    if(f[i][j] == 'S') pos[0] = make_pair(i,j);
	    else if(f[i][j] != '.' && f[i][j] != 'X' && f[i][j] != 'S') pos[f[i][j] - '0'] = make_pair(i,j);
	}
    }
    int ans = 0;

    rep(i,N) {
	int sy = pos[i].first;
	int sx = pos[i].second;
	int gy = pos[i+1].first;
	int gx = pos[i+1].second;

//	cout << sy << sx << gy << gx << endl;
	vector<vector<int>> dis(H,vector<int>(W,-1));
	queue<P> q;
	q.push(make_pair(sy,sx));
	dis[sy][sx] = 0;
	while(!q.empty()) {
	    int y = q.front().first;
	    int x = q.front().second;
	    q.pop();
	    rep(i,4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny >= 0 && ny < H && nx >= 0 && nx < W && f[ny][nx] != 'X' && dis[ny][nx] == -1) {
		    q.push(make_pair(ny,nx));
		    dis[ny][nx] = dis[y][x] + 1;
		}
	    }
	}

	ans += dis[gy][gx];
	// rep(i,H) {
	//     rep(j,W) {
	// 	cout << dis[i][j];
	//     }
	//     cout << endl;
	// }
    }

    cout << ans << endl;
    
    return 0;
}

