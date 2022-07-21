#include <iostream>
#include "linkList.h"
#include <map>
using namespace std;


ListNode * giveCycleNode(ListNode *head){
    map<ListNode*,bool> mp;

    auto temp = head;
    while(temp){
       if(mp.find(temp) != mp.end())
           return temp;
       mp[temp] = true;
       temp = temp->next;
    }

    return NULL;
}


int  main(){

    return 0;
}
