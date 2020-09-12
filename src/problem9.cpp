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

int main() {
    int m;
    int n;
    cin >> m;
    map<P,int> is;
    vector<P> star;
    vector<P> cordinate;
    int x0,y0;
    rep(i,m) {
	int x,y;
	cin >> x >> y;
	if(i == 0) x0 = x, y0 = y;
	x -=x0;
	y -=y0;
	star.push_back(make_pair(x,y));
    }
    cin >> n;
    rep(i,n) {
	int x,y;
	cin >> x >> y;
	is[make_pair(x,y)] = 1;
	cordinate.push_back(make_pair(x,y));
    }
    int ansx,ansy;
    for(auto cor : cordinate) {
	int x = cor.first;
	int y = cor.second;
	bool f = true;
	for(auto st : star) {
	    if(is[make_pair(x+st.first,y+st.second)] != 1) f = false;
	}
	if(f) ansx = x - x0, ansy = y - y0 ;
    }
    cout << ansx << " " << ansy << endl;


}

