COMPOSE_FILE=./srcs/docker-compose.yml
CONTAINERS = srcs-server srcs-wordpress srcs-database
IMAGES = srcs-server srcs-database srcs-wordpress
VOLUMES = srcs_data srcs_www
NETWORKS = srcs_intra_net

# docker-compose up
# volume create
up:
	docker-compose -f $(COMPOSE_FILE) up -d

# docker-compose down
down:
	docker-compose -f $(COMPOSE_FILE) down

# container ps
container_list:
	docker ps -a

# volume ls
volume_list:
	docker volume ls

# network ls
network_list:
	docker network ls

# clean & network volume image remove
fclean:
	$(MAKE) down
	docker image rm $(IMAGES)
	docker volume rm $(VOLUMES)
