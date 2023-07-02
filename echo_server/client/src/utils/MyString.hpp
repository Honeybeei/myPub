/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyString.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:53:45 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/25 22:17:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRING_HPP_
#define MYSTRING_HPP_

#include <string>
#include <ctime>
#include <sys/time.h>
#include <sstream>
#include <iomanip>

// enum to color strings
enum StringColor {
  kStrPreset = -1,
  kStrBlack = 0,
  kStrRed,
  kStrGreen,
  kStrYellow,
  kStrBlue,
  kStrMagenta,
  kStrCyan,
  kStrWhite
};

class MyString {
 public:
  // functions
  static std::string ColorString(const std::string &str,
                                 enum StringColor foreground_color,
                                 enum StringColor background_color);
  static std::string ColorString(const char *str,
                                 enum StringColor foreground_color,
                                 enum StringColor background_color);

  static std::string GetPreciseTime();
 protected:
 private:
};

#endif