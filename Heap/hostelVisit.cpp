#include<iostream>
#include<queue>
#include<vector>
using namespace std;
	long long int distance(long long int x,long long int y)
	{
		return x*x+y*y;
    }
int main() {
    priority_queue<int>pq;
    long long int n;
    cin>>n;
    long long int k;
    cin>>k;
    long long int g=0;
    for(long long int i=0;i<n;i++)
    {
        long long  t;
        cin>>t;
        if(t==1)
        {
            long long int x,y;
            cin>>x>>y;
            if(g<k)
            {
                pq.push(distance(x,y));
                g++;
            }
            else
            {
                if(distance(x,y)<pq.top())
                {
                    pq.pop();
                    pq.push(distance(x,y));
                }
            }
        }
        else if(t==2)
        {
            cout<<pq.top()<<endl;
        }
    }

	return 0;
}
