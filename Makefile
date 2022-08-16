CONTAINER_NAME=axxonsoft_counter

## COLORS
NO_COLOR=\033[0m]
CYAN=\033[0;36m
GREEN=\033[32m
UNDER=\033[4m
BOLD=\033[1m

## pre_build: actualize all submodules before build actual project
pre_build:
	@echo "${CYAN}[pre_build]\t->\tActualize git submodules${NO_COLOR}"
	git submodule init
	git submodule update
	@echo "${CYAN}[pre_build]\t<-\tDone!${NO_COLOR}"

## build: build docker container with application
build_app:
	@echo "${CYAN}[build_app]\t->\trun docker build${NO_COLOR}"
	docker build -t $(CONTAINER_NAME) .
	@echo "${CYAN}[build_app]\t<-\tDone!${NO_COLOR}"

# run_app: run application
run_app:
	@echo "${CYAN}[run_app]\t->\trun docker container${GREEN}${UNDER}${BOLD}"
	@docker run --rm \
	-v $(input):/docker_input_dir \
	$(CONTAINER_NAME) \
	--input=/docker_input_dir
	@echo "${CYAN}[build_app]\t<-\tDone!${NO_COLOR}"
