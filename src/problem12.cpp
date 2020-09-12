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


bool re[15][15];

int main(){
    int N,M;
    cin >> N >> M;
    rep(i,M) {
	int x,y;
	cin >> x >> y;
	x--,y--;
	re[x][y] = true;
	re[y][x] = true;
    }
    int ans = 0;
    
    for(int bit=0; bit < (1 << N); bit++) {
	vector<bool> frd(N,false);
	int num = 0;
	rep(i,N) {
	    if(bit & (1 << i)){
		frd[i] = true;
		num++;
	    }
	    
	}
	
	// for(auto itr : frd) {
	//     cout << itr;
	// }
	// cout << endl;
	    
	bool f = true;
	rep(i,N) {
	    rep(j,N) {
		if(i == j) continue;
		if(frd[i] && frd[j]) {
		    if(re[i][j] == false) f = false;
		}
	    }
	}
//	cout << num << endl;
	if(f) ans = max(ans,num);
    }
    cout << ans << endl;

    // rep(i,N) {
    // 	rep(j,N) {
    // 	    cout << re[i][j];
    // 	}
    // 	cout << endl;
    // }

    
    return 0;
}

