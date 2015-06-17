#include <stdio.h>
#include <stdbool.h>
#include "list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 往后找第K个节点，并返回实际步长
struct ListNode* NextK(struct ListNode* p, int k, int* real_step)
{
    struct ListNode* q = p;
    *real_step = 0;
    for (int i = 0; i < k; ++i)
    {
        if (q)
        {
            q = q->next; 
            ++*real_step;
        }
        else
        {
            break;
        }
    }
    return q;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    if (NULL == head)
    {
        return NULL;
    }
    int count = 0;
    struct ListNode* new_head = head;
    struct ListNode* p = head;
    while (true)
    {
        int step = 0;
        struct ListNode* p_next_k = NextK(p, k, &step);
        // 剩余节点数少于K，则不用反转
        if (step < k)
        {
            break;
        }

        struct ListNode* next = p->next;
        // 找真正指向的节点，如果往后第2k-1个节点存在，则指向它，否则指向往后第k个节点
        struct ListNode* real_pnext = NextK(p_next_k, k-1, &step);
        if (real_pnext)
        {
            p->next = real_pnext;
        }
        else
        {
            p->next = p_next_k;
        }
        while (next != p_next_k)
        {
            struct ListNode* next_next = next->next;
            next->next = p;
            if (count == 0)
            {
                new_head = next;
            }
            p = next;
            next = next_next;
        }
        p = next;
        ++count;
    }
    return new_head;
}

int main()
{
    {

    int data[] = {1,2};
    struct ListNode* head = CreateList(data, 2);

    printf("before:\n");
    PrintList(head);

    struct ListNode* new_head = reverseKGroup(head, 2);
    printf("k:%d after:\n", 2);
    PrintList(new_head);
    }
    {

    int data[] = {1,2,3,4,5};
    struct ListNode* head = CreateList(data, 5);

    printf("before:\n");
    PrintList(head);

    struct ListNode* new_head = reverseKGroup(head, 2);
    printf("k:%d after:\n", 3);
    PrintList(new_head);
    }

    return 0;
}
