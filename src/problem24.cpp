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


int n = 100;
vector<vector<int>> G(n);
vector<P> ts(n);
int ord = 1;

void dfs(int nord) {
    if(ts[nord].first == 0) {
	ts[nord].first = ord++;
    }
    else return;

    for(auto itr : G[nord]) {
	dfs(itr);
    }

    ts[nord].second = ord++;
}


int main(){
    cin >> n;
    rep(i,n) {
	int vn;
	int d;
	cin >> vn;
	cin >> d;
	vn--;
	rep(j,d) {
	    int x;
	    cin >> x;
	    x--;
	    G[vn].push_back(x);
	}
    }
    
    rep(i,n) dfs(i);



    rep(i,n) {
	cout << i + 1 << " " << ts[i].first << " " << ts[i].second << endl;
    }
    
    
    return 0;
}

