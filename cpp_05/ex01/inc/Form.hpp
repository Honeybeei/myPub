/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:39:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 22:14:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
public:
    // constructors & destructor
    Form(std::string name, int grade_to_sign, int grade_to_execute);
    Form(const Form &src);
    ~Form();
    // operators
    Form &operator=(const Form &rhs);
    // functions
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;
    bool beSigned(Bureaucrat const &someone);
    
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
