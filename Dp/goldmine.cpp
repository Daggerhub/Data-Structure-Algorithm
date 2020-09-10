#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
  #endif
  
  int n,m;
  cin>>n;
  cin>>m;
  vector<vector<long long int>> arr(n, vector<long long int> (m));

      for(long long int i=0;i<arr.size();i++){
        for(long long int j=0;j<arr[i].size();j++)
            cin>>arr[i][j];
    }   

    vector<vector<long long int>> dp(n, vector<long long int> (m));

    for(long long int j  = dp[0].size() - 1; j >= 0; j--){
      for(long long int i = dp.size() - 1; i >= 0; i--){
        if(j == dp[0].size() - 1){
          dp[i][j] = arr[i][j];
        }
        else if(i == 0){
          dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
        }
        else if(i == arr.size() - 1){
          dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i-1][j+1]);
        }
        else{
          dp[i][j] = arr[i][j] + max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
        }
      }
    }

    long long int max;
    max = dp[0][0];

      for(long long int i=0;i<dp.size();i++){
        for(long long int j=0;j<dp[0].size();j++){
          if(dp[i][j] > max){
            max = dp[i][j];
          }
        }
            
    } 

    cout<<max;


return 0;

}


