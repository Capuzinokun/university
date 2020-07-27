/* Class: Account
  * ----------
  * Defines a student or a staff account in the university system.
  * */
#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include "date.hh"
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Instance;
class Course;

const std::string NO_SIGNUPS = "No signups found on this instance.";
const std::string SIGNED_UP = "Signed up on the course instance.";
const std::string COMPLETED = "Course completed.";

class Account
{
public:
    /**
     * @brief Account constructor
     * @param full_name as "frontname lastname"
     * @param email
     * @param account_number
     */
    Account(std::string full_name, std::string email, int account_number);

    /**
     * @brief print account info on one line
     */
    void print() const;

    /**
     * @brief get_email
     * @return email linked to this account
     */
    std::string get_email();

    /**
     * @brief complete the course for given student
     * @param course
     * @param inst_name
     */
    void complete_course(Course *course, std::string inst_name);

    /**
     * @brief print the given student's study state
     * current/completed courses
     */
    void print_study_state();

    /**
     * @brief print the given student's
     * list of completed courses
     */
    void print_completed();

    /**
     * @brief add given course to student's list of current courses
     * @param current
     */
    void add_to_current(Instance* current);

private:
    std::string full_name_;
    std::string last_name_;
    std::string first_name_;
    std::string email_;
    const int account_number_;
    std::vector<Instance*> current_;
    std::vector<Course*> completed_;
};

#endif // ACCOUNT_HH
