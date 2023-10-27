/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * iter = head;
        Node * front = head;
        
        while(iter != NULL){
            front = iter->next;
            
            //for new node
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            
            iter = front;
        }
        
        iter = head;
        
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next; // only go to the orginal nodes not to the deepCopyies
        }
        
        iter = head;
        
        Node *PudoHead = new Node(0);
        Node *copy = PudoHead;
        
        while(iter != NULL){
            front = iter->next->next;
            
            // copy will now point to the head of our DeepCopy
            copy->next = iter->next;
            
            // seprate the orginal with the deepcopies
            iter->next = front;
            
            copy = copy->next;// deepcopy to deepcopy;
            
            iter = front;
        }
        return PudoHead->next;
    }
};