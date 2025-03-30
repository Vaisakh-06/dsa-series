//Day-26
//Problem 1 - Delete in a Doubly Linked List
//code:
class Solution {
  public:
   
    Node* deleteNode(Node* head, int x) {
       if (head == NULL) return head; 

        Node* temp = head;
 
        if (x == 1) {
            head = head->next;
            if (head) head->prev = NULL; 
            delete temp;
            return head;
        }

       
        for (int i = 1; temp != NULL && i < x; i++) {
            temp = temp->next;
        }

      
        if (temp == NULL) return head;

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;

        delete temp; 
        return head;
    }
};

//Problem 2 - Reverse a Doubly Linked List
//code:
class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == NULL || head->next == NULL) return head;

        DLLNode* curr = head;
        DLLNode* temp = NULL;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        return temp->prev;
    }
};
