gsm_coder - GSM 7/8 character strings encoder/decoder for Erlang
==============================================================

It's a GSM 7/8 character strings encoder/decoder for Erlang based on the implementation from Android Open Source Project - https://source.android.com/

Usage
-----
    1> application:start(gsm_coder).
    ok
    2> gsm_coder:utf8_check_gsm7(<<"abcdef">>).
    true
    3> gsm_coder:sms_text_parts_number(<<"abcdef">>).
    1
    4> gsm_coder:utf8_to_gsm7(<<"abcdef">>).
    <<97,241,152,92,54,3>>
    5> gsm_coder:utf8_from_gsm7(<<97,241,152,92,54,3>>).
    <<"abcdef">>
    6> gsm_coder:utf8_to_gsm8(<<"abcdef">>).            
    <<"abcdef">>
    7> gsm_coder:utf8_from_gsm8(<<"abcdef">>).
    <<"abcdef">>

