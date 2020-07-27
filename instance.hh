/* Class: Instance
 * ----------
 * TIE-02201/TIE-02207 SPRING 2020
 * ----------
 * Class that represent a single instance.
 * */
#ifndef INSTANCE_HH
#define INSTANCE_HH

#include "account.hh"
#include "date.hh"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

// Forward-declaration of Course, so that instance can point to the course it belongs to.
class Course;

const std::string ALREADY_REGISTERED = "Error: Student has already registered on this course.";
const std::string LATE = "Error: Can't sign up on instance after the starting date.";
const std::string INDENT = "    ";

class Instance
{
public:
    /**
     * @brief Instance constructor
     * @param course
     * @param instance_name
     * @param date
     */
    Instance(Course* course, std::string instance_name, const Date date);

    /**
     * @brief print starting date and students in it
     */
    void print();

    /**
     * @brief print student's in instance
     */
    void print_students();

    /**
     * @brief add_student_to_instance
     * @param account
     * @param today
     */
    void add_student_to_instance(Account* account, Date today);

    /**
     * @brief checks if name matches instance's
     * @param name
     * @return true/false
     */
    bool is_named(const std::string& name);

    /**
     * @brief find_student
     * @param account
     * @return true/false
     */
    bool find_student(Account* account);

    /**
     * @brief get_name
     * @return instance_name
     */
    std::string get_name();

    /**
     * @brief get_course
     * @return course
     */
    Course *get_course();
private:
    Course* course_;
    std::string instance_name_;
    Date instance_date_;
    std::vector<Account*> students_;
};

#endif // INSTANCE_HH
