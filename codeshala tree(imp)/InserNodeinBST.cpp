#include <iostream>
#include <algorithm>
using namespace std;
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;
struct node * getnewnode(int data){
    node * newnode=new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node * insertNode(struct node * tNode, int value) {
	if(tNode==NULL){tNode=getnewnode(value);}
	else if(value<=tNode->data){tNode->left=insertNode(tNode->left,value);}
	else{tNode->right=insertNode(tNode->right,value);}
return tNode;
}

void buildTree(int a[], int N) {
	for(int i = 0; i < N; i++) {
		if(i) {
			insertNode(root, a[i]);
		} else {
			root = insertNode(NULL, a[i]);
		}
	}
}

void inOrderTraversal(struct node * tNode) {
	if(tNode == NULL)
		return;
	inOrderTraversal(tNode->left);
	cout << tNode->data << endl;
	inOrderTraversal(tNode->right);
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	inOrderTraversal(root);
}
