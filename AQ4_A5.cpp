struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;


    int n = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    k = k % n;
    if (k == 0) return head; // No rotation needed

 
    Node* curr = head;
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = nullptr;

  
    tail->next = head;

    return newHead;
}
