/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:00:17 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 18:47:06 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target_;
    void robotomize() const;

protected:

public:
    // constructors & destructor
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();
    // operators
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    // functions
    void execute(const Bureaucrat &executor) const;
};

#endif