#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int left[MAX_SIZE];
int right[MAX_SIZE];
int size;

int height(int index) {
    if(index >= MAX_SIZE || tree[index] == -1)
        return 0;
        int leftheight = height(left[index]);
        int rightheight = height(right[index]);
    return 1 + (leftheight> rightheight ? leftheight: rightheight);
}
int balancefactor(int index){
  if (index >= MAX_SIZE || tree[index] == -1)
    return 0;
  return height(left[index]) - height(right[index]); 
    
}
void rightrotate(int index){
    int leftchild = left[index];
    left[index] = right[leftchild];
    if (right[leftchild] != -1){
        left[right[leftchild]] = index;
    }
    right[leftchild] = index;
} 
void leftrotate(int index){
    int rightchild = right[index];
    right[index] = left[rightchild];
    if (left[rightchild] != -1){
        right[left[rightchild]] = index;
    }
    left[rightchild] = index;
}
void rebalance (int index) {
    if(index >= MAX_SIZE || tree[index] == -1) return;
    
    int balance = balancefactor(index);
    if (balance >1){
        if (balancefactor(left[index]) < 0){
            leftrotate(left[index]);
        }
        rightrotate(index);
    }else if(balance < -1){
        if ( balancefactor(right[index]) > 0){
            rightrotate(right[index]);
            
        }
        leftrotate(index);
    }
}
void insertNode(int index, int value){
    if(tree[index] == -1){
        tree[index] = value;
        left[index] = -1;
        right[index] = -1;
        size++;
        return;
    }
    if(value < tree[index]){
        if(left[index] == -1){
            left[index] = size;
            tree[size] = -1;
            right[size] = -1;
            size++;
        }else {
            insertNode(left[index],value);}
    }else{
        if (right[index] == -1){
            right[index] = size;
            tree[size] = -1;
            right[size] = -1;
            size++;
        }else {
            insertNode(right[index],value);
        }
    }
   rebalance(index); 

    
}

void initTree(){
    for(int i = 0;i < MAX_SIZE;i++){
        tree[i] = -1;
        left[i] = -1;
        right[i] = -1;
    }
    size = 0;
    
}
    void insert(int value){
        if (size >= MAX_SIZE){
            printf("Tree is full!\n");
            return;
        }
        if (size == 0) {
            tree[size] = value;
            left[size] = -1;
            right[size] = -1;
            size++;
        } else {
            insertNode(0,value);
        }
        
        }
    
    


void inOrderTraversal(int index){
    if( index>= MAX_SIZE || tree[index] == -1)
    return;
    inOrderTraversal(left[index]);
    printf("%d ",tree[index]);
    inOrderTraversal(right[index]);
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
    
    printf("\nIn order traversal of AVL tree: \n");
    inOrderTraversal(0);
    printf(" \n");
    return 0;
}
