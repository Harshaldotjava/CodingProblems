#include <iostream>
#include "linkList.h"
using namespace std;

ListNode *reverse(ListNode *head){
    if(head == NULL || head->next == NULL)
        return head;

    ListNode *rhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rhead;
}

int main(){

    return 0;
}
