//
//  main.c
//  binary search tree
//
//  Created by Asude Ekiz on 13.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}NODE;


NODE * newNode(int data);
void inorder(NODE *root);
NODE* insert(NODE* root,int data);
NODE* minValueNode(NODE *root);
NODE * maxValueNode(NODE *root);

int main(int argc, const char * argv[]) {
    
    return 0;
}
NODE * newNode(int data){
    NODE* new=malloc(1*sizeof(NODE));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void inorder(NODE *root){
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}
NODE* insert(NODE* root,int data){
    if (root==NULL) {
        root=newNode(data);
    }
    if (data<root->data) {
        root->left=newNode(data);
    }
    else{
        root->right=newNode(data);
    }
    return root;
}

NODE* minValueNode(NODE *root){
    NODE *current=root;
    while (current!=NULL &&current->left!=NULL) {
        current=current->left;
    }
    if (current->left==NULL) {
        //printf("Bulundu.\n");
    }
    return current;
}
NODE * maxValueNode(NODE *root){
    NODE* current=root;
    while (current!=NULL && current->right!=NULL) {
        current=current->right;
    }
    return current;
}
NODE* delete(NODE*root,int data){
    if (root==NULL) {
        return root;
    }
    if (data<root->data) {
        root->left=delete(root->left, data);
    }
    else if (data>root->data) {
        root->right=delete(root->right, data);
    }
    else {//demek ki silinecek degeri bulduk.
        //tek cocuklu ya da cocuksuzsa
        if (root->left==NULL) {
            NODE*tmp=root->right;
            free(root);
            return tmp; //tmp uzerinden sagın en kucugunu bulucaz
        }
        if (root->right==NULL) {
            NODE*tmp=root->left;
            free(root);
            return tmp;
        }
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        NODE* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
        
    }
    return root;
}


