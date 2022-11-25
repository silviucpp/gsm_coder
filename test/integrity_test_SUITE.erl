-module(integrity_test_SUITE).

-include_lib("stdlib/include/assert.hrl").

-define(GSM_ALPHABET_UTF8, <<"@£$¥èéùìòÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞÆæßÉ!\"#¤%&'()*+,-./0123456789:;<=>?¡ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÑÜ§¿abcdefghijklmnopqrstuvwxyzäöñüà^{}\[~]|€"/utf8>>).

-compile(export_all).

all() -> [
    {group, gsm_coder_tests}
].

groups() -> [
    {gsm_coder_tests, [sequence], [
        basic_suite
    ]}
].

init_per_suite(Config) ->
    gsm_coder:start(),
    Config.

end_per_suite(_Config) ->
    gsm_coder:stop().

basic_suite(_Config) ->
    ?assertEqual(true, gsm_coder:utf8_check_gsm7(?GSM_ALPHABET_UTF8)),
    ?assertEqual(1, gsm_coder:sms_text_parts_number(?GSM_ALPHABET_UTF8)),
    ?assertEqual(<<97,241,152,92,54,3>>, gsm_coder:utf8_to_gsm7(<<"abcdef">>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_from_gsm7(<<97,241,152,92,54,3>>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_to_gsm8(<<"abcdef">>)),
    ?assertEqual(<<"abcdef">>, gsm_coder:utf8_from_gsm8(<<"abcdef">>)),
    ok.

