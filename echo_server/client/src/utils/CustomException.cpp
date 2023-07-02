/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:51:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 21:55:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomException.hpp"

// public **********************************************************************

// Default constructor
// Exception type will be set to kExceptionUnknown.
// If you want to print Error message, change kPrintErrorWhenThrow(boolean) to
// true.
// TODO : has conflict with kQueue with using output streams. figure this out
// later. But now we will just print error to std::cerr.
CustomException::CustomException(const std::string &message)
    : exception_type_(kExceptionUnknown), message_(message) {
  if (kPrintErrorWhenThrow)
    std::cerr << GetErrorMessage(exception_type_, message_) << std::endl;
}

// Constructor with exception type. This constructor should be mainly used.
CustomException::CustomException(enum ExceptionTypes exception_type,
                                 const std::string &message)
    : exception_type_(exception_type), message_(message) {
  if (kPrintErrorWhenThrow)
    std::cerr << GetErrorMessage(exception_type_, message_) << std::endl;
}

// Advanced version of what().
// It returns Customized error string including time, type and message.
std::string CustomException::What() const {
  return GetErrorMessage(exception_type_, message_);
}

// Termination protocol in webserv level
void CustomException::TerminationProcess() {
  // TODO
  std::exit(1);
}

// private *********************************************************************

// Returns colored(when kColorErrorString is true) Error message in std::string
// type. Format of Error String : [%TIME] %EXCEPTION_TYPE %MESSAGE
// Change constants in CustomException.hpp to change values.
std::string CustomException::GetErrorMessage(enum ExceptionTypes exception_type,
                                             const std::string &message) {
  // set time string
  std::string time_str = MyString::GetPreciseTime();

  // set error-type string
  std::string error_type_str;
  switch (exception_type) {
    case kExceptionConfigParsing:
      error_type_str = "ConfigParsing";
      break;
    case kExceptionSystemCallFail:
      error_type_str = "SystemCallFail";
      break;
    default:
      error_type_str = "Unknown";
      break;
  }
  std::string result_str =
      "[ " + time_str + " ] " + error_type_str + " : " + message;
  if (kColorErrorString)
    return MyString::ColorString(result_str, kErrorMessageForegroundColor,
                                 kErrorMessageBackgroundColor);
  else
    return result_str;
}
