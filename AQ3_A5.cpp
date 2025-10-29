struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;
    bool hasLoop = false;

  
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasLoop = true;
            break;
        }
    }

    if (!hasLoop) return;

    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* loopStart = slow;

    
    Node* ptr = loopStart;
    while (ptr->next != loopStart) {
        ptr = ptr->next;
    }
    ptr->next = nullptr;
}
