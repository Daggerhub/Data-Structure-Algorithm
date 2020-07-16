//order of n^2 printklevel


#include<iostream>
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


void printin(node*root)         //inoder traversal
{
	if (root==NULL)
	{
		return;
	}                           //else print the left, root and right
	printin(root->left);
	cout<<root->data<<" ";
	printin(root->right);
}


void printpost(node*root)       //postoder traversal
{
	if (root==NULL)
	{
		return;
	}                           //else print the left, right and root
	printin(root->left);
	printin(root->right);
	cout<<root->data<<" ";
}


void printpre(node* root)      //preorder traversal
{
	if(root==NULL)
	{
		return;
	}                         //else print the root, left and right
	cout<<root->data<<" ";
	printpre(root->left);     //left node now become the root and get printed as a root and further printed till left node is null
	printpre(root->right);    //same goes with the right node
}

int height(node*root){
if(root==NULL){
	return 0;
}
int ls = height(root ->left);
int rs = height(root ->right);
   return max(ls,rs) +1;
}

void printklevel(node*root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printklevel(root->left,k-1);
	printklevel(root->right,k-1);
	return;
}



int main()
{
	node* root=buildtree();
	// printpre(root);
	// cout<<endl;
	// printin(root);
	// cout<<endl;
	// printpost(root);
	// cout<<endl;

 //    cout<<height(root)<<endl;
	 printklevel(root,1);

	return 0;
}