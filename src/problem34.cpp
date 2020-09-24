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

int memo[50];

int fib(int n) {
    if(n==0 || n==1) return 1;
    if(memo[n] != 0) return memo[n];
    else return memo[n]=fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

