#include <bits/stdc++.h> 
using namespace std;

  int fibmemo(int n , int qb[]){

    qb[0] = 0;
    qb[1] = 1;

    if(qb[n]!= 0){
      return qb[n];
    }

    int fibm1 = fibmemo( n - 1 , qb);
    int fibm2 = fibmemo( n - 2 , qb);
    int fibans = fibm1 + fibm2;
    qb[n] = fibans;

    return fibans;

  }

  int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int qb[n];
    // int fib =  fibmemo(n , qb);
    cout<<fibmemo( n , qb);
 
  }
