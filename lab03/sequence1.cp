//
//  sequence1.cpp
//  
//
//  Created by Tania Pham on 4/23/20.
//

#include <stdio.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3
{
    void sequence::start()
    {
        iterator=0;
    }
    void sequence::end()
    {
        iterator = total-1;
    }
    void sequence::last()
    {
        iterator = sequence::CAPACITY - 1;
    }
    void sequence::advance() //go to the next item in the list
    {
        assert(is_item());
        if(iterator < sequence::CAPACITY - 1)
            {
                iterator++;
                return;
            }
    }
    void sequence::retreat()
    {
        if(iterator>0)
        {
            iterator--;
        }
        return;
    }
    void sequence::insert(const value_type& entry)
    {
        assert(total < CAPACITY);
        if(total==0) //no items in the array
        {
            array[0]=entry;
            iterator = 0;
            total++;
        }
        else //add to array and shift everything down
        {
            for(size_type i = total; i > iterator; i--)
            {
                array[i]=array[i-1];
            }
            array[iterator]=entry;
            total++;
        }
    }
    void sequence::attach(const value_type& entry)
    {
        assert(total < CAPACITY);
        if(total==0) //no items in the array
        {
            array[0]=entry;
            iterator = 0;
            total++;
        }
        else if(!is_item()) //not at current item in the array
        {
            array[total]=entry;
            iterator = total;
            total++;
        }
        else //add after current item in array and shift
        {
            for(size_type i = total; i > iterator + 1; i--)
                array[i]=array[i-1];
            array[iterator+1] = entry;
            iterator++;
            total++;
        }
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(size_type i = iterator;i < total-1; i++)
            array[i]=array[i+1];
        total--;
    }
    void sequence::insert_front(const value_type& entry)
    {
        assert(total < CAPACITY);
        if(total==0)
        {
            array[0]=entry;
            iterator = 0;
            total++;
        }
        else //add in first element
        {
            for(size_type i = total; i > iterator; i--)
            {
                array[i]=array[i-1];
            }
            array[iterator]=entry;
            total++;
            iterator = 0;
        }
        
    }
    void sequence::attach_back(const value_type& entry) //attach at the end of the array
    {
        assert(size()<CAPACITY);
        array[total++]=entry;
        iterator = total;
    }
    void sequence::remove_front()
    {
        assert(is_item());
        sequence::size_type i;
        for (i = iterator; i < total; i++)
        {
            array[i] = array[i+1];
        }
        total--;
        iterator = 0;
    }
    void sequence::operator +=(const sequence& rhs) //adds item from rhs to array
    {
        assert((rhs.size()+total) < sequence::CAPACITY);
        //end();
        for(size_type i = 0; i < rhs.size(); i++)
        {
            //attach(rhs[i]);
            array[total++]=rhs.array[i];
        }
    }

    sequence::size_type sequence::size() const
    {
        return total;
    }
    bool sequence::is_item() const //if there is a current item
    {
        if (iterator < total)
            return true;
        else
            return false;
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return array[iterator];
    }
    sequence::value_type sequence::operator[](int index) const
    {
        assert(index<total);
        return array[index];
    }
    double sequence::mean() const
    {
        double counter = 0.0;
        for (size_type i = 0; i < total; i++)
        {
            counter+=array[i];
        }
        return (counter/total);
    }
    double sequence::standardDeviation() const
    {
        double stdev = 0;
        for(size_type i = 0; i < total; ++i)
            stdev += pow(array[i] - mean(), 2); //https://www.programiz.com/cpp-programming/examples/standard-deviation

        return sqrt(stdev / total);
    }

    sequence operator +(const sequence& lhs, const sequence& rhs) //add lhs and rhs to new sequence
    {
        assert((lhs.size() + rhs.size()) < sequence::CAPACITY);
        sequence newSequence;
        newSequence += lhs;
        newSequence += rhs;
        newSequence.start();
        //sequence::size_type i,j;
        return newSequence;
        /*for (i = 0; i < lhs.size(); i++)
            sequence[i] = lhs[i];
        for (j = 0; j < rhs.size(); j++)
            sequence[j] += rhs[j];*/
        
    }
    sequence::value_type summation(const sequence &s)
    {
        double sum;
        sequence::size_type i;
        for (i = 0; i < s.size(); i++)
        {
            sum+=s[i];
        }
        return sum;
    }
}
