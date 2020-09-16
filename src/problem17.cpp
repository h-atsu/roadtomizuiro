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




#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2*N-1], dneg[2*N-1];
int counter;
bool ng[N];
vector<P> cor;

void initialize(){
    for ( int i = 0; i < N; i++ ){ row[i] = FREE, col[i] = FREE; }
    for ( int i = 0; i < 2*N - 1; i++ ) { dpos[i] = FREE; dneg[i] = FREE; }
}

void printBoard(){
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            cout << (( row[i] == j ) ? "Q" : ".");
        }
        cout << endl;
    }
//    cout << endl;
}

void recursive( int i ){
    if ( i == N ){ // SUCCESS
	for(auto itr : cor) {
	    row[itr.second] = itr.first;
	}
        printBoard();
	return;
    }
    if(ng[i]) recursive(i+1);
    
    for ( int j = 0; j < N; j++ ){
        // if (i, j) is attacked by other queens, continue
        if ( col[j] == NOT_FREE || dpos[i+j] == NOT_FREE ||
	     dneg[i-j+N-1] == NOT_FREE ) continue;
	// put a queen on (i, j)
        row[i] = j; col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
        // try next row
        recursive( i + 1 );
        // remove the queen from (i, j)
        row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
    }
    
    // FAIL
}

int main(){
    initialize();
    int n;
    cin >> n;
    rep(i,n) {
	int x,y;
	cin >> y >> x;
	cor.push_back(make_pair(x,y));
	row[y] = x;
	col[x] = dpos[x+y] = dneg[y-x+N-1] = NOT_FREE;
	ng[y] = true;
    }
    recursive( 0 );
}






















// #define N 8
// #define FREE -1
// #define NOT_FREE 1
// vector<vector<bool>> f(9,vector<bool>(9,true));
// int row[N], col[N], dpos[2*N-1], dneg[2*N-1];

// void dfs(int i) {
//     if(i == N) return;
//     rep(j,N) {
// 	if(col[j] == NOT_FREE || dpos[i+j] == NOT_FREE || dneg[i-j+N-1] == NOT_FREE) continue;
// 	row[i] = j;  //とりあえずi行目のj列にクイーンを配置する
// 	col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
	
// 	dfs(i+1);
// 	//失敗したのでクイーンを取り除く
// 	row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
//     }
//     //失敗したら到達するライン
// }

// void init() {
//     rep(i,N) row[i] = FREE, col[i] = FREE;
//     rep(i,N*2-1) dpos[i] = dneg[i] = FREE;
// }


// int main(){
//     init();
//     int n;
//     cin >> n;
//     rep(i,n) {
// 	int x,y;
// 	cin >> y >> x;
// 	row[y] = x;
// 	col[x] = dpos[x+y] = dneg[y-x+N-1] = NOT_FREE;
//     }


//     dfs(0);


    

//     rep(i,8) {
// 	rep(j,8) {
// 	    cout << ((row[i] == j) ? "Q" : ".");
// 	}
// 	cout << endl;
//     }
    
//     return 0;
// }

