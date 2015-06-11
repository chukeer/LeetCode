/**
 * Definition for singly-linked list.
 */
#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }
    struct ListNode* head = NULL;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    if (p->val < q->val)
    {
        head = p;
        p = p->next;
    }
    else
    {
        head = q;
        q = q->next;
    }
    struct ListNode* tail = head;
    //head = p->val < q->val ? p : q;
    while(p && q)
    {
        if (p->val < q->val)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }
    if (p)
    {
        tail->next = p;
    }
    if (q)
    {
        tail->next = q;
    }
    return head;
}

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

int main()
{
    int data1[] = {1, 3};
    int data2[] = {2, 4};
    struct ListNode* l1 = CreateList(data1, 2);
    struct ListNode* l2 = CreateList(data2, 2);

    PrintList(l1);
    PrintList(l2);

    struct ListNode* head = mergeTwoLists(l1, l2);
    PrintList(head);
    return 0;
}
