
#include<iostream>
#include<queue>
#include<vector>
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
        int count = mq.size();
        for(int i = 0 ; i < count ; i++){
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

bool find(node* root,vector<int>& path, int data){


        if(root == NULL){
            return false;
        }
        if(root->data == data){
            path.push_back(root->data);
            return true;
        }
        bool filt = find(root->left ,path , data);
        if(filt){
            path.push_back(root->data);
            return true;
        }

        bool firt = find(root->right , path , data);
        if(firt){
              path.push_back(root->data);
            return true;
        }

        return false;
}


int main(){ 
    node* root = buildTree();
    vector<int> path;
    // Pair p = fastDiameter(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;
    printlevelorder(root);
    bool found = find(root,path,87);
    if(found){
        cout<<"true"<<endl;
           vector<int>:: iterator it;
          for(it=path.begin();it<path.end();it++)
           {
             cout<<*it<<" ";
           }
    }
    else{
        cout<<"false";
    }
    return 0;
}