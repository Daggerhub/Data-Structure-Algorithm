#include <bits/stdc++.h> 
  
using namespace std; 
void printKMax(int arr[], int n, int k) 
{ 
	  deque<int> q; 
	     int i; 
    for (i = 0; i < k; ++i) { 
        while ((!q.empty()) && arr[i] >= arr[q.back()]) 
            q.pop_back(); 
        q.push_back(i); 
    } 

      for (; i < n; ++i) { 
      
        cout << arr[q.front()] << " "; 
  
       
        while ((!q.empty()) && q.front() <= i - k) 
            q.pop_front(); 

        while ((!q.empty()) && arr[i] >= arr[q.back()]) 
            q.pop_back(); 
  
       
        q.push_back(i); 
    } 

    cout << arr[q.front()]; 
}

int main(){

        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


	int n,k;
	cin>>n;
	int arr[n];

	for(int i = 0 ; i < n ;i++){
		cin>>arr[i];
	}
	cin>>k;
	printKMax(arr, n, k); 
    return 0; 
} 