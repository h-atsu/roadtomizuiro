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
    vector<string> tate(100);
    vector<string> yoko(100);
    rep(i,10) {
	char c;
	cin >> c;
	tate[0].push_back(c);
    }

    cout << tate[0] << endl;
    
    // int h,w;
    // while(cin >> w >> h) {
    // 	if(h==0 && w==0) break;
      
    // 	rep(i,2*h-1) {
    // 	    if(i%2 == 0) {
    // 		cin >> tate[i/2];
    // 	    }
    // 	    else cin >> yoko[i/2];
    // 	}

    // 	cout << tate[0] << endl;

    // }

    
    return 0;
}

