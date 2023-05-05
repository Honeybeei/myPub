/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:26:47 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 21:38:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// private *********************************************************************

//  functions ------------------------------------------------------------------

void Bureaucrat::checkGradeRange()
{
    if (grade_ < MAX_GRADE_)
    {
        grade_ = MAX_GRADE_;
        throw std::range_error("Bureaucrat::GradeTooHighException");
    }
    else if (grade_ > MIN_GRADE_)
    {
        grade_ = MIN_GRADE_;
        throw std::range_error("Bureaucrat::GradeTooLowException");
    }
}

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

Bureaucrat::Bureaucrat() : NAME_("Unknown"), grade_(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : NAME_(name), grade_(grade)
{
    checkGradeRange();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : NAME_(src.NAME_), grade_(src.grade_)
{
}

Bureaucrat::~Bureaucrat()
{
}

//  operators ------------------------------------------------------------------

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this == &rhs)
        return *this;
    grade_ = rhs.grade_;
    checkGradeRange();
    return *this;
}

//  functions ------------------------------------------------------------------

std::string Bureaucrat::getName() const { return NAME_; }

int Bureaucrat::getMaxGrade() { return MAX_GRADE_; }

int Bureaucrat::getMinGrade() { return MIN_GRADE_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::promote()
{
    grade_--;
    checkGradeRange();
}

void Bureaucrat::demote()
{
    grade_++;
    checkGradeRange();
}

//  operators(overloaded globally) ---------------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
    os << rhs.getName() << " : bureaucrat grade [" << rhs.getGrade() << "]" << std::endl;
    return os;
}
