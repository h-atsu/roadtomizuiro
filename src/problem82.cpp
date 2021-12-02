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
    int N;
//    cout << 3600*24 + 60*59 + 60 << endl;
    while(cin >> N) {
	if(N == 0) break;
	int Max = 90010;
	vector<int> table(Max);
	rep(i,N) {
	    string a,b;
	    cin >> a >> b;
	    int s = stoi(a.substr(0,2))*3600 + stoi(a.substr(3,2))*60 + stoi(a.substr(6,2));
	    int g = stoi(b.substr(0,2))*3600 + stoi(b.substr(3,2))*60 + stoi(b.substr(6,2));
	    table[s]++;
	    table[g]--;
	}
	int ans = 0;
	rep(i,Max-1) {
	    if(i==0) continue;
	    table[i] += table[i-1];
	    ans = max(ans, table[i]);
	}
	cout << ans << endl;
    }
}

