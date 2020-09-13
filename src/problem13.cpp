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

int senbei[13][10010];

int main(){
    int R,C;
    cin >> R >> C;
    rep(i,R) {
	rep(j,C) {
	    cin >> senbei[i][j];
	}
    }
    int ans = 0;
    
    for(int bit =0; bit < (1<<R); bit++) {
	int tmp = 0;
	rep(i,C) {
	    int back = 0;
	    int front = 0;
	    rep(j,R) {
		int now = senbei[j][i];
		if(bit & (1 << j)) now = 1 - now;
		if(now == 0) back++;
		else front++;
	    }
	    tmp += max(back,front);
	}
	ans = max(tmp,ans);
    }
    cout << ans << endl;



    
    
    return 0;
}

