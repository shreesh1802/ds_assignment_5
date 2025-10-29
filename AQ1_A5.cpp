struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;

    Node* a = headA;
    Node* b = headB;

    while (a != b) {
       
        a = (a == nullptr) ? headB : a->next;

        
        b = (b == nullptr) ? headA : b->next;
    }

    
    return a;
}
