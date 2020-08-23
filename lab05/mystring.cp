//
//  mystring.cpp
//  
//
//  Created by Tania Pham on 5/7/20.
//

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <cstring>      // String Library
#include <cctype>
#include "mystring.h"   // Or use the Standard Library <string>

using std::cin;
using std::cout;
using std::endl;
using namespace coen79_lab5;

namespace coen79_lab5
{
    string::string(const char str[])
    {
        //     Precondition: str is an ordinary null-terminated string.
        //     Postcondition: The string contains the sequence of chars from str.
        current_length = strlen(str);
        allocated = current_length+1;
        characters = new char[allocated];
        strncpy(characters,str,allocated);
    }
    string::string(char c)
    {
        //     Postcondition: The string contains c and then the null character.
        current_length = 1; //character is 1 in length
        allocated = 2;
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }
    string::string(const string& source)
    {
        //     Postcondition: The string becomes a copy of the source string.
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[current_length];
        strncpy(characters,source.characters,current_length);
    }
    string::~string()
    {
        delete [] characters;
        current_length = 0;
        allocated = 0;
    }

    //MODIFICATION MEMBER FUNCTIONS for the string class:
    void string::operator +=(const string& addend)
    //     Postcondition: addend has been catenated to the end of the string.
    {
        //length = addend.current_length;
        current_length += addend.current_length;
        allocated += current_length+1;
        reserve(allocated);
        strncat(characters, addend.characters, addend.current_length);
        return;
    }
    void string::operator +=(const char addend[ ])
    //     Precondition: addend is an ordinary null-terminated string.
    //     Postcondition: addend has been catenated to the end of the string.
    {
        current_length += strlen(addend);
        allocated = current_length+1;
        reserve(allocated);
        strncat(characters, addend, strlen(addend));
        return;
    }
    void string::operator +=(char addend)
    //     Postcondition: The single character addend has been catenated to the
    //     end of the string.
    {
        current_length += 1;
        allocated = current_length + 1;
        reserve(allocated);
        characters[current_length-1] = addend;
        //strncat(characters,addend,allocated);
    }
    void string::reserve(size_t n)
    //     Postcondition: All functions will now work efficiently (without
    //     allocating new memory) until n characters are in the string.
    //
    {
        char* temp = new char[n];
        if (characters != NULL)
        {
            strncpy (temp, characters, current_length);
            delete [] characters;
        }
        characters = temp; //put temp back into characters
        return;
    }
    string& string::operator =(const string& source)
    {
        //set string into something else
        this->dlt(0,current_length); //to return string&
        current_length = source.current_length;
        allocated = source.allocated;
        reserve(allocated);
        strncpy(characters, source.characters, source.current_length);
        return *this;
    }
    void string::insert(const string& source, unsigned int position)
    //     Precondtion: position <= length()
    //     Postcondition: The source string is inserted into this string before
    //     the character at the given index.
    {
        assert(position <= length());
        int i, j, s;
        string temp = source;
        //reserve(allocated);
        for(i = position; i < current_length; i++) //add characters from position into temp
        {
            temp += characters[i];
        }
        current_length += source.length();
        for(j = 0; j < temp.length(); position++, j++) //add temp back into characters
        {
            characters[position] = temp[j];
        }
        return;
    }
    void string::dlt(unsigned int position, unsigned int num)
    //     Precondition: (position + num) <= length( ).
    //     Postcondition: num characters are deleted from the sequence, starting
    //     at index position.
    {
        assert((position + num) <= length( ));
        int i;
        for (i = position; i < current_length; i++)
        {
            characters[i] = characters[num + i]; //shift characters to the left
        }
        current_length-=num;
        return;
    }
    void string::replace(char c, unsigned int position)
    //     Precondition: position < length()
    //     Postcondtion: the character at the given position in the string is
    //     replaced with c.
    {
        assert(position < length());
        characters[position] = c;
        return;
    }
    void string::replace(const string& source, unsigned int position)
    //     Precondition: (position + source.length()) <= length()
    //     Postcondtion: the characters in this string starting at position are
    //     replaced with those in the source srting.
    {
        assert((position + source.length()) <= length());
        int i, j = 0;
        for (i = position; i < (position + source.length()); i++, j++)
        {
            characters[i] = source[j];
        }
        return;
    }

    // CONSTANT MEMBER FUNCTIONS for the string class:
    char string::operator [ ](size_t position) const
    //     Precondition: position < length( ).
    //     Postcondition: The value returned is the character at the specified
    //     position of the string. A string's positions start from 0 at the start
    //     of the sequence and go up to length( )-1 at the right end.
    {
            assert(position < length());
            return characters[position];
    }

    int string::search(char c) const
    //     Postcondition: The location of the first occurence of the character c
    //     within this string is returned. If the string does not contain c, -1 is
    //     is returned.
    {
            int i;
            for (i = 0; i < current_length; i++)
            {
                if (characters[i] == c) //if string contains c, returns index
                    return i;
            }
            return -1;
    }
    int string::search(const string& substring) const
    //     Postcondition: Returns the index of the start of the first instance of
    //     the given substring inside of this string. If the substring is not found,
    //     this function returns -1.
    {
            //HELP
            int i;
            int index = 0;
            int j = 0;
            for (i = 0; i < current_length; i++) //go through characters
            {
                   if (substring[0] == characters[i]) //check first letter of substring
                   {
                        for (j = 0; j < substring.length(); j++) //check the rest of substring
                        {
                                if(characters[i+j] == substring[j])
                                    return i;
                        }
                   }
            }
            return -1;
    }
    unsigned int string::count(char c) const
    //     Postcondition: The count of the occurence of the character c within this
    //     string is returned.
    {
            int i;
            unsigned int count = 0;
            for (i = 0; i < length(); i++)
            {
                if (c == characters[i])
                    count++;
            }
            return count;
    }

    //FRIEND FUNCTIONS
    std::ostream& operator <<(std::ostream& outs, const string& source)
    {
    //     Postcondition: The sequence of characters in source has been written
    //     to outs. The return value is the ostream outs.
            outs << source.characters;
            return outs;
    }
    bool operator ==(const string& s1, const string& s2)
    {
            /*if (s1 == s2)
                   return true;
            else
                   return false;*/
            return (strcmp(s1.characters,s2.characters) == 0);
    }
            
    bool operator !=(const string& s1, const string& s2)
    {
            return (strcmp(s1.characters,s2.characters) != 0);
    }
                
    bool operator >(const string& s1, const string& s2)
    {
            return (strcmp(s1.characters,s2.characters) > 0);
    }
                
    bool operator <(const string& s1, const string& s2)
    {
            return (strcmp(s1.characters,s2.characters) < 0);
    }
                
    bool operator >=(const string& s1, const string& s2)
    {
            return (strcmp(s1.characters,s2.characters) >= 0);
    }
                
    bool operator <=(const string& s1, const string& s2)
    {
            return (strcmp(s1.characters,s2.characters) <= 0);
    }


    // NON-MEMBER FUNCTIONS for the string class:
    string operator +(const string& s1, const string& s2)
    //     Postcondition: The string returned is the catenation of s1 and s2.
    {
            string temp;
            temp.reserve(s1.length() + s2.length() + 1);
            temp += s1;
            temp += s2;
            return temp;
    }
    string operator +(const string& s1, const char addend[ ])
    {
            string temp;
            temp.reserve(s1.length() + strlen(addend) + 1);
            temp += s1;
            temp += addend;
            return temp;
    }
    std::istream& operator >>(std::istream& ins, string& target)
    //     Postcondition: A string has been read from the istream ins, and the
    //     istream ins is then returned by the function. The reading operation
    //     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
    //     Then the string is read up to the next white space or the end of the
    //     file. The white space character that terminates the string has not
    //     been read.
    {
            //HELP
        while (ins && isspace(ins.peek( )))
            ins.ignore( );
        //set the string to an empty string
        //read the input characters, adding each character to the end of the string
        char* temp = new char[1000];
        ins >> temp;
        target = string(temp);
        return ins;
    }
}
