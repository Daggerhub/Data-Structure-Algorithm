#include<iostream>
using namespace std;

class node{

public:
	node *left;  
	node *right;

};
class trie{
	node*root;

public:
	trie(){
		root = new node();
	}
	node*temp = root;
	void insert (int n){
		

		for(int i =31;i>=0;i--){
			int bit = (n>>i)&1; 
			if(bit==0){
				if(temp->left==NULL){
					temp->left = new node();
				} 
				temp=temp->left;
			}
			else{
				if(temp->right==NULL){
					temp = temp-> left;
				}
				temp = temp ->right;
			}
		}
	}

	//To find XOR

	int max_xor_helper(int value){
		int current_ans = 0;
		for(int j=31;j>=0;j--){
			int bit = (value>>j)&1;

			if(bit==0){
				//find a complementry bit
				if(temp->right!=NULL){
					temp = temp->right;
					current_ans+=(1<<j);
				}
				else{
					temp = temp->left;
				}

			}

		}
		return current_ans;
	}
	int max_xor(int *input,int n){
		int max_xor = 0;

		for(int i=0;i<n;i++){
			int val = input[i];
			insert(val);
			int current_xor = max_xor_helper(val);
			cout<<current_xor<< "  "; 
			max_xor = max(current_xor,max_xor);		
		}
		return max_xor;
	}

};

int main(){

	int input[] = {3,10,5,25,2,8};
	trie t;
	cout<<t.max_xor(input,6)<<endl;

	return 0;
}