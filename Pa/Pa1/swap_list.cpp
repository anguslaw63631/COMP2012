#include <iostream>
#include <cstring>
#include "swap_list.h"

using namespace std;

Swap::Swap(const char *const original_course_name, const char *const target_course_name, Swap *const next)
{
    // TODO

    this->original_course_name = new char[strlen(original_course_name) + 1];
    strcpy(this->original_course_name, original_course_name);

    this->target_course_name = new char[strlen(target_course_name) + 1];
    strcpy(this->target_course_name, target_course_name);

    this->next = next;
}

Swap::~Swap()
{
    // TODO

    delete[] original_course_name;
    delete[] target_course_name;
    

}

Swap_List::Swap_List()
{
    // TODO

    this->head = nullptr;
}

Swap_List::Swap_List(const Swap_List &swap_list)
{
    // TODO
    if(swap_list.get_head()!= nullptr){
        Swap* orgHead = swap_list.get_head();

        head = new Swap(orgHead->original_course_name,orgHead->target_course_name,orgHead->next);
        head->next = nullptr;

        Swap* tempHead = head->next;

        orgHead = orgHead->next;

        while (orgHead!=nullptr)
        {
            tempHead = new Swap(orgHead->original_course_name,orgHead->target_course_name,orgHead->next);
            tempHead->next = nullptr;
            tempHead = tempHead->next;
            orgHead = orgHead->next;
        }
    
    }else{
        head = nullptr;
    }
}
    

Swap_List::~Swap_List()
{
    // TODO

    Swap *current = head;
    while (current != nullptr)
    {
        Swap *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void Swap_List::print_list() const
{
    Swap *temp = this->head;
    int index = 0;
    while (temp)
    {
        cout << "Swap: " << index++ << endl;
        cout << "Original Course: " << temp->original_course_name << endl;
        cout << "Target Course: " << temp->target_course_name << endl;
        temp = temp->next;
    }
}

Swap *Swap_List::get_head() const
{
    return head;
}

void Swap_List::set_head(Swap *const head)
{
    this->head = head;
}