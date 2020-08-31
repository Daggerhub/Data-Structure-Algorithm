#include <iostream>
using namespace std;
class node {
public:
    long data;
    node *next;
    node(long d){
        data = d;
        next = NULL;
    }
};

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void getLinkedList(node *&head,long n){
    long x;
    cin>>x; //first input;
    head = new node(x);
    node *current = head;
    for(long i=1;i<n;i++){
        cin>>x;
        node *a = new node(x);
        current->next = a;
        current = a;
    }
    current->next = NULL;
}

node* appendK(node *head,long k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i<k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    node *head = NULL;
    long n;
    cin>>n;
    getLinkedList(head,n);
    //print(head);
    long k ;
    cin>>k;
    k=k%n;
    if(k==0)print(head);
    else{
        head = appendK(head,k);
        print(head);}
    return 0;
}