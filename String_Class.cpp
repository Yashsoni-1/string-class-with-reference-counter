//
//  String_Class.cpp
//  to_test_play
//
//  Created by Yash soni on 13/07/23.
//

#include "String_Class.hpp"
#include <iostream>


String::String(int size) : size(size)
{
    counter = new int{0};
    data = new char[size];
    ++(*counter);
}

String::~String() noexcept
{
    std::cout << "Destructor: data = " << static_cast<void *>(data)
    << ", counter = " << counter ;
    
    
    if (counter){
        std::cout << " count = " << *counter  << '\n';
        
        --(*counter);
        
        if(*counter == 0)
        {
            std::cout << "Deleting shared memory at "
            << static_cast<void *>(data) << '\n';
            std::cout << "Deleting counter memory at "
            << static_cast<void *>(counter) << '\n';
            delete counter;
            delete [] data;
        }
        
    }else
        std::cout << '\n';
}


String::String(const String& other_string)
{
    std::cout << "In the copy constructor\n";
    size = other_string.size;
    data = other_string.data;
    counter = other_string.counter;
    
    ++(*counter);
}


String& String::operator=(const String& rhs)
{
    std::cout << "Assigned: data = " << static_cast<void *>(data)
    << ", counter = " << counter << " count = " << *counter << '\n';
    
    if (data != rhs.data) {
        --(*counter);
        
        if(*counter == 0)
        {
            std::cout << "Deleting shared memory at "
            << static_cast<void *>(data) << '\n';
            delete counter;
            delete [] data;
        }
        
        size = rhs.size;
        data = rhs.data;
        counter = rhs.counter;
    }
    
    if (&rhs != this)
        ++(*counter);
    
    return *this;
}


String::String(String&& other_string)
{
    std::cout << "Move constructor called\n";
    size = other_string.size;
    data = other_string.data;
    counter = other_string.counter;
    
    other_string.data = nullptr;
    other_string.counter = nullptr;
}



inline void swap(String&s1, String&s2) noexcept
{
    using std::swap;
    swap(s1.size, s2.size);
    swap(s1.data, s2.data);
    swap(s1.counter, s2.counter);
}

String& String::operator=(String&& rhs)
{
    std::cout << "In the move constructor\n";
    String temp(std::move(rhs));
    swap(*this, temp);
    
    return *this;
}
