#include<bits/stdc++.h>
using namespace std;

void printSpan(int a[], int n){
	stack<int> s;
	int ans[100000];

	for(int i = 0 ; i < n ; i++){
	
	  while( !s.empty() && a[s.top()] < a[i]){ 
	    
	      s.pop();
	    
	  }

		if(s.empty()){
			ans[i] = i+1;
		}
		else{
			ans[i]= i - s.top();
		}
        s.push(i);
    
	}
	for(int i=0 ; i< n ;i++){
		cout << ans[i] << " ";
	}
	cout << "END" << endl;
}

int main(){
	    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
   
	int n;
	cin >> n;
	int a[n];
	for(int i=0 ; i< n; i++){
		cin >> a[i];
	}
  if(n>0){
  	printSpan(a,n);
  }
    
	return 0;
}
