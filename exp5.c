#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node* next;
} ;
struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertatbeginning(struct node** head_ref,int data){
    struct node* newnode = createnode(data);
    newnode->next = *head_ref;
    *head_ref = newnode;
    
}
void insertatend(struct node** head_ref,int data){
    struct node* newnode = createnode(data);
    if(*head_ref == NULL){
        *head_ref = newnode;
        return;
    }
    struct node* temp = *head_ref;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
        
    }
void insertafter(struct node* prev_node, int data) {
    if(prev_node == NULL){
        printf("the given previous node cannot be null\n");
        return;
    }
    struct node* newnode = createnode(data);
    newnode->next = prev_node->next;
    prev_node->next = newnode;
}
void deletenode(struct node** head_ref,int key){
    struct node* temp = *head_ref;
    struct node* prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
     if (temp == NULL) return;

    
    prev->next = temp->next;
    free(temp);
}
void traverseList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct node* searchList(struct node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head; 
        }
        head = head->next;
    }
    return NULL; 
}
int main() {
     struct node* head = NULL;

   
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatbeginning(&head, 5);
    insertafter(head->next, 15); 

   
    printf("Linked List: ");
    traverseList(head);

   
    int key = 15;
    struct node* result = searchList(head, key);
    if (result != NULL) {
        printf("Node with value %d found.\n", key);
    } else {
        printf("Node with value %d not found.\n", key);
    }
    int key1 = 10;
    struct node* result1 = searchList(head, key1);
    if (result1 != NULL) {
        printf("Node with value %d found.\n", key1);
    } else {
        printf("Node with value %d not found.\n", key1);
    }
   
    deletenode(&head, 20); 
  deletenode(&head, 10); 
   int key2 = 10;
    struct node* result2 = searchList(head, key2);
    if (result2 != NULL) {
        printf("Node with value %d found.\n", key2);
    } else {
        printf("Node with value %d not found.\n", key2);
    }
    printf("Linked List after deletion: ");
    traverseList(head);

    return 0;
}
