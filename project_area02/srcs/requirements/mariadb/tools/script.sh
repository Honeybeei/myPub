#!/bin/bash

service mariadb start 

echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME} ;" > db1.sql
echo "CREATE USER IF NOT EXISTS '${ADMIN}'@'%' IDENTIFIED BY '${ADMIN_PW}' ;" >> db1.sql
echo "GRANT ALL PRIVILEGES ON wordpressDB.* TO '${ADMIN}'@'%' ;" >> db1.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${ADMIN_PW}' ;" >> db1.sql
echo "FLUSH PRIVILEGES;" >> db1.sql

mysql < db1.sql

kill $(cat /var/run/mysqld/mysqld.pid)

exec mysqld
