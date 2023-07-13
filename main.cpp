#include <iostream>
#include <memory>
#include "String_Class.hpp"



int main(int argc, const char * argv[]) {
    
    
    String s1 (10);
    String s2 (10);
    
    String s3(std::move(s1));
    
    String s4 (11);
    s4 = std::move(s2);

    std::cout << "\nExiting the program...\n\n";
    
    return 0;
}
