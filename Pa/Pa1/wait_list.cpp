#include <iostream>
#include "wait_list.h"

using namespace std;

Student_ListNode::Student_ListNode(const int student_id, Student_ListNode *const next)
{
    // TODO
    this->student_id = student_id;
    this->next = next;
}

Wait_List::Wait_List()
{
    // TODO

    this->head = nullptr;
    this->end = nullptr;
}

Wait_List::Wait_List(const Wait_List &wait_list)
{
    // TODO
    if(wait_list.get_head()!= nullptr){
        Student_ListNode* orgHead = wait_list.get_head();

        head = new Student_ListNode(orgHead->student_id,orgHead->next);
        head->next = nullptr;

        Student_ListNode* tempHead = head->next;

        orgHead = orgHead->next;

        while (orgHead!=nullptr)
        {
            tempHead = new Student_ListNode(orgHead->student_id,orgHead->next);
            tempHead->next = nullptr;
            tempHead = tempHead->next;
            orgHead = orgHead->next;
        }
    
    }else{
        head = nullptr;
    }
}

Wait_List::~Wait_List()
{
    // TODO

    Student_ListNode *current = head;
    while (current != 0)
    {
        Student_ListNode *next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

void Wait_List::print_list() const
{
    Student_ListNode *temp = this->head;
    int index = 0;
    while (temp)
    {
        cout << "Waitlist Number: " << index++ << endl;
        cout << temp->student_id << endl;
        temp = temp->next;
    }
}

Student_ListNode *Wait_List::get_head() const
{
    return head;
}

Student_ListNode *Wait_List::get_end() const
{
    return end;
}

void Wait_List::set_head(Student_ListNode *const head)
{
    this->head = head;
}

void Wait_List::set_end(Student_ListNode *const end)
{
    this->end = end;
}