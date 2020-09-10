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
  vector<vector<int>> arr(n, vector<int> (m));

      for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++)
            cin>>v[i][j];
    }   

    //   for(int i=0;i<v.size();i++){
    //     for(int j=0;j<v[0].size();j++)
    //         cout<<v[i][j]<<" ";
    //     cout<<endl;
    // } 
    vector<vector<int>> dp(n, vector<int> (m));

    for(int i  = dp.size() - 1; i >= 0; i--){
    	for(int j = dp[0].size() - 1; j >= 0; j--){
    		if( i == dp.size() - 1 && j == dp[0].size() -1){
    			dp[i][j] = arr[i][j];
    		}
    		    	   else	if( i == dp.size() - 1){
    			dp[i][j] = dp[i][j+1] + arr[i][j];
    		}
    		    	   else if(j == dp[0].size() -1){
    			dp[i][j] = dp[i+1][j] + arr[i][j];
    		}
    		    		else{
    			dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + arr[i][j];
    		}
    	}
    }

cout<<dp[0][0];
return 0;

}

