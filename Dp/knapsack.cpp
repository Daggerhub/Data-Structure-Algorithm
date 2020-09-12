#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
  #endif
  
  int n;
  cin>>n;
  int arr[n];
  int wt[n];

      for(int i = 0 ; i < n; i++){
       cin>>arr[i];
    }   

          for(int i = 0 ; i < n; i++){
       cin>>wt[i];
    }   

int target;
cin>>target;

     vector<vector<int>> dp(n + 1, vector<int> (target + 1));

     for(int i = 1; i < dp.size() ; i++){
      for(int j = 1; j < dp[0].size() ; j++){
        if(j >= wt[i -1]){
          int rcap = j -wt[i -1];
          if((dp[i-1][rcap] + arr[i-1]) > dp[i-1][j]){
            dp[i][j] = dp[i -1][rcap] + arr[i-1];
          }
          else{
            dp[i][j] = dp[i -1][j];
          }
        }
        else{
          dp[i][j] = dp[i -1][j];
        }
      }
     }

    cout<<dp[n][target];

return 0;

}
