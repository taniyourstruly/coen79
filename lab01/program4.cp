
//
//  program4.cpp
//  
//
//  Created by Tania Pham on 4/9/20.
//

/*
 Precondition: Number remains between 1-20
 Postcondition: Printing steps after the number is found
 */

#include <stdio.h>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main(){
    string str2;
    string str3;
    //creating strings for each possible input
    string y1("Y");
    string y2("y");
    string y3("yes");
    string n1("N");
    string n2("n");
    string n3("no");
    int steps = 0;
    
    std::cout << "Think of a number between 1 and 20. Please press enter when you are ready. \n";
    std::getline (std::cin,str2); //user input
    
    for (int k = 1; k <= 20; k++)
    {
        std::cout << "Is the number " << k << "? Y or N?" << std::endl;
        std::getline (std::cin,str3); //user input
        //std::cout << "Typed: " << str3 << std::endl;
    
        //compare if none of the possible inputs
        if (((str3.compare(y1)) != 0) && ((str3.compare(y2)) != 0) && ((str3.compare(y3)) != 0) && ((str3.compare(n1)) != 0) && ((str3.compare(n2)) != 0) && ((str3.compare(n3)) != 0))
            {
                //std::cout << "y1 is " << y1 << std::endl;
                //std::cout << "testing \n";
                std::cout << "Please type Y or N. \n";
                steps++;
                //std::cout << "counting wrong \n";
                k = k-1; //repeat the same number asked
            }
        if (((str3.compare(n1)) == 0)) //if user typed N, then continue
        {
            steps++;
        }
        if (((str3.compare(n2)) == 0)) //if user typed n, then continue
        {
            steps++;
        }
        if (((str3.compare(n3)) == 0)) //if user typed no, then continue
        {
            steps++;
        }
        else if (((str3.compare(y1)) == 0)) //if user typed Y, then exit
            {
                //std::cout << "Y success \n";
                steps++;
                //std::cout << "counting right \n";
                break;
            }
        else if (((str3.compare(y2)) == 0)) //if user typed y, then exit
        {
            //std::cout << "y success \n";
            steps++;
            //std::cout << "counting right \n";
            break;
        }
        else if (((str3.compare(y3)) == 0)) //if user typed yes, then exit
        {
            //std::cout << "yes success \n";
            steps++;
            //std::cout << "counting right \n";
            break;
        }
    }
    std::cout << "I found the number in " << steps << " steps. " << std::endl;

    return 0;
}
