#include <iostream>
#include <queue>
#include <algorithm>
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

void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node *curr=q.front();
        q.pop();
        cout<<curr->data;
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    return max(left_height,right_height)+1;
}

int countOfNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    int left_count=countOfNodes(root->left);
    int right_count=countOfNodes(root->right);
    return left_count+right_count+1;
}

int sumOfNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    int left_sum=sumOfNodes(root->left);
    int right_sum=sumOfNodes(root->right);
    return left_sum+right_sum+root->data;
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

