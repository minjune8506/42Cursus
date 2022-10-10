FROM debian:buster

RUN apt-get update && \
	apt-get install -y php-fpm php-mysql wget curl mariadb-client && \
	rm -rf /var/lib/apt/lists/*

RUN mkdir -p tools && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	wp cli update

COPY ./config/www.conf /tools/www.conf
COPY ./config/php-fpm.conf /tools/php-fpm.conf
COPY ./tools/run.sh /tools/run.sh

RUN chmod +x /tools/run.sh

WORKDIR /www

EXPOSE 9000

ENTRYPOINT ["/tools/run.sh"]
