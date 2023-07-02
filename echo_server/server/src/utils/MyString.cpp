/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyString.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:53:46 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/25 22:21:54 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyString.hpp"

// public **********************************************************************

std::string MyString::ColorString(const std::string &str,
                                  enum StringColor foreground_color,
                                  enum StringColor background_color) {
  std::string color_prefix = "\033[";
  std::string color_suffix = "m";
  std::string color_end = "\033[0m";

  std::string foreground_color_data, background_color_data;
  if (foreground_color != kStrPreset)
    foreground_color_data = "3" + std::to_string(foreground_color);
  if (background_color != kStrPreset)
    background_color_data = "4" + std::to_string(background_color);
  std::string color_start;
  color_start += color_prefix;
  color_start += foreground_color_data;
  if (background_color_data.empty() == false) {
    if (foreground_color_data.empty() == false) color_start += ";";
    color_start += background_color_data;
  }
  color_start += color_suffix;
  return color_start + str + color_end;
}

std::string MyString::ColorString(const char *str,
                                  enum StringColor foreground_color,
                                  enum StringColor background_color) {
  std::string converted_str = str;
  return ColorString(converted_str, foreground_color, background_color);
}

std::string MyString::GetPreciseTime() {
  // Get current time
  timeval current_time;
  gettimeofday(&current_time, NULL);
  int micro = current_time.tv_usec;

  // Convert timeval to tm
  std::time_t raw_time = current_time.tv_sec;
  std::tm *time_info = std::localtime(&raw_time);

  // Prepare a string stream
  std::ostringstream oss;

  // Output the date, time, and microseconds into the string stream
  oss << (time_info->tm_year + 1900) << "." << std::setfill('0') << std::setw(2)
      << (time_info->tm_mon + 1) << "." << std::setfill('0') << std::setw(2)
      << time_info->tm_mday << " " << std::setfill('0') << std::setw(2)
      << time_info->tm_hour << ":" << std::setfill('0') << std::setw(2)
      << time_info->tm_min << ":" << std::setfill('0') << std::setw(2)
      << time_info->tm_sec << "." << std::setfill('0') << std::setw(6) << micro;

  // Return the string
  return oss.str();
}

// private *********************************************************************
