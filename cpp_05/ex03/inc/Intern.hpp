/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:25:44 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 20:51:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class AForm;

class Intern
{
private:
protected:
public:
    // constructors & destructor
    Intern();
    Intern(const Intern &rhs);
    ~Intern();
    // operators
    Intern &operator=(const Intern &src);
    // functions
    AForm *makeForm(std::string form_name, std::string target) const;
};

#endif