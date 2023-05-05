/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:40:04 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 15:39:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// private *********************************************************************

void AForm::checkGradeRange()
{
    if (GRADE_TO_SIGN_ < Bureaucrat::getMaxGrade() || GRADE_TO_EXECUTE_ < Bureaucrat::getMaxGrade())
        throw std::out_of_range("Form::GradeToHighException");
    else if (GRADE_TO_SIGN_ > Bureaucrat::getMinGrade() || GRADE_TO_EXECUTE_ > Bureaucrat::getMinGrade())
        throw std::out_of_range("Form::GradeToLowException");
}

// protected *******************************************************************

void AForm::checkViability(const Bureaucrat &executor) const
{
    if (is_signed_ == false)
        throw std::invalid_argument("Form::NotSignedException");
    if (GRADE_TO_EXECUTE_ < executor.getGrade())
        throw std::range_error("Bureaucrat::GradeTooLowException");
}

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : NAME_(name), GRADE_TO_SIGN_(grade_to_sign), GRADE_TO_EXECUTE_(grade_to_execute), is_signed_(false)
{
    checkGradeRange();
}

AForm::AForm(const AForm &src) : NAME_(src.NAME_), GRADE_TO_SIGN_(src.GRADE_TO_SIGN_), GRADE_TO_EXECUTE_(src.GRADE_TO_EXECUTE_), is_signed_(src.is_signed_)
{
    checkGradeRange();
}

AForm::~AForm()
{
    /* Destructor */
}

//  operators ------------------------------------------------------------------

AForm &AForm::operator=(const AForm &rhs)
{
    if (this == &rhs)
        return *this;
    is_signed_ = rhs.is_signed_;
    return *this;
}

// functions -------------------------------------------------------------------

std::string AForm::getName() const { return NAME_; }

int AForm::getGradeToSign() const { return GRADE_TO_SIGN_; }

int AForm::getGradeToExecute() const { return GRADE_TO_EXECUTE_; }

bool AForm::getIsSigned() const { return is_signed_; }

bool AForm::beSigned(Bureaucrat const &someone)
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

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
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
