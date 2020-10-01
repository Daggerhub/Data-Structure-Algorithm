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

class istree
{
public:
    bool isBST;
    int min;
    int max;
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

istree* isBST(node* n){

    if(n == NULL){
        istree* bp = new istree();
        bp->min = INT_MIN;
        bp->max = INT_MAX;
        bp->isBST = true;
        return bp;
    }

    istree* lp = isBST(n->left);
    istree* rp = isBST(n->right);

    istree* mp = new istree();
    mp->isBST = lp->isBST && rp->isBST && (n->data >= lp->max && n->data <= rp->min);

    mp->min = min(n->data, min(lp->min,rp->min));
    mp->max = max(n->data, max(lp->max,rp->max));
    return mp;
}

int main(){ 
    node* root = buildTree();
    istree * bp = isBST(root);
    cout<<bp->min;
    return 0;
}
 