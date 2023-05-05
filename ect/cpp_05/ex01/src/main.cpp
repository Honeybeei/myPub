/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:45:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 22:59:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1()
{
    Bureaucrat b1("John Wick", 10);
    std::cout << b1 << std::endl;
    Form f1("Killing Form", 13, 10);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
}

void test2()
{
    Bureaucrat b1("John Wick", 14);
    std::cout << b1 << std::endl;
    Form f1("Killing Form", 13, 10);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
}

void test3()
{
    try
    {
        Bureaucrat b1("John Wick", 0);
        // should not be executed from here
        std::cout << b1 << std::endl;
        Form f1("Killing Form", 13, 10);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test4()
{
    // testing if checkRange function works well.
    try
    {
        Form f1("Awesome form", 0, 100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form f2("Awesome form", 1, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main(void)
{
    std::cout << "Testing area\n" << std::endl;

    // test1();
    // test2();
    // test3();
    test4();

    std::cout << "Test FINISHED!!" << std::endl;
}