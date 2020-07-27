/* University (Yliopisto)
 *
 * Desc:
 * This program creates an class where you can
 * input staff and students alike and asign them to
 * different courses.
 *
 * The program also keeps in track of the time
 * and is able to take in commands to change it.
 *
 * Program keeps track of the completed cources a student
 * has completed and gives the points (5) for each one.
 *
 * Program Author:
 * Name: Petrus Jussila
*/

#include "utils.hh"
#include "cli.hh"
#include "university.hh"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::string PROMPT = "Uni> ";


int main()
{
    University* university = new University();
    Cli cli(university, PROMPT);
    while ( cli.exec() ){}

    delete university;
    return EXIT_SUCCESS;
}
