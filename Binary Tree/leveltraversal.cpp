
#include<iostream>
#include<queue>
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


void printlevelorder(node * root){
    queue<node*> mq;
    mq.push(root);
    while(!mq.empty()){
        for(int i = 0 ; i < mq.size() ; i++){
            node* n = mq.front();
            mq.pop();
            cout<<n->data<<" ";
            if(n->left != NULL){
                mq.push(n->left);
            }
            if(n->right != NULL){
                mq.push(n->right);
            }
        }
        cout<<endl;
    }
}

int main(){ 
    node* root = buildTree();
    // Pair p = fastDiameter(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;
    printlevelorder(root);
    return 0;
}