#!/bin/sh

cat << EOF > config.sql
CREATE DATABASE IF NOT EXISTS $DB_NAME;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';
FLUSH PRIVILEGES;
EOF

service mysql start && mysql < config.sql && sleep 2 && service mysql stop && mysqld_safe
