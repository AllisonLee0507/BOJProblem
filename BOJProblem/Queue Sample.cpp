#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <stdlib.h>

struct selfref {
   int n;
   struct selfref *next;
};
typedef struct selfref list;

int main(void)
{
   list *first;
   first = (list *)malloc(sizeof(list)*3);
   first[0].n = 100;
   first[1].n = 200;
   first[2].n = 300;
    
   first[0].next = (first+1);
   first[1].next = (first+2);
   first[2].next = NULL;

   printf("첫 번째 구조체 >> ");
   printf("\t자료의 주소값(first) = %#X\n", (first+0));
   printf("\t자료값(first->n) = %d\n", first[0].n);
   printf("\t자료값(first->next) = %#X\n", first[0].next);
   printf("\t자료값(first->next->n) = %d\n\n", (first[0].next)->n);
   
   printf("두 번째 구조체 >> ");
   printf("\t자료의 주소값(second) = %#X\n", (first+1));
   printf("\t자료값(second->n) = %d\n", first[1].n);
   printf("\t자료값(second->next) = %#X\n", first[1].next);
    
    
   printf("두 번째 구조체 >> ");
   printf("\t자료의 주소값(second) = %#X\n", (first+2));
   printf("\t자료값(second->n) = %d\n", first[2].n);
   printf("\t자료값(second->next) = %#X\n", first[2].next);

   free(first);

   return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main(){
    struct node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    getchar();
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main(){
    Node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void printPostorder(Node* node){
    if(node == NULL){
        return;
    }
    printPostorder(node-> left);
    printPostorder(node-> right);
    printf("%d ", node->data);
}

void printlnorder(Node* node){
    if(node == NULL){
        return;
    }
    printlnorder(node->left);
    printf("%d ", node->data);
    printlnorder(node->right);
}

void printPreorder(Node* node){
    if(node ==NULL){
        return;
    }
    printf("%d " , node -> data);
    printPreorder(node->left);
    printPreorder(node -> right);
}
int main(){
    Node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
    
    printf("\nlnorder traversal of binary tree is\n");
    printlnorder(root);
    
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
    
    getchar();
    return 0;
}

#endif

#if 0
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data){
    Node* newNode = new Node();
    if(!newNode){
        cout << "Memory error \n";
        return NULL;
    }
    newNode ->data = data;
    newNode ->left  = NULL;
    newNode -> right = NULL;
    return newNode;
}
Node* InsertNode(Node* root, int data){
    if(root == NULL){
        root = CreateNode(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp -> left!= NULL){
            q.push(temp -> left);
        }
        else{
            temp -> left = CreateNode(data);
            return root;
        }
        if(temp ->right!= NULL){
            q.push(temp ->right);
        }
        else{
            temp -> right = CreateNode(data);
            return root;
        }
    }
    return root;
}
void inorder(Node* temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
void preorder(Node* temp){
    if(temp == NULL){
        return;
    }
    cout << temp->data << ' ';
    inorder(temp->left);
    inorder(temp->right);
}
void postorder(Node* temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    inorder(temp->right);
    cout << temp->data << ' ';
}
int main(){
    Node* root = CreateNode(10);
    root -> left = CreateNode(11);
    root -> left -> left = CreateNode (7);
    root -> right = CreateNode(9);
    root -> right -> left = CreateNode(15);
    root -> right -> right = CreateNode(8);
    
    cout << "Inorder traversal before insertion1: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder traversal before insertion: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal before insertion: ";
    postorder(root);
    cout << endl;
    
    int key = 12;
    root = InsertNode(root, key);
    cout << "Inorder traversal before insertion2: ";
    inorder(root);
    cout << "Preorder traversal before insertion2: ";
    preorder(root);
    cout << "Postorder traversal before insertion2: ";
    postorder(root);
    
    cout << endl;
    
    return 0;
}
#endif
