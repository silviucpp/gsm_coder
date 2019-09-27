
#include <erl_nif.h>
#include <math.h>
#include <string.h>
#include "gsm.h"

static ERL_NIF_TERM utf8_check_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary text_bin;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &text_bin) ) {
	    if( utf8_check_gsm7(text_bin.data, text_bin.size) ) {
		return enif_make_atom(env, "true");
	    }
	    else {
		return enif_make_atom(env, "false");
	    }
	}
    }

    return enif_make_badarg(env);
}

/*
static ERL_NIF_TERM sms_text_parts_number_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary text_bin;
    int len;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &text_bin) ) {
	    if( utf8_check_gsm7(text_bin.data, text_bin.size) ) {
		len = utf8_to_gsm7(text_bin.data, text_bin.size, NULL, 0);
		if( len > 160 ) {
		    return enif_make_int(env, ceil(len / 153.0));
		}
		else {
		    return enif_make_int(env, 1);
		}
	    }
	    else {
		len = utf8_to_ucs2(text_bin.data, text_bin.size, NULL);
		if( len > 70 ) {
		    return enif_make_int(env, ceil(len / 67.0));
		}
		else {
		    return enif_make_int(env, 1);
		}
	    }
	}
    }

    return enif_make_badarg(env);
}
*/

static ERL_NIF_TERM sms_text_parts_number_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary text_bin;
    int len;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &text_bin) ) {
	    if( utf8_check_gsm7(text_bin.data, text_bin.size) ) {
		len = utf8_to_gsm8(text_bin.data, text_bin.size, NULL);
		if( len > 160 ) {
		    return enif_make_int(env, ceil(len / 153.0));
		}
		else {
		    return enif_make_int(env, 1);
		}
	    }
	    else {
		len = utf8_to_ucs2(text_bin.data, text_bin.size, NULL);
		if( len > 70 ) {
		    return enif_make_int(env, ceil(len / 67.0));
		}
		else {
		    return enif_make_int(env, 1);
		}
	    }
	}
    }

    return enif_make_badarg(env);
}

static ERL_NIF_TERM utf8_to_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary src_bin, dst_bin;
    int len;
    bytes_t dst;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &src_bin) ) {
	    if( utf8_check_gsm7(src_bin.data, src_bin.size) ) {
		len = utf8_to_gsm7(src_bin.data, src_bin.size, NULL, 0);
		dst = enif_alloc(len);
		utf8_to_gsm7(src_bin.data, src_bin.size, dst, 0);
		enif_alloc_binary(len, &dst_bin);
		memcpy(dst_bin.data, dst, len);
		enif_free(dst);
		return enif_make_binary(env, &dst_bin);
	    }
	    else {
		return enif_make_badarg(env);
	    }
	}
    }

    return enif_make_badarg(env);
}

static ERL_NIF_TERM utf8_from_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary src_bin, dst_bin;
    int len;
    bytes_t dst;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &src_bin) ) {
	    len = utf8_from_gsm7(src_bin.data, 0, src_bin.size, NULL);
	    dst = enif_alloc(len);
	    utf8_from_gsm7(src_bin.data, 0, src_bin.size, dst);
	    enif_alloc_binary(len, &dst_bin);
	    memcpy(dst_bin.data, dst, len);
	    enif_free(dst);
	    return enif_make_binary(env, &dst_bin);
	}
    }

    return enif_make_badarg(env);
}

static ERL_NIF_TERM utf8_to_gsm8_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary src_bin, dst_bin;
    int len;
    bytes_t dst;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &src_bin) ) {
	    if( utf8_check_gsm7(src_bin.data, src_bin.size) ) {
		len = utf8_to_gsm8(src_bin.data, src_bin.size, NULL);
		dst = enif_alloc(len);
		utf8_to_gsm8(src_bin.data, src_bin.size, dst);
		enif_alloc_binary(len, &dst_bin);
		memcpy(dst_bin.data, dst, len);
		enif_free(dst);
		return enif_make_binary(env, &dst_bin);
	    }
	    else {
		return enif_make_badarg(env);
	    }
	}
    }

    return enif_make_badarg(env);
}

static ERL_NIF_TERM utf8_from_gsm8_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary src_bin, dst_bin;
    int len;
    bytes_t dst;

    if( argc == 1 ) {
	if( enif_inspect_iolist_as_binary(env, argv[0], &src_bin) ) {
	    len = utf8_from_gsm8(src_bin.data, src_bin.size, NULL);
	    dst = enif_alloc(len);
	    utf8_from_gsm8(src_bin.data, src_bin.size, dst);
	    enif_alloc_binary(len, &dst_bin);
	    memcpy(dst_bin.data, dst, len);
	    enif_free(dst);
	    return enif_make_binary(env, &dst_bin);
	}
    }

    return enif_make_badarg(env);
}

static ErlNifFunc nif_funcs[] = {
    {"utf8_check_gsm7", 1, utf8_check_gsm7_nif},
    {"sms_text_parts_number", 1, sms_text_parts_number_nif},
    {"utf8_to_gsm7", 1, utf8_to_gsm7_nif},
    {"utf8_from_gsm7", 1, utf8_from_gsm7_nif},
    {"utf8_to_gsm8", 1, utf8_to_gsm8_nif},
    {"utf8_from_gsm8", 1, utf8_from_gsm8_nif}
};

ERL_NIF_INIT(gsm_coder, nif_funcs, NULL, NULL, NULL, NULL)
