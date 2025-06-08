class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        
        // Case 1: Deleting the head
        if(x == 1){
            Node* del = head;          // Save the head node to delete
            head = head->next;         // Move head forward
            if(head) head->prev = NULL; // Fix back link if head is not null
            delete del;                // Free memory
            return head;
        }
        
        // Case 2: Deleting at position x (not head)
        Node* temp = head;
        int i = 0;
        while(temp && i < (x-1)){
            temp = temp->next;
            i++;
        }
        
        // Check if node exists
        if(temp == NULL) return head;

        Node* before = temp->prev;
        Node* after = temp->next;

        if(before) before->next = after;
        if(after) after->prev = before;

        delete temp;

        return head;
    }
};