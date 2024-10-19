# include <stdio.h>
int binarysearch(int arr[],int size, int target){
    int left = 0;
    int right = size - 1;
    
    while(left <= right){
        int mid = left + (right + left) / 2;
        
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int bookIDs[] = {101, 203, 304, 405, 506, 607, 708, 809, 910};
    int size = sizeof(bookIDs) / sizeof(bookIDs[0]);
    int target;
    printf("Enter the bookID to search for:");
    scanf("%d",&target);
    int result = binarysearch(bookIDs , size, target);
    if (result != -1){
        printf("Book ID %d found at index %d.\n", target , result);
    }else{
        printf("Book ID %d not found .\n",target);
    }
    return 0;
}
