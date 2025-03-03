-module(integrity_test).

-include_lib("eunit/include/eunit.hrl").

-define(GSM_ALPHABET_UTF8, <<"@£$¥èéùìòÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞÆæßÉ!\"#¤%&'()*+,-./0123456789:;<=>?¡ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÑÜ§¿abcdefghijklmnopqrstuvwxyzäöñüà^{}\[~]|€"/utf8>>).

basic_suite_test() ->
    ?assertEqual(true, gsm_coder:utf8_check_gsm7(?GSM_ALPHABET_UTF8)),
    ?assertEqual(1, gsm_coder:sms_text_parts_number(?GSM_ALPHABET_UTF8)),
    ?assertEqual(<<97,241,152,92,54,3>>, gsm_coder:utf8_to_gsm7(<<"abcdef">>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_from_gsm7(<<97,241,152,92,54,3>>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_to_gsm8(<<"abcdef">>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_from_gsm8(<<"abcdef">>)),
    ok.

