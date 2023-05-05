/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:04:58 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 21:38:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    // constants
    const std::string NAME_;
    static const int MAX_GRADE_ = 1;
    static const int MIN_GRADE_ = 150;
    // variables
    int grade_;
    // functions
    void checkGradeRange();
protected:
public:
    // constructors & destructor
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &rhs);
    ~Bureaucrat();
    // operators
    Bureaucrat &operator=(const Bureaucrat &src);
    // functions
    std::string getName() const;
    static int getMaxGrade();
    static int getMinGrade();
    int getGrade() const;
    void promote();
    void demote();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif