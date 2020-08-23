//
//  program1.cpp
//  
//
//  Created by Tania Pham on 4/13/20.
//

/*
 Precondition: string is valid and has alphanumeric and non-alphanumeric characters
 Postcondition: Print how many alphanumeric and non-alphanumeric characters there are
 */

#include <stdio.h>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main(){

    //program 1: count the input characters
    string str;
    int acount=0;
    int ncount=0;
    
    std::cout << "Please type something: \n";
    std::getline (std::cin,str); //www.cplusplus.com/reference/string/string/getline/
    
    for (int i = 0; i<str.length();i++)
    {
    
        if(isalnum(str[i]) != 0) //if a character is alphanumeric
            acount++; //add to alphanumeric count
        else if(str[i] != ' ') //if a space
            ncount++; //add to non-alphanumeric count
    }
    std::cout << str << " has " << acount << " alphanumeric characters." << std::endl;
    std::cout << str << " has " << ncount << " non-alphanumeric characters." << std::endl;
     
    return 0;
}
