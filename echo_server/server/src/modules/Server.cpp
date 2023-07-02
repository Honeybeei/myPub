/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:45:24 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/29 10:24:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  Default constructor
Server::Server() {
  CreateSocket();
  BindSocket();
  StartListening();
  AcceptConnections();
}

//  destructor
Server::~Server() {}

//  functions ------------------------------------------------------------------

/**
 * @brief This function starts the server.
 *
 */
void Server::Run() {
  std::string received_message;
  while (true) {
    ClearBuffer();
    received_message = ReceiveMessage();
    std::cout << MyString::GetPreciseTime() << " | " << received_message
              << std::endl;
    if (received_message == "exit" || received_message.empty()) break;
  }
}

/**
 * @brief Termination process of a server. Add codes if there are more resources
 * to collect which allocated dynamically.
 *
 */
void Server::TerminateServer() {
  if (close(socket_fd_))
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "close() fail");
  // TODO : Retrieve all resources allocated at running time.
}

// private *********************************************************************

void Server::CreateSocket() {
  socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd_ == 0)
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "socket() failed");
}

void Server::BindSocket() {
  address_.sin_family = AF_INET;
  address_.sin_addr.s_addr = INADDR_ANY;
  address_.sin_port = htons(kPort);
  addrlen_ = sizeof(address_);

  if (bind(socket_fd_, (struct sockaddr*)&address_, addrlen_)) {
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "bind() failed");
  }
}

void Server::StartListening() {
  if (listen(socket_fd_, kBacklog))
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "listen() failed");
}

void Server::AcceptConnections() {
  new_socket_ =
      accept(socket_fd_, (struct sockaddr*)&address_, (socklen_t*)&addrlen_);
  if (new_socket_ < 0) {
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "accept() failed");
  }
}

std::string Server::ReceiveMessage() {
  if (recv(new_socket_, buffer_, kBufferSize, 0) < 0)
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "recv() failed");
  return std::string(buffer_);
}
