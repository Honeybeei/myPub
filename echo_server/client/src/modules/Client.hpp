/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:40:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 22:38:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "../utils/CustomException.hpp"
#include "defines.hpp"

class Client {
 public:
  // constructors & destructorÓ
  Client();
  ~Client();

  // functions
  void Run();
  void TerminateClient();

 private:
  // variables
  int socket_fd_;
  struct sockaddr_in address_;

  // functions
  void CreateSocket();
  void SetAddress();
  void ConnectToServer();
  void SendMessage(const std::string& message);
};
