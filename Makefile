compile_nif:
	@make V=0 -C c_src -j 8

clean_nif:
	@make -C c_src clean
