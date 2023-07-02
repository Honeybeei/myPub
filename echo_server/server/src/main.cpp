/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:16:04 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 22:32:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/Server.hpp"

int main(void) {
  try {
    Server server;
    server.Run();
    server.TerminateServer();
  } catch (const CustomException& e) {
    std::cerr << e.What() << '\n';
  }

  return 0;
}