/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:45:22 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 22:30:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "../../include/defines.hpp"
#include "../utils/CustomException.hpp"

class Server {
 public:
  // constructors & destructor
  Server();
  ~Server();
  // functions
  void Run();
  void TerminateServer();

 private:
  // variables
  int socket_fd_;
  int new_socket_;
  struct sockaddr_in address_;
  int addrlen_;
  char buffer_[kBufferSize];

  // functions
  std::string ReceiveMessage();
  void ClearBuffer() { std::memset(buffer_, 0, kBufferSize); }
  void CreateSocket();
  void BindSocket();
  void StartListening();
  void AcceptConnections();
};

#endif