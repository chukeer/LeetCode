#include "list.h"
#include <stdio.h>
#include <stdlib.h>
void PrintList(struct ListNode* head)
{
    struct ListNode* p = head;
    while(p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

struct ListNode* CreateList(int* data, int n)
{
    struct ListNode* head = NULL;
    struct ListNode** tail = &head;
    for (int i = 0; i < n; ++i)
    {
        int val = data[i];
        *tail = (struct ListNode*)malloc(sizeof(struct ListNode));
        (*tail)->val = val;
        (*tail)->next = NULL;
        tail = &((*tail)->next);
    }
    return head;
}

