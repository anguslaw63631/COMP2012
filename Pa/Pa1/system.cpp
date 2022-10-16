#include <iostream>
#include <cstring>
#include "system.h"
#include "student.h"
#include "course.h"
#include "course_database.h"
#include "student_database.h"
#include "wait_list.h"
#include "swap_list.h"

using namespace std;

/*
The following 3 helper functions may be useful in add/swap/drop function. You may implement them if you find them useful.
If not, you can remove these 3 helper functions as we will NOT set any test case testing these helper functions.
*/

// Helper function: add the Student to the end of the waitlist of the Course.
void join_waitlist(const int student_id, Course* course) {
    // TODO
    if(course->get_wait_list()->get_head() != nullptr){
       
       // cout<<"std id"<<student_id<<endl;
        Student_ListNode* StuN = course->get_wait_list()->get_head();
        Student_ListNode* newStuN = new Student_ListNode(student_id,nullptr);
        while (StuN->next != nullptr)
        {
            //cout<<"std id inside:"<<StuN->student_id << "2"<<newStuN->student_id <<endl;
            StuN = StuN->next;
        }
        StuN->next = newStuN;
        course->get_wait_list()->set_end(newStuN);
        
        
        
    }else{
        Student_ListNode* stuN= new Student_ListNode(student_id,nullptr);
        course->get_wait_list()->set_head(stuN);
        course->get_wait_list()->set_end(stuN);
    }
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student* const student, const char* const course_name) {
    // TODO

    for(int i=0;i<student->get_num_enrolled_course();i++){
        
        if(strcmp(student->get_enrolled_courses()[i],course_name) == 0)
            return i;
    }
    return -1;
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course* const course) {
    // TODO

    for(int i=0;i<course->get_size();i++){
        if(course->get_students_enrolled()[i] == student_id)
            return i;
    }
    return -1;
}


System::System(const int max_num_course, const int max_num_student) {
    course_database = new Course_Database(max_num_course);
    student_database = new Student_Database(max_num_student);
}

System::System(const System& system) {
    this->course_database = new Course_Database(*system.course_database);
    this->student_database = new Student_Database(*system.student_database);
}

System::~System() {
    delete course_database;
    delete student_database;
}

void System::admit(const char* const name, const int student_id, const double gpa) {
    this->student_database->create_entry(name, student_id, gpa);
}

bool System::apply_overload(const int student_id, const int request_credit) {
    // TODO

    if(request_credit >30){
        return false;
    }

    if(request_credit >= 24){
        if(get_student_database()->get_student_by_id(student_id)->get_gpa() < 3.7){
            return false;
        }
    }

    if(request_credit >= 18){
        if(get_student_database()->get_student_by_id(student_id)->get_gpa() < 3.3){
            return false;
        }
    }
    get_student_database()->get_student_by_id(student_id)->set_max_credit(request_credit);
    return true;
}

bool System::add(const int student_id, const char* const course_name) {
    // TODO
    Student* stu = get_student_database()->get_student_by_id(student_id);

    int curr_cr = stu->get_curr_credit();
    int max_cr = stu->get_max_credit();
    int enrolled_num = stu->get_num_enrolled_course();
    int pend_cr = stu->get_pending_credit();

    Course* orgC = get_course_database()->get_course_by_name(course_name);

    int course_cr = orgC->get_num_credit();
    int* enrolled_students = orgC->get_students_enrolled();
    int num_enrolled_course = orgC->get_size();

    if(curr_cr+pend_cr+course_cr > max_cr){
        return false;
    }
    
    if(num_enrolled_course == orgC->get_capacity()){
        join_waitlist(stu->get_student_id(),orgC);
        stu->set_pending_credit(pend_cr+course_cr);
    }else{

    stu->get_enrolled_courses()[enrolled_num] = new char[strlen(course_name)+1];
    strcpy(stu->get_enrolled_courses()[enrolled_num], orgC->get_name());
  
    stu->set_curr_credit(curr_cr+course_cr);
    enrolled_num++;
    stu->set_num_enrolled_course(enrolled_num);

    enrolled_students[num_enrolled_course] = stu->get_student_id();
    num_enrolled_course++;
    orgC->set_students_enrolled(enrolled_students);
    orgC->set_size(num_enrolled_course);
    }
    
    
    return true;
}

bool System::swap(const int student_id, const char* const original_course_name, const char* const target_course_name) {
    // TODO

    Student* stu = get_student_database()->get_student_by_id(student_id);
    Course* orgC = get_course_database()->get_course_by_name(original_course_name);
    Course* tarC = get_course_database()->get_course_by_name(target_course_name);

    int curr_cr = stu->get_curr_credit();
    int max_cr = stu->get_max_credit();
    int pend_cr = stu->get_pending_credit();

    int orgC_cr = orgC->get_num_credit();
    int tarC_cr = tarC->get_num_credit();

    if(curr_cr+pend_cr+tarC_cr-orgC_cr > max_cr){
        return false;
    }

    if(tarC->get_size()<tarC->get_capacity()){
        // cout<<student_id<<"|||"<<original_course_name<<endl;
       
        add(student_id,target_course_name);
        
        drop(student_id,original_course_name);
    }else{
        // cout<<student_id<<"|||"<<original_course_name<<endl;

        //cout<<"te2222st:" <<orgC->get_name()<<endl;

        join_waitlist(student_id,tarC);
        stu->set_pending_credit(pend_cr+tarC_cr-orgC_cr);
        if(stu->get_swap_list()->get_head() != nullptr){
        Swap* StuN = stu->get_swap_list()->get_head();
        Swap* newStuN = new Swap(original_course_name,target_course_name,nullptr);
        while (StuN->next != nullptr)
        {
            StuN = StuN->next;
        }
        StuN->next = newStuN;
        }
        else{
        stu->get_swap_list()->set_head(new Swap(original_course_name,target_course_name,nullptr));
        }
    }
    return true;
}

void System::drop(const int student_id, const char* const course_name) {
    // TODO

    Student* stu = get_student_database()->get_student_by_id(student_id);
    Course* orgC = get_course_database()->get_course_by_name(course_name);

    int curr_cr = stu->get_curr_credit();

    int orgC_cr = orgC->get_num_credit();

    stu->set_curr_credit(curr_cr-orgC_cr);
    if(stu->get_enrolled_courses()[search_course_index(stu,course_name)] == stu->get_enrolled_courses()[stu->get_num_enrolled_course()-1]){
        //cout<<"test1"<<endl;
        delete[] stu->get_enrolled_courses()[search_course_index(stu,course_name)];
    }else{
        //cout<<"test2"<<endl;
        stu->get_enrolled_courses()[search_course_index(stu,course_name)] = stu->get_enrolled_courses()[stu->get_num_enrolled_course()-1];
        //delete[] stu->get_enrolled_courses()[stu->get_num_enrolled_course()-1];
    }
    
    stu->set_num_enrolled_course(stu->get_num_enrolled_course()-1);

    if(orgC->get_wait_list()->get_head()!=nullptr){
        
        //cout<<"test"<<endl;
        Student_ListNode* tempNode = orgC->get_wait_list()->get_head();
        int stuId= tempNode->student_id;
        orgC->get_students_enrolled()[search_student_id(student_id,orgC)] =stuId;
        Student* temp = get_student_database()->get_student_by_id(stuId);
        temp->set_curr_credit(temp->get_curr_credit()+orgC_cr);
        
        if(temp->get_swap_list()->get_head()!=nullptr){
            //cout<<"test:" <<temp->get_name()<<endl;
            Swap* tempNode2 = temp->get_swap_list()->get_head();
            while (strcmp(tempNode2->target_course_name,course_name)!=0 || tempNode2->next!=nullptr)
            {
                tempNode2 = tempNode2->next;
            }
            if(strcmp(tempNode2->target_course_name,course_name)==0){
                Course* swapC = get_course_database()->get_course_by_name(tempNode2->original_course_name);
                
                drop(temp->get_student_id(),swapC->get_name());

                temp->get_swap_list()->set_head(nullptr);
            }
            
            
        }
       

        temp->get_enrolled_courses()[temp->get_num_enrolled_course()] = new char[strlen(course_name)+1];
        //cout<<"test:" <<temp->get_student_id()<<endl;
        strcpy(temp->get_enrolled_courses()[temp->get_num_enrolled_course()], orgC->get_name());
        

        temp->set_num_enrolled_course(temp->get_num_enrolled_course()+1);
   
        temp->set_pending_credit(temp->get_pending_credit()-orgC_cr);

        if(temp->get_pending_credit()<0){
             temp->set_pending_credit(0);
        }
        orgC->get_wait_list()->set_head(tempNode->next);

        delete tempNode;

    }else{
        orgC->get_students_enrolled()[search_student_id(student_id,orgC)] = orgC->get_students_enrolled()[orgC->get_size()-1];
        orgC->get_students_enrolled()[orgC->get_size()-1] = 0;
        orgC->set_size(orgC->get_size()-1);
    }

}

void System::add_course(const char* const name, const int num_credit, const int course_capacity) {
    this->course_database->create_entry(name, num_credit, course_capacity);
}

void System::print_info() const {
    this->course_database->print_all_course();
    this->student_database->print_all_students();
}

Course_Database* System::get_course_database() const {
    return course_database;
}

Student_Database* System::get_student_database() const {
    return student_database;
}

void System::set_course_database(Course_Database* const course_database) {
    this->course_database = course_database;
}

void System::set_student_database(Student_Database* const student_database) {
    this->student_database = student_database;
}
