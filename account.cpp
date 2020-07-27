#include "account.hh"
#include "utils.hh"
#include "instance.hh"
#include "course.hh"

Account::Account(std::string full_name, std::string email, int account_number):
    full_name_(full_name),
    last_name_(""),
    first_name_(""),
    email_(email),
    account_number_(account_number)
{
    std::vector<std::string> name = utils::split(full_name_, ' ');
    last_name_ = name.back();
    first_name_ = name.front();
}


void Account::print() const
{
    std::cout << account_number_ << ": "
              << first_name_ << " "
              << last_name_  << ", "
              << email_ << std::endl;
}

std::string Account::get_email()
{
    return email_;
}

void Account::complete_course(Course *course, std::string instance_name) {
    Instance* c_inst = course->get_instance(instance_name);
    int i = 0;
    for (Instance* current : current_) {
        if (current == c_inst) {
            current_.erase(current_.begin()+i);
            completed_.push_back(course);
            std::cout << COMPLETED << std::endl;
            return;
        }
        ++i;
    }
    std::cout << NO_SIGNUPS << std::endl;
}

void Account::print_study_state()
{
    std::cout << "Current:" << std::endl;

    for (Instance* inst : current_) {
        inst->get_course()->print_info(false);
        std::cout << " " << inst->get_name() << std::endl;
    }

    std::cout << "Completed:" << std::endl;

    print_completed();
}

void Account::print_completed()
{
    int credits = 0;

    for (Course* course : completed_) {
        course->print_info(true);
        credits += course->get_credits();
    }
    std::cout << "Total credits: " << credits << std::endl;
}

void Account::add_to_current(Instance *current)
{
    current_.push_back(current);
}
