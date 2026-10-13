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

// 顺序表去重
void deleteDuplicates(SqList *L) {
    if (L->length == 0) {
        return; // 空表无需去重
    }

    int k = 0; // 记录当前不重复元素的索引

    // i 当前元素的索引
    for (int i = 1; i < L->length; i++) {
        // 如果当前元素与上一个元素不同
        if (L->data[i] != L->data[k]) {
            k++; // 更新当前不重复元素的索引
            L->data[k] = L->data[i]; // 复制当前元素到当前不重复元素的索引
        }
    }

    // 更新表长
    L->length = k + 1;
}

int main() {
    SqList L;
    // 初始化顺序表
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    initList(&L, arr, n);
    
    printf("去重前：");
    printList(L);

    deleteDuplicates(&L);

    printf("去重后：");
    printList(L);

    return 0;
}