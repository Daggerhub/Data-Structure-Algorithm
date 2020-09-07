#include <iostream>
#include <string>
using namespace std;

void floodfill(int maze[][10] ,int i,int j,int n,int m,string ans,bool visited[][10])
{
	if(n < 0 || m < 0 || n == i-1 || m == j-1 || maze[n][m] == 1){
		return;
	}

	if(n == i-1 && m == j-1){
		cout<<ans<<endl;
		return;
	} 

	visited[n][m]=true;
	floodfill(maze,i,j,n-1,m,ans+"t",visited);
	floodfill(maze,i,j,n,m-1,ans+"l",visited);
	floodfill(maze,i,j,n+1,m,ans+"d",visited);
	floodfill(maze,i,j,n,m+1,ans+"r",visited);
	visited[n][m]=false;
}

int main(){

		 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


    int n;
    int m;
    cin>>n>>m;
    int arr[10][10] = {0};
    bool visited[10][10] = {0};
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>arr[i][j];
        }
    }
    floodfill(arr,n,m,0,0,"",visited);
}
