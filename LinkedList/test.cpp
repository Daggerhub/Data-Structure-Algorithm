#include <iostream>
using namespace std;

void zigzag(int n){
	if(n == 0){
	  return;
	}

	cout<<n<<" ";
	zigzag(n-1);
	cout<<n<<" ";
	zigzag(n-1);
	cout<<n<<" ";
}

int factorial(int n){
	if(n==1||n==0){
		return 1;
	}

	return n*factorial(n-1);
}

void pdi(int n){
	if(n==0){
		return;
	}
	cout<<n<<endl;
	pdi(n-1);
	cout<<n<<endl;
}

void print_increasing(int n , int i){

	if(i>n){
		return;
	}
	cout<<i<<endl;
	print_increasing(n , i+1);

}

int power(int n , int i){
	if(i === 0){
		return 1;
	}

	int xpnb2 = power(n , i / 2)

	int x = xpnb2*xpnb2;

	if(i%2 == 1){
		x = x * i;
	}
}

 int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,t;
	cin>>n;
	// print_increasing(n,1);
	// pdi(n);
	t = factorial(n);
	cout<<t;

    return 0;
 }