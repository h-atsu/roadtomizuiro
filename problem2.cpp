#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

template <typename T>
bool chmax(T &a, T &b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, T &b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}


int main() {
  string s;
  cin >> s;
  int ans = 0;
  int tmp = 0;
  int N = s.size();
  rep(i,N) {
    if(s[i] != 'A' && s[i] != 'G' && s[i] != 'T' && s[i] != 'C') {
      ans = max(tmp,ans);
      tmp = 0;
    }
    else tmp++;
    if(i == N-1) ans = max(tmp,ans);
    
  }
  cout << ans << endl;
  return 0;
}





