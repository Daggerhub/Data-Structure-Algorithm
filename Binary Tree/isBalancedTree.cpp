#include <bits/stdc++.h> 
using namespace std;
class node
{
	public:
	    int data;
		node*left;
		node*right;
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}	
};
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

static bool isbalanced = true;
 int balanced(node* n){

     if(n == NULL){
         return 0;
     }

     int lh = balanced(n->left);
     int rh = balanced(n->right);

     int gap = abs(lh - rh);
     if(gap > 1){
         isbalanced = false;
     }

     int th = max(lh,rh) + 1;
     return th;
 }



int main(){ 
    node* root = buildTree();
    balanced(root);
    cout<<isbalanced;
    return 0;
}
 
//  #input
//  50 25 12 -1 -1 37 30 -1 -1 51 -1 -1 75 62 60 -1 -1 70 -1 -1 -1
//  #output
//  0