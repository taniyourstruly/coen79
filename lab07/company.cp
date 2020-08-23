// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)


#include <cassert>
#include "company.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);
        this->company_name = company_name;
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);
        node* tail;
        list_copy(src.head_ptr, head_ptr, tail); //copy from src
        head_ptr = src.head_ptr;
        tail_ptr = tail;
        company_name = src.company_name;
        // COMPLETE THE IMPLEMENTATION...
    }

    
    company& company::operator= (const company &src) {
        Debug("Company assignment operator..." << std::endl);
        if(this == &src) //check self assignment
            return *this;
        list_copy(src.get_head(), head_ptr, tail_ptr); //copy from src
        company_name = src.company_name;
        return *this;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    company::~company() {
        list_clear(head_ptr);
    }
    
    
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    
    bool company::insert(const std::string& product_name, const float& price) {
        
        assert(product_name.length() > 0);

        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        
        if (head_ptr == NULL) {
            // COMPLETE THE IMPLEMENTATION...
            node* head = new node(product_name, price); //make new nodea and assign at head
            head_ptr = head;
            tail_ptr = head_ptr;
        }
        else {
            // COMPLETE THE IMPLEMENTATION...
            list_tail_insert(tail_ptr, product_name, price); //insert at end
        }
        
        return true;
    }

    
    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);
        // COMPLETE THE IMPLEMENTATION...
        
        node *product = list_search(head_ptr, product_name); //find product
        if(product == NULL)
            return false;
        product->setName(head_ptr->getName());
        product->setPrice(head_ptr->getPrice());
        list_head_remove(head_ptr); //remove product
        return true;
    }
    
    
}
