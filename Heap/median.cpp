#include<bits/stdc++.h>
using namespace std;
int main(){



	int t;
	cin>>t;
	while(t--){
        priority_queue<int> leftheap; //maxHeap
    priority_queue<int,vector<int>,greater< int > > rightheap; //minHeap
	
    int n;
    float d,med;
    cin>>n;

    while(n--){
        cin >> d;
    	if(leftheap.size()>rightheap.size()){

    		if(d<med){
    			rightheap.push(leftheap.top());
    			leftheap.pop();
    			leftheap.push(d);
    		}
    		else{
    			rightheap.push(d);
    		}
    		med = ((leftheap.top() + rightheap.top()) /2.0);

    	}

    	else if(leftheap.size() == rightheap.size()){
    		if(d<med){
    			leftheap.push(d);
    			med = leftheap.top();
    		}
    		else{
    			rightheap.push(d);
    			med = rightheap.top();
    		}
    	}
    	else{
    		if(d>med){
    			leftheap.push(rightheap.top());
    			rightheap.pop();
    			rightheap.push(d);
    		}
    		else{
    			leftheap.push(d);
    		}
    		med = ((leftheap.top() + rightheap.top())/2.0);
    	}

        cout<<med <<" ";

    }
    cout<<endl;
	
    }



}