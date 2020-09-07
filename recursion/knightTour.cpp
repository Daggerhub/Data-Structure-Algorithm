#include<iostream>
#include<string>
using namespace std;

void displayboard(int chess[][10],int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<chess[i][j];
		}
		cout<<endl;
	}
}

void printQueen(int chess[][10] , int r , int c ,int move,int n){

	if(r < 0 || c < 0 || r >= n || c >= n || chess[r][c] > 0){
		return;
	}
	else if(move == n*n){
		chess[r][c] = move;
		displayboard(chess, n);
		chess[r][c] = 0;
		return;
	}
	chess[r][c] = move;
	printQueen(chess , r-2,c+1,move+1,n);
	printQueen(chess , r-1,c+2,move+1,n);
	printQueen(chess , r+1,c+2,move+1,n);
	printQueen(chess , r+2,c+1,move+1,n);
	printQueen(chess , r+2,c-1,move+1,n);
	printQueen(chess , r+1,c-2,move+1,n);
	printQueen(chess , r-1,c-2,move+1,n);
	printQueen(chess , r-2,c-1,move+1,n);
	chess[r][c] = 0;
}

int main(){
		 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,r,c;
	cin>>n;
	cin>>r;
	cin>>c;

	int chess[10][10] = {0};

	printQueen(chess,r ,c ,1 , n);

}