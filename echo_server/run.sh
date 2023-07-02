#!/bin/bash

# Define paths
server_dir="./server"
client_dir="./client"

# Make server and client
(cd "$server_dir" && make)
(cd "$client_dir" && make)

# Check if the binaries are executable
if [[ -x "$server_dir/bin/server" && -x "$client_dir/bin/client" ]]; then
  # Open a new iTerm2 window, split it vertically, and run the server in one pane and the client in the other
  osascript <<EOF
tell application "iTerm"
  activate
  tell current window
    create tab with default profile
  end tell
  tell current session of current tab of current window
    write text "cd `pwd`/$server_dir/bin && ./server"
    set newSplit to (split vertically with default profile)
  end tell
  tell newSplit
    write text "cd `pwd`/$client_dir/bin && ./client"
  end tell
end tell
EOF

else
  echo "One or both binaries are not executable or do not exist"
fi
