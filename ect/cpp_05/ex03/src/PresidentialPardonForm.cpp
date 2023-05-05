/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:54 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 18:47:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// private *********************************************************************

void PresidentialPardonForm::pardon() const
{
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target_(src.target_)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

//  operators ------------------------------------------------------------------

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this == &rhs)
        return *this;
    target_ = rhs.target_;
    return *this;
}

//  functions ------------------------------------------------------------------

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkViability(executor);
    pardon();
}
