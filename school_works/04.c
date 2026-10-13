#include <stdio.h>
#include <stdlib.h>

// 单链表结点结构体定义
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 创建带头结点的单循环链表（尾插法）
void createCircularList(LinkList *L, int arr[], int n) {
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = *L; // 初始指向自己，形成空循环
    LNode *r = *L;
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = *L; // 新结点指向头结点
        r->next = p;
        r = p;
    }
}

// 打印单循环链表
void printCircularList(LinkList L) {
    if (L->next == L) {
        printf("链表为空\n");
        return;
    }
    LNode *p = L->next;
    printf("链表内容：");
    while (p != L) { // 循环直到回到头结点
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("回到头结点\n");
}

// 核心算法：单循环链表逆置
void reverseCircularList(LinkList L) {
    if (L == NULL || L->next == L) {
        return; // 空表或只有头结点，无需逆置
    }
    
    LNode *pre = L->next;       // 第一个实际结点
    LNode *curr = pre->next;    // 第二个实际结点
    LNode *next;
    
    // 将原第一个结点的next指向头结点，作为逆置后的尾结点
    pre->next = L; 
    
    while (curr != L) {         // 遍历直到回到头结点
        next = curr->next;      // 暂存下一个结点
        curr->next = pre;       // 当前结点指向前驱（逆置）
        pre = curr;             // 指针后移
        curr = next;
    }
    
    // 头结点指向原来的尾结点（现在的第一个结点）
    L->next = pre;
}

int main() {
    LinkList L;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    createCircularList(&L, arr, n);
    
    printf("逆置前：");
    printCircularList(L);
    
    reverseCircularList(L);
    
    printf("逆置后：");
    printCircularList(L);
    
    return 0;
}