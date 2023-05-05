/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:45:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 21:33:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/**
 * @brief This function is for coloring printed characters which will be useful 
 * for distinguishing printed strings in a testing environment.
 * 
 * @param str 
 * @param foreground_color 
 * @param background_color 
 */
void printColoredString(std::string str, std::string foreground_color = "White", std::string background_color = "Black")
{
    std::string color_end = "\033[0m";
    std::string color_prefix = "\033[";
    std::string color_suffix = "m";

    std::string foreground_color_data;
    if (foreground_color == "Black")
        foreground_color_data = "30";
    else if (foreground_color == "Red")
        foreground_color_data = "31";
    else if (foreground_color == "Green")
        foreground_color_data = "32";
    else if (foreground_color == "Yellow")
        foreground_color_data = "33";
    else if (foreground_color == "Blue")
        foreground_color_data = "34";
    else if (foreground_color == "Magenta")
        foreground_color_data = "35";
    else if (foreground_color == "Cyan")
        foreground_color_data = "36";
    else if (foreground_color == "White")
        foreground_color_data = "37";
    else
        foreground_color_data = "30";

    std::string background_color_data;
    if (background_color == "Black")
        background_color_data = "40";
    else if (background_color == "Red")
        background_color_data = "41";
    else if (background_color == "Green")
        background_color_data = "42";
    else if (background_color == "Yellow")
        background_color_data = "43";
    else if (background_color == "Blue")
        background_color_data = "44";
    else if (background_color == "Magenta")
        background_color_data = "45";
    else if (background_color == "Cyan")
        background_color_data = "46";
    else if (background_color == "White")
        background_color_data = "47";

    std::string color_start;
    color_start += color_prefix;
    color_start += foreground_color_data;
    if (background_color_data.empty() == false)
    {
        if (foreground_color_data.empty() == false)
            color_start += ";";
        color_start += background_color_data;
    }
    color_start += color_suffix;

    std::cout << color_start << str << color_end << std::endl;
}

// Testing creates() function from Intern class
void test1()
{
    printColoredString("Execute Test1");
    Bureaucrat b1("John", 1);
    Intern i1;
    AForm *form_array[4];

    form_array[0] = i1.makeForm("SomeThingWeird", "Bob");  // invalid form name
    form_array[1] = i1.makeForm("ShrubberyCreationForm", "SomePlace");
    form_array[2] = i1.makeForm("RobotomyRequestForm", "Ronnie");
    form_array[3] = i1.makeForm("PresidentialPardonForm", "Jay");

    for (size_t i = 0; i < 4; i++)
    {
        if (form_array[i] != NULL)
        {
            printColoredString(form_array[i]->getName(), "Blue", "Black");
            b1.signForm(*form_array[i]);
            b1.executeForm(*form_array[i]);
        }
        else
            std::cout << "form_ptr is NULL" << std::endl;
    }

    printColoredString("Test1 complete");
}

int main(void)
{
    printColoredString("Entered testing area!!", "White", "Blue");

    test1();

    printColoredString("Exiting testing area!!", "White", "Blue");
}