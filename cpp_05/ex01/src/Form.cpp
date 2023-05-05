/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:40:04 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 22:11:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// private *********************************************************************

void Form::checkGradeRange()
{
    if (GRADE_TO_SIGN_ < Bureaucrat::getMaxGrade() || GRADE_TO_EXECUTE_ < Bureaucrat::getMaxGrade())
        throw std::out_of_range("Form::GradeToHighException");
    else if (GRADE_TO_SIGN_ > Bureaucrat::getMinGrade() || GRADE_TO_EXECUTE_ > Bureaucrat::getMinGrade())
        throw std::out_of_range("Form::GradeToLowException");
}

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : NAME_(name), GRADE_TO_SIGN_(grade_to_sign), GRADE_TO_EXECUTE_(grade_to_execute), is_signed_(false)
{
    checkGradeRange();
}

Form::Form(const Form &src) : NAME_(src.NAME_), GRADE_TO_SIGN_(src.GRADE_TO_SIGN_), GRADE_TO_EXECUTE_(src.GRADE_TO_EXECUTE_), is_signed_(src.is_signed_)
{
    checkGradeRange();
}

Form::~Form()
{
    /* Destructor */
}

//  operators ------------------------------------------------------------------

Form &Form::operator=(const Form &rhs)
{
    if (this == &rhs)
        return *this;
    is_signed_ = rhs.is_signed_;
    return *this;
}

// functions -------------------------------------------------------------------

std::string Form::getName() const { return NAME_; }

int Form::getGradeToSign() const { return GRADE_TO_SIGN_; }

int Form::getGradeToExecute() const { return GRADE_TO_EXECUTE_; }

bool Form::getIsSigned() const { return is_signed_; }

bool Form::beSigned(Bureaucrat const &someone)
{
    if (someone.getGrade() > GRADE_TO_SIGN_)
        throw std::out_of_range("Form:GradeTooLowException");
    if (is_signed_ == false)
    {
        is_signed_ = true;
        return true;
    }
    else
        return false;  // If the form is already sighed, it returns false
}

//  operators(overloaded globally) ---------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
    os << "Form Spec"
        << "\nName             : " << rhs.getName()
        << "\nGrade to sign    : " << rhs.getGradeToSign()
        << "\nGrade to execute : " << rhs.getGradeToExecute()
        << "\nIs signed        : " ;
        if (rhs.getIsSigned() == true)
            os << "true" << std::endl;
        else
            os << "false" << std::endl;
    return os;
}
