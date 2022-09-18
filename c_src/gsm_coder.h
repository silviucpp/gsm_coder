#ifndef C_SRC_GSM_CODER_H_
#define C_SRC_GSM_CODER_H_

#include "erl_nif.h"

struct atoms
{
    ERL_NIF_TERM atomError;
    ERL_NIF_TERM atomBadArg;
    ERL_NIF_TERM atomTrue;
    ERL_NIF_TERM atomFalse;
};

extern atoms ATOMS;

#endif  // C_SRC_GSM_CODER_H_

