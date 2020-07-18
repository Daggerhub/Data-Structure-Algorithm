#include<iostream>
#include<queue>
using namespace std;
int main(){

	priority_queue<int, vector<int>,greater<int>> pq; 
	int i,k,n,a,d;
	cin>>k>>n;

	a=k*n;

	for(i=0;i<a;i++){
		cin>>d;
		pq.push(d);
	}

	while(!pq.empty())
{

	cout<<pq.top()<<" ";
	pq.pop();

}

}