//
//  program3.cpp
//  
//
//  Created by Tania Pham on 4/9/20.
//

/*
 Precondition: Text file exists to be able to be open and read
 Postcondition: program prints out all the words with length greater than 10 in uppercase
 */

#include <stdio.h>
#include <iostream>
#include <locale>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{   //makes sure file can be opened
    if(argc != 2)
    {
        cout<<"Incorrect number of files. \n";
        return 0;
    }
    else
    {
        int i,j,k;
        string str1, str2;
        int count;
        ifstream in_file(argv[1]); //opens the file
        if(!in_file)
        {
            cout<<"File could not be opened. \n";
            return 0;
        }
        while(in_file >> str1) //www.geeksforgeeks.org/cpp-program-read-file-word-word/
        {
            if(str1.length() >= 10) //checks if word is greater than 10 in length
            {
                for(i = 0, j = 0; i < str1.length(); i++)
                {
                    if (isalpha(str1[i])) //checks if word is in the alphabet
                    {
                        str2[j] = toupper(str1[i]); //convert word to uppercase
                        j++;
                    }
                }
                if(j >= 10) //rechecks if word in uppercase is greater than 10 in length
                {
                    for (k = 0; k < j; k++) //go through each character and print
                        cout << str2[k];
                    cout << endl;
                }
            
            }
        }
        in_file.close(); //closes file
    }
    return 0;
}

