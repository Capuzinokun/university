#include "instance.hh"
#include "course.hh"

Instance::Instance(Course* course, std::string instance_name, const Date date):
    course_(course), instance_name_(instance_name), instance_date_(date)
{

}

void Instance::print() {
    std::cout << instance_name_ << std::endl;
    std::cout << INDENT << "Starting date: ";
    instance_date_.print();
    std::cout << std::endl;
    std::cout << INDENT << "Amount of students: " << students_.size() << std::endl;

}

void Instance::print_students() {
    if (students_.size() != 0) {
        for (auto student: students_) {
            std::cout << INDENT;
            student->print();
        }
    }
}

void Instance::add_student_to_instance(Account* account, Date today)
{
    if (instance_date_ == today) {
        students_.push_back(account);
        account->add_to_current(this);
        std::cout << SIGNED_UP << std::endl;
        return;
    }
    else {
        std::cout << LATE << std::endl;
    }
}

bool Instance::is_named(const std::string& name) {
    if (name == instance_name_){
        return true;
    }
    else {
        return false;
    }
}

bool Instance::find_student(Account* account) {
    if (std::find(students_.begin(), students_.end(), account) == students_.end()) {
        return true;
    }
    else {
        return false;
    }
}

std::string Instance::get_name()
{
    return instance_name_;
}

Course *Instance::get_course()
{
    return course_;
}
