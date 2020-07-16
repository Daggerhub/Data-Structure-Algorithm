 
#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node* left;
		node* right;
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
class Pair {
     public:
     	int height;
     	int diameter;
};


node* buildtree()        
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}
	node* root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
void bfs(node *root){
      
     queue<node*> q;
     q.push(root);
   	  
     while(!q.empty()){

     	node* f = q.front();
     	cout<<f->data<<",";
     	q.pop();
     

     if(f->left){
     	q.push(f->left);
     	
     }
     if(f->right){
     	q.push(f->right);
     }

    }
    return;
}

int count(node*root){
	if(root==NULL){
		return 0;
	}

	return 1 + count(root->left) + count(root->right);

}

Pair fastDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.diameter = p.height=0;
		return p;
	}
	Pair left =fastDiameter(root->left);
	Pair right =fastDiameter(root->right);

	p.height = max(left.height,right.height) + 1;
	p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
	return p;

}
 
int replacesum(node*sum){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int leftsum = replacesum(root->left);
	int rightsum = replacesum(root->right)

	int temp = root->data;
	root->data = leftsum +rightsum;

	return temp + root->data;
}


int main(){

	node* root =buildtree();
	// bfs(root);
	Pair p = fastDiameter(root);
    cout<<endl;
    cout<<p.height<<p.diameter;
     
}
