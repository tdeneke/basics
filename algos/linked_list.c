#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* nalloc(int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p!=NULL){
        p->data = data;
        p->next = NULL;
    }
    return p;
}

struct node* addfront(struct node* head, int data){
     struct node* p = nalloc(data);
     if(p==NULL) return head;
     p->next = head;
     return p;
}

void display(struct node* head){
    while(head->next != NULL){
        printf("%d\n",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}

struct node* addback(struct node* head, int data){
    struct node* orig = head;
    struct node* new = nalloc(data);
    while(head->next != NULL){
        head = head->next;
    }
    if(new==NULL) return orig;
    head->next = new;
    return orig;
}

struct node* find(struct node* head, int data){
    struct node* temp = head;
    while(temp->next != NULL){
        if(temp->data == data) return temp;
        temp = temp->next;
    }
    if(temp->data == data) return temp;
    return NULL;
}

struct node* delnode(struct node* head, struct node* pelement){
    struct node* prev = head;
    struct node* temp = head;
    while(temp->next != NULL){

    }
    return head;
}

void freelist(struct node* head){

}

int main(void){
    struct node* head = nalloc(-1);
    head = addfront(head,0);
    head = addfront(head,1);
    head = addfront(head,2);
    head = addfront(head,3);
    printf("this is a simple linked list implementation\n");
    //display(head);
    head = addback(head,-2);
    //display(head);
    head = addback(head,-3);
    //display(head);
    struct node* elem = find(head, -3);
    display(elem);
    return 0;
}
