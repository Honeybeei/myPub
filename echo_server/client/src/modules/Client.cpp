/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:35:42 by seoyoo            #+#    #+#             */
/*   Updated: 2023/06/21 16:10:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

Client::Client() {
  CreateSocket();
  SetAddress();
  ConnectToServer();
}

Client::~Client() {
  // TODO
}

//  functions ------------------------------------------------------------------

/**
 * @brief This function starts the client.
 *
 */
void Client::Run() {
  std::string buffer;
  while (true) {
    buffer.clear();
    std::getline(std::cin, buffer);
    std::cout << MyString::GetPreciseTime() << " | You entered : " << buffer
              << std::endl;
    SendMessage(buffer);
    if (buffer == "exit" || buffer.empty()) break;
  }
}

/**
 * @brief Termination process of a client. Add codes if there are more resources
 * to collect which allocated dynamically.
 *
 */
void Client::TerminateClient() {
  if (close(socket_fd_))
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "close() fail");
  // TODO : Retrieve all resources
}

// private *********************************************************************

//  functions ------------------------------------------------------------------

void Client::CreateSocket() {
  socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd_ < 0)
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "socket() fail");
}

void Client::SetAddress() {
  address_.sin_family = AF_INET;
  address_.sin_port = htons(kPort);

  int result = inet_pton(AF_INET, "127.0.0.1", &address_.sin_addr);
  if (result == 0)
    throw CustomException(CustomException::kExceptionUnknown,
                          "Invalid address");
  else if (result < 0)
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "inet_pton() fail");
}

void Client::ConnectToServer() {
  if (connect(socket_fd_, (struct sockaddr*)&address_, sizeof(address_)))
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "connect() fail");
}

void Client::SendMessage(const std::string& message) {
  if (send(socket_fd_, message.c_str(), message.length(), 0) < 0)
    throw CustomException(CustomException::kExceptionSystemCallFail,
                          "send() fail");
}
