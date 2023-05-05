/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:42:36 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/01 21:36:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// private *********************************************************************

void ShrubberyCreationForm::createTree() const
{
    std::string file_name = target_ + "_shrubbery";
    std::ofstream file_to_write(file_name);
    if (file_to_write.is_open() == false || file_to_write.fail() == true)
        throw std::runtime_error("Failed to open file: " + file_name);
    std::string ascii_trees = "    /\\          /\\          /\\    \n  /////\\      /////\\      /////\\  \n ///////\\    ///////\\    ///////\\ \n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n   ||||        ||||        ||||   \n   ||||        ||||        ||||   ";
    file_to_write << ascii_trees << std::endl;
    file_to_write.close();
}

// protected *******************************************************************

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target_(src.target_)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//  operators ------------------------------------------------------------------

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this == &rhs)
        return *this;
    target_ = rhs.target_;
    return *this;
}

//  functions ------------------------------------------------------------------

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    checkViability(executor);
    createTree();
}