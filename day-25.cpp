//Day-25
//Problem 1 - Delete Node in a Linked List
//code:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next != NULL){
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = NULL;
        delete(temp);
    }
};

//Problem 2 - Linked List Insertion At End
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newnode = new Node(x);
        if(head == nullptr){
            return newnode;
        }
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newnode;
        return head;
    }
};
