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

int A[30];
int n;

bool can(int pos,int m,int val) {
    if(val == m) return true;
    if(val > m || pos == n) return false;
    return can(pos+1,m,val + A[pos]) | can(pos+1,m,val);
}

int cans(bool f){
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


int main() {
    cin >> n;
    rep(i,n) cin >> A[i];
    int m;
    cin >> m;
    int q[m];
    rep(i,m) cin >> q[i];
    rep(i,m) {
	bool f=can(0,q[i],0);
	if(f) cout << "yes" << endl;
	else cout << "no" << endl;
    }
    return 0;
}

