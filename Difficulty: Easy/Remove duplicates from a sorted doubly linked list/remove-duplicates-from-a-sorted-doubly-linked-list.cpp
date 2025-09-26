class Solution {
public:

    Node *removeDuplicates(Node *head) {
        if (!head) return NULL;
        
        Node* temp = head;
        int ele = temp->data - 1; // just smaller than first element
        
        while (temp) {
            if (ele != temp->data) {
                ele = temp->data;
                temp = temp->next;
            } else {
                Node* before = temp->prev;
                Node* after = temp->next;

                if (before) before->next = after;
                if (after) after->prev = before;

                // update head if temp is head
                if (temp == head) head = after;

                Node* toDelete = temp;
                temp = after; // move temp AFTER deletion
                delete toDelete; // optional
            }
        }
        return head;
    }
};
