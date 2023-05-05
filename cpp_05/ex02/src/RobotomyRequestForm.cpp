/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:00:29 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 18:51:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <unistd.h>

// private *********************************************************************

void RobotomyRequestForm::robotomize() const
{
    srand(time(NULL));

    int operation_time = rand() % 5 + 1;
    bool operation_result = rand() % 2;
    std::cout << "\033[31;47m" << "Operation started" << "\033[0m" << std::endl;
    for (int i = 0; i < operation_time; i++)
    {
        std::cout << "Buzzzz......" << std::endl;
        sleep(1);
    }
    if (operation_result == true)
        std::cout << "\033[31;47m" << target_ << " has been robotomized successfully!!" << "\033[0m" << std::endl;
    else
        std::cout << "\033[31;47m" << "Operation fail......" << "\033[0m" << std::endl;
}

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target_(src.target_)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//  operators ------------------------------------------------------------------

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this == &rhs)
        return *this;
    target_ = rhs.target_;
    return *this;
}

// functions -------------------------------------------------------------------

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkViability(executor);
    robotomize();
}