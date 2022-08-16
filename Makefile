CONTAINER_NAME=axxonsoft_counter

## pre_build: actualize all submodules before build actual project
pre_build:
	@echo "[pre_build] Actualize git submodules"
	git submodule init
	git submodule update
	@echo "[pre_build] Done!"

## build: build docker container with application
build:
	@echo "[build] run docker build ..."
	docker build -t $(CONTAINER_NAME) .
	@echo "[build] Done!"
