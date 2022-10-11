# Color
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

# Docker Components
COMPOSE_FILE = ./srcs/docker-compose.yml
IMAGES = nginx:42Seoul mariadb:42Seoul wordpress:42Seoul
VOLUMES = srcs_data srcs_www

# docker-compose up
up:
	@echo "$(GREEN)create directory...$(RESET)"
	@mkdir -p /home/minjkim2/www /home/minjkim2/data
	@echo "$(GREEN)docker-compose up...$(RESET)"
	@docker compose -f $(COMPOSE_FILE) up -d

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
	@docker image rm -f $(IMAGES)
	@echo "$(RED)cleanup volumes$(RESET)"
	@docker volume rm -f $(VOLUMES)
