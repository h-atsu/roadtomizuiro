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
  ll A[N][M];
  rep(i,N) {
	rep(j,M) {
	  cin >> A[i][j];
	}
  }

  ll ans = 0;

  rep(i,M) {
	for(int j=i+1; j<M; j++) {
	  ll tmp = 0;
	  rep(k,N) {
		tmp += max(A[k][i], A[k][j]);
		//		cout << A[k][i] << " " << A[k][j] << endl;
	  }
	  ans = max(ans, tmp);
	}
  }
  cout << ans << endl;
  return 0;
}

