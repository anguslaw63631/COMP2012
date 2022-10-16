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
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student* const student, const char* const course_name) {
    // TODO
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course* const course) {
    // TODO
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
    Student* tempStudent = get_student_database()->get_student_by_id(student_id);

    int curr_cr = tempStudent->get_curr_credit();
    int max_cr = tempStudent->get_max_credit();
    int enrolled_num = tempStudent->get_num_enrolled_course();
    char** enrolled_courses = tempStudent->get_enrolled_courses();

    Course* tempCourse = get_course_database()->get_course_by_name(course_name);

    int course_cr = tempCourse->get_num_credit();
    int* enrolled_students = tempCourse->get_students_enrolled();
    int num_enrolled_course = tempCourse->get_size();
    if(curr_cr+course_cr > max_cr){
        return false;
    }

    tempStudent->set_curr_credit(curr_cr+course_cr);

    
    enrolled_courses[enrolled_num] = tempCourse->get_name();
    enrolled_num++;
    tempStudent->set_enrolled_courses(enrolled_courses);
    tempStudent->set_num_enrolled_course(enrolled_num);

    
    enrolled_students[num_enrolled_course] = tempStudent->get_student_id();
    num_enrolled_course++;
    tempCourse->set_students_enrolled(enrolled_students);
    tempCourse->set_size(num_enrolled_course);
    
    return true;
}

bool System::swap(const int student_id, const char* const original_course_name, const char* const target_course_name) {
    // TODO

    return true;
}

void System::drop(const int student_id, const char* const course_name) {
    // TODO
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
