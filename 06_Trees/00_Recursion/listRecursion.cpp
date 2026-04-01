#include <iostream>


class Node {
    public:
        int data;
        Node* next;

        Node(int d = 0, Node* n = nullptr) : data(d), next(n) {};

};

void print_list(Node* head);
void print_reverse(Node* head);
Node* reverse_list(Node* head);
Node* swap_pairs(Node* head);

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    print_list(head);
    print_reverse(head);
    std::cout << std::endl;
    
    print_list(reverse_list(head));

    print_list(swap_pairs(head));
    
    return 0;
}

// Tail iteration - Can be replaced easily with loop
void print_list(Node* head) {
    if (!head) {
        std::cout << "\n";
        return;
    }
    else {
        std::cout << head->data << " ";
        // Recursive case
        print_list(head->next);
    }
}

// Nontail Recursion - Harder to replace with loop
void print_reverse(Node* head) {
    if (!head) {
        return;
    }
    else {
        // Recursive case
        print_reverse(head->next);
        
        std::cout << head->data << " ";
    }
}


Node* reverse_list(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    else {
        Node* p = reverse_list(head->next);

        head->next->next = head;
        head->next = nullptr;
        
        return p;
    }
}


Node* swap_pairs(Node* head) {
    
    if (!head || !head->next) {
        return head;
    }
    
    Node* p = head->next->next;
    head->next->next = head;
    head = head->next;
    head->next->next = swap_pairs(p);
    
    return head;
}