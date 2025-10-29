struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};


Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prevGroupEnd = dummy;

    while (true) {
        Node* kth = prevGroupEnd;
        
       
        for (int i = 0; i < k && kth; ++i) {
            kth = kth->next;
        }

        if (!kth) break; 

        Node* groupStart = prevGroupEnd->next;
        Node* nextGroupStart = kth->next;

     
        Node* prev = nextGroupStart;
        Node* curr = groupStart;

        while (curr != nextGroupStart) {
            Node* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

       
        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;
    }

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}
