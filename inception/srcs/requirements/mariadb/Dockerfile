FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server procps && rm -rf /var/lib/apt/lists/*

RUN sed -i "s/127.0.0.1/0.0.0.0/g" /etc/mysql/mariadb.conf.d/50-server.cnf; \
	mkdir -p tools; \
	chown mysql:mysql /var/lib/mysql

WORKDIR /tools

COPY ./tools/run.sh .

RUN chmod +x run.sh

EXPOSE 3306

ENTRYPOINT ["./run.sh"]
