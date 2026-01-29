#include "SLLNode.hpp"
#include <iostream>

int main() {
    // Create SSL Nodes
    SLLNode *n1 = new SLLNode(1);
    SLLNode *n2 = new SLLNode(2);
    SLLNode *n3 = new SLLNode(3);
    SLLNode *n4 = new SLLNode(4);
    
    // Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    


    // Create new elements through the first (normally how it is done)
    SLLNode *b = new SLLNode(10);
    b->next = new SLLNode(20);
    b->next->next = new SLLNode(30);

    // Update 20 to 100
    b->next->data = 100;


    
    // Iterate through the nodes
    SLLNode *cur = n1;

    while (cur != nullptr) {
        std::cout << cur->data;
        if (cur->next != nullptr) {
            std::cout << " -> ";
        }
        cur = cur->next; // go to next node
    }

    // Free the memory
    delete n1->next->next->next;   
    delete n1->next->next;   
    delete n1->next;   
    delete n1;   

    return 0;
}