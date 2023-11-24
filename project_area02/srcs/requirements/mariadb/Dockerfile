FROM debian:bullseye

RUN apt-get update -y
RUN apt-get install -y mariadb-server
# RUN apt-get install -y mariadb-client

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/script.sh /

ENTRYPOINT ["./script.sh"]