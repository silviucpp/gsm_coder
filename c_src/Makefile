
PROJECT_NIF_NAME=gsm_coder

include nif.mk

ifeq ($(UNAME_SYS), darwin)
	LDFLAGS += -framework CoreFoundation

	LDFLAGS +=  -Wl,-U,_enif_make_existing_atom \
	            -Wl,-U,_enif_make_atom \
	            -Wl,-U,_enif_make_new_binary \
	            -Wl,-U,_enif_make_tuple2 \
	            -Wl,-U,_enif_inspect_iolist_as_binary \
	            -Wl,-U,_enif_make_int
endif

CXXFLAGS += -DNDEBUG -g -Wextra -Werror -Wno-missing-field-initializers -fno-strict-aliasing -fno-exceptions -fno-rtti -std=c++11
LDFLAGS += -lstdc++
