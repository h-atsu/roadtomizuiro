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


vector<vector<int>> table(550,vector<int>(550,0));
vector<vector<int>> cum(550,vector<int>(550,0));

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    rep(i,M) {
	int l,r;
	cin >> l >> r;
	l--,r--;
	table[l][r]++;
    }
    rep(i,N) {
	rep(j,N) {
	    cum[i+1][j+1] = table[i][j] + cum[i+1][j];
	}
    }

    int ans[Q];

    rep(i,Q) {
	int p,q;
	cin >> p >> q;
	int tmp=0;
	for(int j=p; j<=q; j++) {
	    tmp += cum[j][q] - cum[j][p-1];
	}
	ans[i] = tmp;
    }

    // rep(i,N+1) {
    // 	rep(j,N+1) cout << cum[i][j];
    // 	cout << endl;
    // }
    
    rep(i,Q) cout << ans[i] << endl;
}



//　この方法だと漏れがある
// int main(){
//     int N,M,Q;
//     cin >> N >> M >> Q;
//     rep(i,M) {
// 	int l,r;
// 	cin >> l >> r;
// 	L[l]++;
// 	R[r]++;
//     }
//     rep(i,N) {
// 	cuml[i+1] = cuml[i] + L[i+1];
// 	cumr[i+1] = cumr[i] + R[i+1];
//     }

//     // for(int i=0; i<=N; i++) {
//     // 	cout << cuml[i] << cumr[i] << endl;
//     // }
//     int ans[Q];
    
//     rep(i,Q) {
// 	int p,q;
// 	cin >> p >> q;
// 	int le = M - cuml[p-1];
// 	int ri = cumr[q];
// 	ans[i] = min(ri,le);
//     }
//     cout << "---------------------" << endl;
//     rep(i,M) cout << cuml[i] << " " << cumr[i] << endl;

//     cout << "---------------------" << endl;
//    for(auto itr : ans) cout << itr << endl;



    



    
//     return 0;
// }

