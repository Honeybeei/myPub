FROM debian:bullseye

RUN apt-get update -y 
RUN apt-get install php-fpm php-mysql -y
RUN apt-get install curl -y

COPY ./tools/script.sh /
COPY ./tools/wp-config.php /

EXPOSE 9000

ENTRYPOINT ["./script.sh" ]
