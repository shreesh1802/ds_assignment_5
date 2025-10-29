struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

Node* addPolynomials(Node* poly1, Node* poly2) {
    if (!poly1) return poly2;
    if (!poly2) return poly1;

    Node* dummy = new Node(0, 0);
    Node* temp = dummy;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)  // ignore zero coefficient terms
                temp->next = new Node(sum, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            temp->next = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            temp->next = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        if (temp->next) temp = temp->next;
    }

  
    while (poly1) {
        temp->next = new Node(poly1->coeff, poly1->pow);
        temp = temp->next;
        poly1 = poly1->next;
    }

    while (poly2) {
        temp->next = new Node(poly2->coeff, poly2->pow);
        temp = temp->next;
        poly2 = poly2->next;
    }

    return dummy->next;
}
