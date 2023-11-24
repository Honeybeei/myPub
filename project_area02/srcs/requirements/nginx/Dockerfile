FROM debian:bullseye

RUN apt-get -y update && apt-get install -y nginx && apt-get install openssl -y
RUN mkdir -p /var/www/html
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Jungrang/O=42Seoul/OU=42Seoul/CN=seoyoo" -out /etc/ssl/certs/seoyoo.42.fr.crt -keyout /etc/ssl/private/seoyoo.42.fr.key
COPY ./conf/default /etc/nginx/sites-available/

ENTRYPOINT ["nginx", "-g", "daemon off;"]
