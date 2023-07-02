#!/bin/bash

# Define paths
server_dir="./server"
client_dir="./client"

# Make server and client
(cd "$server_dir" && make fclean)
(cd "$client_dir" && make fclean)
