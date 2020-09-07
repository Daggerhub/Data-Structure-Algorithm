#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void floodfill(int *arr[5], int n, int m , int str, int stc, string path,bool *visited[5])
{
    if(str <0 || stc <0 || str == n - 1 || stc == m - 1 || arr[str][stc] == 1)
    {
        return;
    }
    if(str == n -1 && stc == m-1)
    {
        cout<<path<<endl;
        return;
    }
    visited[str][stc]= true;
    floodfill(arr,n,m,str-1,stc,path + "t",visited);
    floodfill(arr,n,m,str,stc-1,path + "l",visited);
    floodfill(arr,n,m,str+1,stc,path + "d",visited);
    floodfill(arr,n,m,str,stc+1,path + "r",visited);
    visited[str][stc]= false;
}
int main()
{
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n;
    int m;
    cin>>n>>m;
    int **arr;
    arr = new int *[10];
    bool **visited;
    visited = new bool *[10];
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>arr[i][j];
        }
    }
    floodfill(arr,n,m,0,0,"",visited);
}