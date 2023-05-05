/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:45:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/04/30 21:39:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

void catchThrowTest1()
{
    // with try - catch statement
    try
    {
        Bureaucrat b1("John Wick", 3);
        while (true)
        {
            b1.promote();
            std::cout << b1.getName() << " is now Lv " << b1.getGrade() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test1 complete" << std::endl;
}

void catchThrowTest2()
{
    // without try - catch statement -> program will be terminated with uncaught exception
    Bureaucrat b1("Tom", 3);
    while (true)
    {
        b1.promote();
        std::cout << b1.getName() << " is now Lv " << b1.getGrade() << std::endl;
    }
    std::cout << "Test2 complete" << std::endl;
}

void ectTest()
{
    Bureaucrat b1;
    Bureaucrat b2("John", 123);
    Bureaucrat b3("Tom", 1);

    // check overloaded operators
    std::cout << "b1 current status | " << b1 << std::endl;
    b1 = b2;
    std::cout << "b1 current status | " << b1 << std::endl;
}

int main(void)
{
    std::cout << "Testing area\n" << std::endl;
    // catchThrowTest1();
    // catchThrowTest2();
    ectTest();
    std::cout << "Test FINISHED!!" << std::endl;
}