#include <iostream>
using namespace std;
class node {
public:
    long long int data;
    node *next;
    node(long long int d){
        data = d;
        next = NULL;
    }
};

void prinext(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;	
	}
}

void getLinkedList(node *&head,long long int n){
    long long int x;
    cin>>x; //first input;
    head = new node(x);
    node* currenext = head;
        for(long long int i=1;i<n;i++){
        cin>>x;
        node *a = new node(x);
        currenext->next = a;
        currenext = a;
    } 
    currenext->next = NULL;
}
node* reverse(node* head){
	node* currenext = head;
	node* previous =NULL;
	node* n;

	while(currenext!=NULL){
		n = currenext-> next;
		currenext->next = previous;
		previous = currenext;
		currenext = n;
	}
	return previous;
}

node* kReverse(node* head,int k) 
{ 
    int x=k;
    node *currenext = head; 
    node *prev = NULL;
    node *n = NULL; 
    while (currenext != NULL && x>0)
    { 
        n = currenext->next; 
        currenext->next = prev; 
        prev = currenext; 
        currenext = n;
        x--;
      //  cout<<n->data<<" "<<endl;
    } 
    if(n != NULL){
        head->next = kReverse(n,k);
    }
    
    return prev;
} 


bool palindromeChecker(node* &head,node* &head2)
{
	while(head!=NULL && head2!=NULL)
	{
		if(head->data!=head2->data)
		{
			return false;
			break;
			
		}
		head=head->next;
		head2=head2->next;
		
	}
	return true;
}

int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    node *head = NULL;
    // node *head2 = NULL;
    long long int n,k;
    cin>>n>>k;
    getLinkedList(head,n);
    head = kReverse(head,k);
    prinext(head);
    // head2 = reverse(head);
 //        	if(palindromeChecker(head,head2))
	// {
	// 	cout<<"true";
	// }
	// else
	// {
	// 	cout<<"false";
	// }


    return 0;
 }
