/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:50:07 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 21:28:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOMEXCEPTION_HPP_
#define CUSTOMEXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <string>

#include "MyString.hpp"

// Tips!!
// 1. If you want to add another exception/error type, add new type to "enum
// ExceptionTypes".
// 2. Use CustomException(enum ExceptionTypes exception_type, const std::string
// &message);
// 3. Use e.What() instead of e.what();
// 4. If you want to know how to use this class, there is an example in
// test/utils/CustomExceptionTest.cpp

class CustomException : public std::exception {
 public:
  // defining Exception types
  enum ExceptionTypes {
    kExceptionUnknown,
    kExceptionConfigParsing,
    kExceptionSystemCallFail
    // TODO : add more!!
  };

  // constructors & destructor
  CustomException(const std::string &message);
  CustomException(enum ExceptionTypes exception_type,
                  const std::string &message);
  virtual ~CustomException() throw() {};

  // functions
  const char *what() const throw() { return message_.c_str(); }  // overriding
  std::string What() const;  // advanced version of CustomException.what()
  void TerminationProcess();

 private:
  // constant
  static const bool kPrintErrorWhenThrow = false;
  static const bool kColorErrorString = false;
  static const enum StringColor kErrorMessageForegroundColor = kStrRed;
  static const enum StringColor kErrorMessageBackgroundColor = kStrBlack;

  // variable
  enum ExceptionTypes exception_type_;
  std::string message_;

  // function
  static std::string GetErrorMessage(enum ExceptionTypes exception_type,
                                     const std::string &message);
};

#endif