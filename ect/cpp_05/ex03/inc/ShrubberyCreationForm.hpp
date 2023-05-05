/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:42:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 21:05:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target_;
    void createTree() const;

protected:
public:
    // constructors & destructor
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    virtual ~ShrubberyCreationForm();
    // operators
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    // functions
    void execute(const Bureaucrat &executor) const;
};

#endif