#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
class BinarySearchTree{
    Node *root;
    public:
        BinarySearchTree(){
            root=NULL;
        }

        Node *buildBST(Node *root,int val){
            if(root==NULL){
               Node *newnode=new Node;
               newnode->data=val;
               newnode->left=NULL;
               newnode->right=NULL;
               return newnode;
            }
            else if(root->data>=val){
                root->left=buildBST(root->left,val);
            }
            else if(root->data<val){
                root->right=buildBST(root->right,val);
            }
            return root;
        }
        void insert(int val){
            root=buildBST(root,val);
        }
        void inorder(Node *root){
            if(root==NULL){
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        void preorder(Node *root){
            if(root==NULL){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
        void postorder(Node *root){
            if(root==NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
        
        Node *getRoot(){
            return root;
        }
        bool searchBST(Node *root,int key){
            if(root==NULL){
                return false;
            }
            if(key==root->data){
                return true;
            }
            else if(key>root->data){
                return searchBST(root->right,key);
            }
            else if(key<root->data){
                return searchBST(root->left,key);
            }
            else{
                return false;
            }
        }
        Node *getInorderSuccessor(Node *root){
            while(root!=NULL && root->left!=NULL){
                root=root->left;
            }
            return root;
        }
        Node *delNode(Node *root,int delkey){
            if(root==NULL){
                return NULL;
            }
            if(delkey<=root->data){
                root->left=delNode(root->left,delkey);
            }
            else if(delkey>root->data){
                root->right=delNode(root->right,delkey);
            }
            else{
                if(root->right==NULL){
                    Node *temp=root->left;
                    delete root;
                    return temp;
                }
                else if(root->left==NULL){
                    Node *temp=root->right;
                    delete root;
                    return temp;
                }
                else{
                    Node *IS=getInorderSuccessor(root->right);
                    root->data=IS->data;
                    root->right=delNode(root->right,IS->data);
                }
            }
            return root;
        }
};
int main(){
    int n,val,key,delkey;
    BinarySearchTree b;
    cout<<"Enter no.of nodes in a tree:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the data of node "<<i+1<<":";
        cin>>val;
        b.insert(val);
    }
    cout<<"INORDER TRAVERSAL:"<<endl;
    b.inorder(b.getRoot());
    cout<<endl;
    cout<<"PREORDER TRAVERSAL:"<<endl;
    b.preorder(b.getRoot());
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL:"<<endl;
    b.postorder(b.getRoot());
    cout<<endl;
    cout<<"Enter the key node to be searched:";
    cin>>key;
    bool found=b.searchBST(b.getRoot(),key);
    if(found==true){
        cout<<key<<" is found in the tree"<<endl;
    }
    else{
        cout<<key<<" is not found!"<<endl;
    }
    cout<<endl;
    cout<<"Enter the node to be deleted:"<<endl;
    cin>>delkey;
    b.delNode(b.getRoot(),delkey);
    return 0;
}