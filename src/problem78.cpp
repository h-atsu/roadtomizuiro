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
int cumj[1010][1010];
int cumo[1010][1010];
int cumi[1010][1010];

int main(){
    int M,N,K;
    cin >> M >> N >> K;
    rep(i,M) {
	rep(j,N) {
	    char c;
	    cin >> c;
	    int J=0;
	    int O=0;
	    int I=0;
	    if(c == 'J') J++;
	    if(c == 'O') O++;
	    if(c == 'I') I++;
	    cumj[i+1][j+1] = cumj[i][j+1] + cumj[i+1][j] - cumj[i][j] + J;
	    cumo[i+1][j+1] = cumo[i][j+1] + cumo[i+1][j] - cumo[i][j] + O;
	    cumi[i+1][j+1] = cumi[i][j+1] + cumi[i+1][j] - cumi[i][j] + I;	    
	}
    }
    int ansj[K],anso[K],ansi[K];
    rep(i,K) {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	ansj[i] = cumj[c][d] - cumj[a-1][d] - cumj[c][b-1] + cumj[a-1][b-1];
	anso[i] = cumo[c][d] - cumo[a-1][d] - cumo[c][b-1] + cumo[a-1][b-1];
	ansi[i] = cumi[c][d] - cumi[a-1][d] - cumi[c][b-1] + cumi[a-1][b-1];
    }

    rep(i,K) cout << ansj[i] << " " << anso[i] << " " << ansi[i] << endl;

    // rep(i,M) {
    // 	rep(j,N) {
    // 	    cout << cumi[i+1][j+1];
    // 	}
    // 	cout << endl;
    // }
	
    return 0;
}

