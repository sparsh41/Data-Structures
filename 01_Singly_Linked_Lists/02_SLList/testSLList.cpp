#include "SLList.hpp"
#include "SLList.cpp"
#include <string>


int main(){
    SLList<int> list;

    // Populate the list
    for (int i = 5; i >= 1; i--) {
        list.push_front(i);
    }


    for (int i = 5; i <= 8; i++) {
        list.push_back(i);
    }
    
    list.print_list();

    // Delete from front
    list.pop_front();
    list.pop_front();

    list.print_list();

    // Delete from back
    list.pop_back();
    list.pop_back();

    list.print_list();

    // List of Doubles
    SLList<double> list_2;

    list_2.push_back(12.5);
    list_2.push_back(14.0561541);
    list_2.push_back(17.0251);

    list_2.print_list();
    
    // Test pop with empty list
    SLList<int> list_3;
    list_3.pop_back();
    list_3.print_list();
    list_3.push_back(14);
    list_3.print_list();
    list_3.pop_front();
    list_3.print_list();
    list_3.push_back(15);
    list_3.print_list();
    list_3.pop_back();
    list_3.print_list();
    
    // Test assignment operator
    list_3 = list;
    
    list_3.print_list();
    
    // List of Strings
    SLList<std::string> list_4;
    list_4.push_front("abc");
    list_4.push_front("edf");
    list_4.push_front("123");
    list_4.push_front("hello");

    list_4.print_list();

    list_4.insert(2, "insert");

    list_4.print_list();
    
    list_4.erase(2);
    
    list_4.print_list();
    return 0;
}