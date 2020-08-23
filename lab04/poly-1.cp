//
//  poly.cpp
//  
//
//  Created by Tania Pham on 4/30/20.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <climits>
#include "poly.h"

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4
{
    polynomial::polynomial(double c, unsigned int exponent)
    {
        assert(exponent <= MAXIMUM_DEGREE);
        int i;
        for(i = 0; i <= polynomial::MAXIMUM_DEGREE; i++)
            array[i] = 0.0; //set value to 0
        array[exponent] = c;
        currentDegree = exponent;
    }
    void polynomial::update_current_degree()
    {
        //The current degree is set to the highest exponent
        //      with a non-zero coeficient.
        currentDegree = 0;
        int i;
        for (i = polynomial::MAXIMUM_DEGREE; i > 0; i--)
        {
            if (array[i] != 0.0)
            {
                currentDegree = i;
                break;
            }
        }
    }

    //MODIFICATION MEMBER FUNCTIONS
    void polynomial::assign_coef(double coefficient, unsigned int exponent)
    {
        assert(exponent<=MAXIMUM_DEGREE);
        //sets the coefficient for the specific exponents
        array[exponent] = coefficient;
        update_current_degree();
    }
    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
        assert(exponent<=MAXIMUM_DEGREE);
        //adds the given amount to the coefficient of the specified exponent
        array[exponent] += amount;
        update_current_degree();
    }
    void polynomial::clear()
    {
        //all coefficients are set to 0
        int i;
        for(i = 0; i < polynomial::MAXIMUM_DEGREE+1; i++)
            array[i] = 0.0;
        update_current_degree();
    }
    
    polynomial polynomial::antiderivative() const
    {
        assert(degree()<MAXIMUM_DEGREE);
        polynomial tmp;
        int i;
        for (i = 0; i <= currentDegree; i++)
        {
            tmp.assign_coef(coefficient(i) * pow(i + 1, -1), i + 1);
        }
        return tmp;
    }
    double polynomial::coefficient(unsigned int exponent) const
    {
        //returns coefficient at specified exponent of this polynomial
        return array[exponent];
    }
    double polynomial::definite_integral(double x0, double x1) const
    {
        //Returns the value of the definite integral computed from x0 to x1
        return (this -> antiderivative()(x1) - this -> antiderivative()(x0));
    }
    unsigned int polynomial::degree() const
    {
        return currentDegree;
    }
    polynomial polynomial::derivative() const
    {
        assert(degree() < MAXIMUM_DEGREE);
        polynomial tmp;
        int i;
        for (i = 0;i <= currentDegree; i++){
            tmp.array[i-1]=(array[i]*i); //everything shifts left and coefficients are multiplied by their old exponent
        }
        tmp.update_current_degree();
        return tmp;
    }
    double polynomial::eval(double x) const
    {
        //POSTCONDITION: The return value is the value of this polynomial with the
        //     given value for the variable x.
        int i;
        double sum = 0.0;
        for (i = 0; i < MAXIMUM_DEGREE +1 ; i++)
        {
            sum += array[i] * pow(x, i);
        }
        return sum;
    }
    bool polynomial::is_zero() const
    {
        if (currentDegree == 0 && array[0] == 0)
            return true;
        return false;
        //return (current_degree == 0 && array[0] == 0);
    }
    unsigned int polynomial::next_term(unsigned int e) const
    {
        //POSTCONDITION: The return value is the next exponent n which is LARGER
        //     than e such that coefficient(n) != 0.
        //     If there is no such term, then the return value is zero.
        int i;
        for(i = e; i < polynomial::MAXIMUM_DEGREE; i++)
        {
            if(array[i+1] != 0) //if next element is not 0
                return i+1;
        }
        return 0;
    }
    unsigned int polynomial::previous_term(unsigned int e) const
    {
        int i;
        for(i = e; i > 0; i--)
        {
            if(array[i-1] != 0) //if previous element is not 0
                return i-1;
        }
        return UINT_MAX;
    }
    double polynomial::operator( ) (double x) const
    {
        return eval(x);
    }
    polynomial operator +(const polynomial& p1, const polynomial& p2)
    {
        //add p1 and p2 together
        polynomial tmp;
        int i;
        for (i = 0; i < polynomial::MAXIMUM_DEGREE + 1; i++)
            tmp.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
        return tmp;
    }
    polynomial operator -(const polynomial& p1, const polynomial& p2)
    {
        //subtract p2 from p1
        polynomial tmp = p1;
        int i;
        for (i = 0; i < polynomial::MAXIMUM_DEGREE + 1; i++)
            tmp.add_to_coef(-1 * p2.coefficient(i), i);
        return tmp;
    }
    polynomial operator *(const polynomial& p1, const polynomial& p2)
    {
        //multiply p1 and p2
        assert((p1.degree() + p2.degree()) <= polynomial::MAXIMUM_DEGREE);
        polynomial tmp;
        double temp[polynomial::MAXIMUM_DEGREE+1] = {0};
        int i,j,k;
        for (i = 0; i <= p1.degree(); i++)
        {
            for (j = 0; j <= p2.degree(); j++)
                temp[i+j] += (p1.coefficient(i) * p2.coefficient(j));
        }
        for (k = 0; k <= polynomial::MAXIMUM_DEGREE; k++)
            tmp.assign_coef(temp[k],k);
        return tmp;
    }
    ostream& operator << (ostream& out, const polynomial& p)
    {
        //print polynomials
        int i;
        for (i = p.degree(); i >= 0; i--)
        {
            if(p.coefficient(i) != 0)
            {
                if (p.coefficient(i) < 0)
                    out << "-";
                else if (i != p.degree() && i != 1)
                    out << "+";
                if(i > 1)
                    out << p.coefficient(i) << "x^" << i << " ";
                else if (i == 1)
                    out << p.coefficient(i) << "x ";
                else if (i == 0)
                    out << p.coefficient(i);
            }
                
        }
        return out;

    }
}
