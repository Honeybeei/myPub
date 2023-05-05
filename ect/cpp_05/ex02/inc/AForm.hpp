/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:39:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 16:02:00 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    // constants
    const std::string NAME_;
    const int GRADE_TO_SIGN_;
    const int GRADE_TO_EXECUTE_;
    // variables
    bool is_signed_;
    // functions
    void checkGradeRange();

protected:
    void checkViability(const Bureaucrat &executor) const;

public:
    // constructors & destructor
    AForm(std::string name, int grade_to_sign, int grade_to_execute);
    AForm(const AForm &src);
    ~AForm();
    // operators
    AForm &operator=(const AForm &rhs);
    // functions
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;
    bool beSigned(Bureaucrat const &someone);
    virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif
