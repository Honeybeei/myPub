#!/bin/bash

mkdir -p /var/www/html
cd /var/www/html

rm -rf *
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
chmod +x wp-cli.phar 

mv wp-cli.phar /usr/bin/wp

wp core download --locale=ko_KR --allow-root
rm wp-config-sample.php
mv /wp-config.php /var/www/html/wp-config.php

sed -i 's/database_name_here/'${DB_NAME}'/g' /var/www/html/wp-config.php
sed -i 's/username_here/'${ADMIN}'/g' /var/www/html/wp-config.php
sed -i 's/password_here/'${ADMIN_PW}'/g' /var/www/html/wp-config.php
sed -i 's/'localhost'/'${DB_HOST}'/g' /var/www/html/wp-config.php

wp core install --url=$DOMAIN_URL/ --title=$TITLE --admin_user=$ADMIN --admin_password=$ADMIN_PW --admin_email=$ADMIN_EMAIL --skip-email --allow-root
wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW --allow-root
wp plugin update --all --allow-root
wp redis enable --path=/var/www/html
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.4/fpm/pool.d/www.conf

mkdir /run/php

exec /usr/sbin/php-fpm7.4 -F
