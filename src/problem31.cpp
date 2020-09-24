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
// int dx[] = {1,-1,0,0};
// int dy[] = {0,0,1,-1};

int dxo[] = {1,-1,0,-1,-1,0};
int dyo[] = {0,0,-1,-1,1,1};
int dxe[] = {1,-1,1,0,0,1};
int dye[] = {0,0,-1,-1,1,1};
    
    

int f[100][100];

int main(){
    int W,H;
    cin >> W >> H;
    rep(i,H) {
	rep(j,W) {
	    cin >> f[i][j];
	}
    }


    rep(i,H) {
	rep(j,W) {
	    cout << f[i][j];
	}cout << endl;
    }
    cout << endl;
    return 0;
}

