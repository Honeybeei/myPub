/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:26:07 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 21:01:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// private *********************************************************************

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    (void)src;
}

Intern::~Intern()
{
}

//  operators ------------------------------------------------------------------

Intern &Intern::operator=(const Intern &rhs)
{
    if (this == &rhs)
        return *this;
    return *this;
}

//  functions ------------------------------------------------------------------

AForm *Intern::makeForm(std::string form_name, std::string target) const
{
    const int FORM_TYPE_CNT = 3;
    AForm *form_list[FORM_TYPE_CNT];
    AForm *matching_form = NULL;
    form_list[0] = new ShrubberyCreationForm(target);
    form_list[1] = new RobotomyRequestForm(target);
    form_list[2] = new PresidentialPardonForm(target);
    for (int i = 0; i < FORM_TYPE_CNT; i++)
    {
        if (form_list[i]->getName() == form_name)
        {
            matching_form = form_list[i];
            form_list[i] = NULL;
        }
    }
    if (matching_form == NULL)
        std::cout << "Intern can't find the matching form.... :(" << std::endl;
    else
        std::cout << "Intern creates " << matching_form->getName() << std::endl;
    for (int i = 0; i < FORM_TYPE_CNT; i++)
    {
        if (form_list[i] != NULL)
            delete form_list[i];
    }
    return matching_form;
}