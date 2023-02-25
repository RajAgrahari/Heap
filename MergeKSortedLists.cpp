// https://leetcode.com/problems/merge-k-sorted-lists/
ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto it:lists)
        {
            if(it!=NULL)
            pq.push({it->val,it});
        }
        if(pq.empty())
        return NULL;
        ListNode* head=pq.top().second;
        pq.pop();
        if(head->next)
        pq.push({head->next->val,head->next});
        ListNode* tail=head;
        while(!pq.empty())
        {
            ListNode* temp = pq.top().second;
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next != NULL)
            {
                pq.push({temp->next->val,temp->next});
            }   
        }
        
        return head;
    }
