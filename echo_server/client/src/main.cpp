/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:16:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 22:39:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/Client.hpp"

int main(void) {
  try {
    Client client;
    client.Run();
    client.TerminateClient();
  } catch (const CustomException& e) {
    std::cerr << e.What() << '\n';
  }
}