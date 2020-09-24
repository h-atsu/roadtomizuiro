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

using Graph = vector<vector<int>>;

Graph G(110);
vector<int> dis(110,-1);

int main(){
    int N;
    cin >> N;
    G.resize(N);
    dis.resize(N);
    dis[0] = 0;
    rep(i,N) {
	int n,k;
	cin >> n >> k;
	rep(j,k) {
	    int nx;
	    cin >> nx;
	    nx--;
	    G[i].push_back(nx);
	}
    }
    
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
	int nord = q.front();
	q.pop();
	for(auto nx : G[nord]) {
	    if(dis[nx] != -1) continue;
	    dis[nx] = dis[nord] + 1;
	    q.push(nx);
	}
    }

    rep(i,N) cout << i+1 << " " <<  dis[i] << endl;
    
    return 0;
}

