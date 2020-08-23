//
//  keyed_bag.cpp
//  
//
//  Created by Tania Pham on 4/30/20.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <string>
#include "keyed_bag.h"
using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4
{
    void keyed_bag::erase()
    {
        total = 0;
        size_type i;
        for (i = 0; i < CAPACITY; i++)
        {
            keys[i] = ""; //set all keys to empty
            data[i] = 0; //set all data to 0
        }
    }
    bool keyed_bag::erase(const key_type& key)
    {
        if(has_key(key))
        {
            size_type i,j;
            for(i = 0; i < total; i++) //go through the entire array
            {
                if(key==keys[i]) //if the key given is in the keyed bag
                {
                    for(j = i; j < total-1; j++) //find the key that matches
                    {
                        keys[j] = keys[j+1]; //shift keys
                        data[j] = data[j+1]; //shift data
                    }
                    total--;
                }
            }
            return true;
        }
        return false;
    }
    void keyed_bag::insert(const value_type& entry, const key_type& key)
    {
        assert(size()<CAPACITY);
        assert(!has_key(key)); //key is not already in bag
        keys[total] = key; //insert key into keys array at the end
        data[total] = entry; //insert entry into datas array at the end
        total++;
    }
    void keyed_bag::operator +=(const keyed_bag& addend)
    {
        assert(size()+addend.size()<=CAPACITY);
        assert(!hasDuplicateKey(addend));
        size_type k;
        for(k = 0; k < addend.size(); k++) //add each item and key into keys
        {
            keys[total]=addend.keys[k];
            data[total]=addend.data[k];
            total++;
        }
    }

    //CONSTANT MEMBER FUNCTION
    bool keyed_bag::has_key(const key_type& key) const
    {
        size_type i;
        for (i = 0; i < size(); i++)
        {
            if (keys[i]==key) //check if equal
                return true;
        }
        return false;
    }
    keyed_bag::value_type keyed_bag::get(const key_type& key) const
    {
        assert(has_key(key));
        size_type i;
        for (i = 0; i < size(); i++)
        {
            if(keys[i]==key)
            {
                return data[i]; //return value at key
            }
        }
    }
    keyed_bag::size_type keyed_bag::size() const
    {
        return total;
    }
    keyed_bag::size_type keyed_bag::count(const value_type& target) const
    {
        size_type i;
        size_type c = 0;
        for (i = 0; i < size(); i++)
        {
            if (target == data[i]) //if value is in the bag, add to counter
                c++;
        }
        return c;
    }
    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const
    {
        size_type i,j,k;
        for (i = 0; i < otherBag.size(); i++)
        {
            for (j = 0; j < size(); j++)
            {
                if (otherBag.keys[i] == keys[j]) //check if they share any keys
                    return true;
            }
        }
        return false;
    }
    //NONMEMBER FUNCTIONS
    keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
    {
        assert((b1.size() + b2.size()) < keyed_bag::CAPACITY);
        keyed_bag newBag; //new bag for union
        keyed_bag::size_type i,j;
        for (i = 0; i < b1.size(); i++)
        {
            for (j = 0; j < b2.size(); j++)
            {
                if (b1.hasDuplicateKey(b2)) //check if they do not share any keys
                    return newBag;
            }
        }
        newBag += b1;
        newBag += b2;
        return newBag;
    }
    
}
