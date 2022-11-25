#include "gsm_coder.h"
#include "nif_utils.h"
#include "macros.h"
#include "gsm.h"

#include <math.h>
#include <string.h>
#include <memory>

static const char kAtomError[] = "error";
static const char kAtomBadArg[] = "badarg";
static const char kAtomTrue[] = "true";
static const char kAtomFalse[] = "false";

atoms ATOMS;

int on_nif_load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info)
{
    UNUSED(load_info);

    ATOMS.atomError = make_atom(env, kAtomError);
    ATOMS.atomBadArg = make_atom(env, kAtomBadArg);
    ATOMS.atomTrue = make_atom(env, kAtomTrue);
    ATOMS.atomFalse = make_atom(env, kAtomFalse);

    *priv_data = nullptr;
    return 0;
}

void on_nif_unload(ErlNifEnv* env, void* priv_data)
{
    UNUSED(env);
    UNUSED(priv_data);
}

static ERL_NIF_TERM utf8_check_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary text_bin;

	if(!enif_inspect_binary(env, argv[0], &text_bin))
	    return make_badarg(env);

    if(utf8_check_gsm7(text_bin.data, text_bin.size))
        return ATOMS.atomTrue;
    else
        return ATOMS.atomFalse;
}

static ERL_NIF_TERM sms_text_parts_number_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary text_bin;

    if(!enif_inspect_binary(env, argv[0], &text_bin))
	    return make_badarg(env);

    if(utf8_check_gsm7(text_bin.data, text_bin.size))
    {
		int len = utf8_to_gsm8(text_bin.data, text_bin.size, NULL);

		if(len > 160)
		    return enif_make_int(env, ceil(len/153.0));
	}
	else
	{
	    int len = utf8_to_ucs2(text_bin.data, text_bin.size, NULL);

	    if(len > 70)
            return enif_make_int(env, ceil(len/67.0));
	}

    return enif_make_int(env, 1);
}

static ERL_NIF_TERM utf8_to_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary src_bin;

    if(!enif_inspect_binary(env, argv[0], &src_bin))
        return make_badarg(env);

    if(!utf8_check_gsm7(src_bin.data, src_bin.size))
        return make_badarg(env);

    int out_buffer_size = utf8_to_gsm7(src_bin.data, src_bin.size, NULL, 0);
    std::unique_ptr<byte_t[]> out_buffer(new byte_t[out_buffer_size]);
    utf8_to_gsm7(src_bin.data, src_bin.size, out_buffer.get(), 0);
    return make_binary(env, out_buffer.get(), out_buffer_size);
}

static ERL_NIF_TERM utf8_from_gsm7_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary src_bin;

    if(!enif_inspect_binary(env, argv[0], &src_bin))
        return make_badarg(env);

    int out_buffer_size = utf8_from_gsm7(src_bin.data, 0, src_bin.size, NULL);
    std::unique_ptr<byte_t[]> out_buffer(new byte_t[out_buffer_size]);
    utf8_from_gsm7(src_bin.data, 0, src_bin.size, out_buffer.get());
    return make_binary(env, out_buffer.get(), out_buffer_size);
}

static ERL_NIF_TERM utf8_to_gsm8_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary src_bin;

    if(!enif_inspect_binary(env, argv[0], &src_bin))
        return make_badarg(env);

    if(!utf8_check_gsm7(src_bin.data, src_bin.size))
        return make_badarg(env);

    int out_buffer_size = utf8_to_gsm8(src_bin.data, src_bin.size, NULL);
    std::unique_ptr<byte_t[]> out_buffer(new byte_t[out_buffer_size]);
    utf8_to_gsm8(src_bin.data, src_bin.size, out_buffer.get());
    return make_binary(env, out_buffer.get(), out_buffer_size);
}

static ERL_NIF_TERM utf8_from_gsm8_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);
    ErlNifBinary src_bin;

    if(!enif_inspect_binary(env, argv[0], &src_bin))
        return make_badarg(env);

    int out_buffer_size = utf8_from_gsm8(src_bin.data, src_bin.size, NULL);
    std::unique_ptr<byte_t[]> out_buffer(new byte_t[out_buffer_size]);
    utf8_from_gsm8(src_bin.data, src_bin.size, out_buffer.get());
    return make_binary(env, out_buffer.get(), out_buffer_size);
}

static ErlNifFunc nif_funcs[] = {
    {"utf8_check_gsm7", 1, utf8_check_gsm7_nif},
    {"sms_text_parts_number", 1, sms_text_parts_number_nif},
    {"utf8_to_gsm7", 1, utf8_to_gsm7_nif},
    {"utf8_from_gsm7", 1, utf8_from_gsm7_nif},
    {"utf8_to_gsm8", 1, utf8_to_gsm8_nif},
    {"utf8_from_gsm8", 1, utf8_from_gsm8_nif}
};

ERL_NIF_INIT(gsm_coder, nif_funcs, on_nif_load, NULL, NULL, on_nif_unload);
