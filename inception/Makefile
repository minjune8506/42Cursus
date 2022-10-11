# Color
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

# Docker Components
COMPOSE_FILE=./srcs/docker-compose.yml
CONTAINERS = srcs-server srcs-wordpress srcs-database
IMAGES = srcs-server srcs-database srcs-wordpress
VOLUMES= srcs_data srcs_www

# docker-compose up
up:
	@echo "$(GREEN)docker compose up...$(RESET)"
	@echo "$(GREEN)create volume...$(RESET)"
	@mkdir -p /home/minjkim2/www /home/minjkim2/data
	@docker compose -f $(COMPOSE_FILE) up

# docker-compose down
down:
	@echo "$(RED)docker compose down...$(RESET)"
	@docker compose -f $(COMPOSE_FILE) down

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
	@echo "$(RED)cleanup images$(RESET)"
	@docker image rm $(IMAGES)
	@echo "$(RED)cleanup volumes$(RESET)"
	@docker volume rm $(VOLUMES)
