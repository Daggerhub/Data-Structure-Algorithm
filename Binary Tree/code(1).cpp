
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class node
{
	public:
	    int data;
		node*left;
		node*right;
        node(int d,node* left,node* right)
        {
            this->data=d;
            this->left=left;
        	this->right=right;
        }
};

class diapair{
    public:
    int ht;
    int diameter;
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d,NULL,NULL);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


void print(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printsinglechildnode(node* n , node* parent){
    if(n == NULL){
        return;
    }
    if(parent != NULL && parent->left == n && n->right == NULL){
        cout<<n->data<<endl;
    }
    else if(parent != NULL && parent->right == n && n->left == NULL){
        cout<<n->data<<endl;
    }
    printsinglechildnode(n->left,n);
    printsinglechildnode(n->right,n);
    
}
 
 node* removeleaves(node* n){

     if(n == NULL){
         return NULL;
     }

     if(n->left == NULL && n->right == NULL){
         return NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
     }

     n->left = removeleaves(n->left);
     n->right = removeleaves(n->right);

     return n;
 }

 diapair* dia(node* n){
if(n == NULL){
    diapair* bp = new diapair();
    bp->ht = -1;
    bp->diameter = 0;
     return bp;
}

    diapair* lp = dia(n->left);
    diapair* rp = dia(n->right);

    diapair* mp = new diapair();
    mp->ht = max(lp->ht, rp->ht) + 1;

    int fes = lp->ht +rp->ht + 2;
    mp->diameter = max(fes, max(lp->diameter , rp->diameter));

    return mp;
 }
 
int main(){ 

    node* root = buildTree();
    // leftclonedtree(root);
    // print(root);
    // cout<<endl;
    // backtonormal(root);
    // printsinglechildnode(root,NULL);
    // print(root);
    // removeleaves(root);
    // print(root);
    diapair* res = dia(root);
    cout<<res->diameter;
 
    return 0;
}

// #input
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// #output
// 50 50 25 25 12 12 37 37 30 30 75 75 62 62 70 70 87 87 
// 50 25 12 37 30 75 62 70 87 