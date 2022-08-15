## pre_build: actualize all submodules before build actual project
pre_build:
	@echo "[pre_build] Actualize git submodules"
	git submodule init
	git submodule update
	@echo "[pre_build] Done!"
