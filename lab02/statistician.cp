// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "statistician.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2
{
    void statistician::next(double r)
    {
        total+=r; //sum of the sequence of numbers
        amount++; //total ammount of numbers
        if(length()==1) //set min and max
        {
            min=r;
            max=r;
        }
        else 
        {
            if(r>max)//check if next number is greater than max
            		max=r;
        	if(r<min)//check if next number is smaller than min
            		min=r;
        }
    }
    void statistician::reset() //reset everything to 0
    {
        amount=0.0;
        total=0.0;
        min = 0;
        max = 0;
    }
    int statistician::length() const
    {
        return amount;
    }
    double statistician::sum() const
    {
        return total;
    }
    double statistician::mean() const
    {
        assert(length()>0);
        return sum()/amount;
    }
    double statistician::minimum() const
    {
        assert(length()>0);
        return min;
    }
    double statistician::maximum() const
    {
        assert(length()>0);
        return max;
    }
    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician s;
        s.amount=s1.amount+s2.amount;
        s.total=s1.total+s2.total;
        s.min=(s1.min<s2.min)?s1.min:s2.min; //compare min of s1 and s2
        s.max=(s1.max>s2.max)?s1.max:s2.max; //compare max of s1 and s2
         
        return s;
            
    }
    statistician operator *(double scale, const statistician& s)
    {
        statistician u;
        u.amount=s.amount; //contains the same numbers that s does
        u.total=(scale*s.total);
        u.min=(scale*s.min);
        u.max=(scale*s.max);
	
        if(scale<0) //check if negative scale and set min and max accordingly
        {
            u.min=(scale*s.max);
            u.max=(scale*s.min);
        }
            return u;
    }
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.length()==s2.length()&&
           s1.mean()==s2.mean()&&
           s1.minimum()==s2.minimum()&&
           s1.maximum()==s2.maximum()&&
           s1.sum()==s2.sum())
            return true;
        else
            return false;
    }
}


