#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RESET='\033[0m'

check_DB()
{
	while ! wp db check --allow-root;
	do
		echo "${RED}Database is installing... wait${RESET}"
		sleep 0.5s
	done
	echo "${GREEN}Database is connected${RESET}"
}

create_config()
{
	IS_EXIST=$(find /www -name "wp-config.php" | wc -l)
	if [ $IS_EXIST -eq 1 ]
	then
		echo "${GREEN}Wordpress config file exist!${RESET}"
	else
		echo "${RED}Create wordpress config file${RESET}"
		until wp config create --dbname=$DB_NAME \
					--dbuser=$MARIADB_USER \
					--dbpass=$MARIADB_PASSWORD \
					--dbhost=$DB_HOST \
					--allow-root;
		do
			echo "${RED}try again${RESET}"
		done
	fi
}

# wp download
wp core download --path=/www --allow-root
if [ $? -eq 0 ]
then
	# install
	echo "${RED}Wordpress is not installed. installing wordpress...${RESET}"
	# wp configuration
	rm -rf /www/wp-config-sample.php
	# create config file
	create_config
	# check database
	check_DB
	# wp install and create admin
	wp core install --url=$DOMAIN_NAME --title="Minjun's blog" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --path=/www --allow-root
else
	# already installed
	echo "${GREEN}Wordpress is already installed${RESET}"
	check_DB
fi

# Check User Count
USER_CNT=$(wp user list --field=ID --allow-root | wc -l)
if [ $USER_CNT -lt 2 ]
then
	# if user count less than 2
	echo "${RED}Create user...${RESET}"
	# wp user create (minjkim2)
	wp user create $USER_NAME $USER_EMAIL --role=editor --user_pass=$USER_PASS --path=/www --allow-root
else
	echo "${GREEN}There are already 2 users.${RESET}"
fi

# wp plugin update
wp plugin update --all --path=/www --allow-root

# php-fpm configuration
mv /tools/www.conf /etc/php/7.3/fpm/pool.d/www.conf
mv /tools/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf

# run php-fpm foreground
exec php-fpm7.3 -F
