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


vector<vector<bool>> f(5050, vector<bool>(5050));
vector<P> p;

int main(){
  int N;
  cin >> N;
  rep(i,N) {
	int x,y;
	cin >> x >> y;
	f[x][y] = true;
	p.push_back(make_pair(x,y));
  }
  int ans = 0;
  for(int i=0; i<N; i++) {
	for(int j=0; j<N; j++) {
	  if(i == j) continue;
	  int x1,x2,y1,y2,dx,dy;
	  x1 = p[i].first;
	  y1 = p[i].second;
	  x2 = p[j].first;
	  y2 = p[j].second;
	  dx = x2 - x1;
	  dy = y2 - y1;
	  if(x2+dy >= 0 && x2+dy <= 5000 && y2-dx >= 0 && y2-dx <= 5000 && f[x2+dy][y2-dx]) {
		if(x1+dy >= 0 && x1+dy <= 5000 && y1-dx >= 0 && y1-dx <= 5000 && f[x1+dy][y1-dx]) {			
		  ans = max(ans, dx*dx + dy*dy);
		  //		  cout << dx << dy << endl;
		}
	  }
	  if(x2-dy >= 0 && x2-dy <= 5000 && y2+dx >= 0 && y2+dx <= 5000 && f[x2-dy][y2+dx]) {
		if(x1-dy >= 0 && x1-dy <= 5000 && y1+dx >= 0 && y1+dx <= 5000 && f[x1-dy][y1+dx]) {			
		  ans = max(ans, dx*dx + dy*dy);
		  //		  cout << dx << dy << endl;
		}
	  }
	}
  }
  cout << ans << endl;
  return 0;
}

