#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size;

void initTree(){
    for(int i = 0;i < MAX_SIZE; i++){
        tree[i] = -1;
    }
}
    void insert(int value){
        if (size >= MAX_SIZE){
            printf("Tree is full!\n");
            return;
        }
        int index = 0;
        while(index < MAX_SIZE) {
            if (tree[index] == -1){
                tree[index] = value;
                size++;
                return;
            }
            if(value < tree[index]){
                index = 2 * index + 1;
            } else {
                index = 2 * index + 2;
            }
        }
    }
    
void inOrderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    inOrderTraversal(2 * index + 1);
    printf("%d ", tree[index]);
    inOrderTraversal(2 * index + 2);
}
int main() {
    initTree();
    insert(23);
    insert(44);
    insert(53);
    insert(72);
    insert(99);
    insert(3);
    insert(7);
    insert(11);
    insert(1);
    
    printf("\nIn order traversal of BST: \n");
    inOrderTraversal(0);
    printf(" \n");
    return 0;
}
