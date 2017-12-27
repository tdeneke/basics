#include<stdio.h>
#include<stdlib.h>

struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(int data){
    struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
    if(node != NULL){
        node->data = data;
        node->left = node->right = NULL;
    }
    return node;
}


struct tnode* addnode(struct tnode* root, int data){
    if(root == NULL){
        struct tnode* node = talloc(data);
        return (root = node);
    }else if(data < root->data){
        root->left = addnode(root->left, data);
    }else if(data > root->data){
        root->right = addnode(root->right, data);
    }
    return root;
}

void preorder(struct tnode* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct tnode* root){
     if(root == NULL) return;
     inorder(root->left);
     printf("%d ", root->data);
     preorder(root->right);
}

int deltree(struct tnode* root){
    int count = 0;
    if(root == NULL) return;
    count += deltree(root->left);
    count += deltree(root->right);
    free(root);
    return ++count;
}

int main(void){
    printf("this is a simple tree implementation!\n");
    struct tnode* root = addnode(NULL, 3);
    root = addnode(root, 1);
    root = addnode(root, 0);
    root = addnode(root, 2);
    root = addnode(root, 8);
    root = addnode(root, 6);
    root = addnode(root, 5);
    root = addnode(root, 9);

    puts("should print 3,1,0,2,8,6,5,9");
    preorder(root); puts(" ");
    puts("should print 0,1,2,3,5,6,8,9");
    inorder(root); puts(" ");
    int count = deltree(root); root = NULL;
    printf("%d\n",count);
    return 0;
}
