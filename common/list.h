#ifndef COMMON_LIST_H_
#define COMMON_LIST_H_

struct ListNode
{
    int val;
    struct ListNode* next;
};
void PrintList(struct ListNode* head);
struct ListNode* CreateList(int* data, int n);

#endif
