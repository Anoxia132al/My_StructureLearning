#include <stdio.h>

#define MAXSIZE 100

// 顺序表结构体定义
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 顺序表初始化
void initList(SqList *L, int arr[], int n) {
    if (n > MAXSIZE) return;
    for (int i = 0; i < n; i++) {
        L->data[i] = arr[i];
    }
    L->length = n;
}

// 顺序表打印
void printList(SqList L) {
    printf("[ ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("]\n");
}

// 顺序表负数移动到前面
void moveNegativeToFront(SqList *L) {
    int left = 0;
    int right = L->length - 1;
    int temp;

    while (left < right) {
        // 找到第一个大于0的元素位置
        while (left < right && L->data[left] < 0) {
            left++;
        }
        // 找到最后第一个小于0的元素位置
        while (left < right && L->data[right] >= 0) {
            right--;
        }
        // 交换两个元素
        if (left < right) {
            temp = L->data[left];
            L->data[left] = L->data[right];
            L->data[right] = temp;
        }
    }
}

int main() {
    SqList L;
    // 测试数据：
    int arr[] = {1, -2, 3, -4, 5, -6, 0, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    initList(&L, arr, n);
    
    printf("移动前：");
    printList(L);

    moveNegativeToFront(&L);

    printf("移动后：");
    printList(L);

    return 0;
}