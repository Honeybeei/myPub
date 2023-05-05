/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:46 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 21:05:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target_;
    void pardon() const;
protected:
public:
    // constructors & destructor
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    virtual ~PresidentialPardonForm();
    // operators
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    // functions
    void execute(const Bureaucrat &executor) const;
};

#endif