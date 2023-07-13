//
//  String_Class.hpp
//  to_test_play
//
//  Created by Yash soni on 13/07/23.
//

#ifndef String_Class_hpp
#define String_Class_hpp

#include <stdio.h>


class String
{
private:
    int size;
    char *data;
    int *counter;
public:
    String(int size);
    ~String() noexcept;
    String(const String& other_string);
    String& operator=(const String& rhs);
    String(String&& other_string);
    friend void swap(String&s1, String&s2) noexcept;
    String& operator=(String&& rhs);
};


#endif /* String_Class_hpp */
