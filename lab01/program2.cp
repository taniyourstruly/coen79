//
//  program2.cpp
//
//
//  Created by Tania Pham on 4/9/20.
//

/*
Pre-condition: string of 10 digits (0 to 9) with no spaces
Post-condition: prints string of numbers in reverse
*/

#include <stdio.h>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main(){


	//program 2: string of numbers and its reverse
	string str1;

	std::cout << "Please type a string of 10 digits (0 to 9) with no space \n";
	std::getline (std::cin,str1); //www.cplusplus.com/reference/string/string/getline/

	cout << str1 << "            ";

	if(str1.length()<10 || str1.length()>10) //check if there are 10 digits 
	{
		cout << "Needs to be 10 digits.\n";
		return 0;
	}	
	for(int i=0; i<10; i++)
	{
		if(str1[i]==' ') //check if there are spaces
		{
			cout<< "Needs to be all digits. \n";
			return 0;
		}
		if(isalpha(str1[i])) //check if there are alphabetical characters
		{
			cout<< "Needs to be all digits. \n";
			return 0;
		}
	}
	for (int j = str1.length()-1; j >= 0; j--) //goes backwards to print
	{
		cout << str1[j];
	}
    	cout<<endl;
	return 0;
}


