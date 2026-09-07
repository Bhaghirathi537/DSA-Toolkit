#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data=val;
            left=right=NULL;
        }
};

static int idx=-1;
Node *buildTree(int preOrder[]){
    idx++;
    if(preOrder[idx]==-1){
        return NULL;
    }
    Node *root=new Node(preOrder[idx]);
    root->left=buildTree(preOrder);
    root->right=buildTree(preOrder);
    return root;
}

void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int n,*arr;
    cout<<"Enter the no.of elements in seq:";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element:";
        cin>>arr[i];
        Node n(arr[i]);
    }
    Node *root=buildTree(arr);
    cout<<"PRE-ORDER TRAVERSAL:"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"IN-ORDER TRAVERSAL:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"POST-ORDER TRAVERSAL:"<<endl;
    postOrder(root);
    return 0;
}

