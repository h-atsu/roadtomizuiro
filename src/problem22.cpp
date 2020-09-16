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



// これは三分探索を用いた解法 たぶんO(logN)

int main() {
    double p;
    cin >> p;
    auto f = [p](double x){
	return x + p*pow(2,-2.0*x/3.0);
    };

    double low = 0;
    double high = 1e9;
    double c1 = (low*2 + high)/3;
    double c2 = (low + 2*high)/3;
    double epsilon = 1e-9;
    while(abs(c1-c2) > epsilon) {
	c1 = (low*2 + high)/3;
	c2 = (low + high*2)/3;

	if(f(c1) > f(c2)) low = c1;
	else high = c2;	    
    }

    printf("%.10lf\n",f(low));



    
    return 0;
}










// これは微分を用いたO(1)解法
//double p;
// double f(double x) {
//     return x + p*pow(2.0,-2.0*x/3.0);
// }


// int main(){
//     cin >> p;

//     double x = 3.0/2.0 * log2(2.0*p*log(2.0)/3.0);

//     if(x < 0) printf("%.14lf\n",f(0.0));
//     else printf("%.14lf\n",x+3.0/log(2)/2.0);
    
//     return 0;
// }

