#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};
Node *createBST(Node *root,Node *newnode){
    if(root==NULL){
        root=newnode;
        return newnode;
    }
    else{
        if(newnode->data<=root->data){
            root->left=createBST(root->left,newnode);
        }
        else if(newnode->data>root->data){
            root->right=createBST(root->right,newnode);
        }
    }
    return root;
}

void display(Node *root){
    if(root==NULL){
        return;
    }
    else{
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}
int main(){
    int n,val;
    Node *root=NULL;
    cout<<"Enter no.of elements in the tree:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element:";
        cin>>val;
        Node *newnode=new Node(val);
        root=createBST(root,newnode);
    }
    display(root);
}


