-module(integrity_test_SUITE).

-compile(export_all).

all() -> [
    {group, gsm_coder_tests}
].

groups() -> [
    {gsm_coder_tests, [sequence], [
        gsm_coder_test_suite
    ]}
].

init_per_suite(Config) ->
    gsm_coder:start(),
    Config.

end_per_suite(_Config) ->
    gsm_coder:stop().

gsm_coder_test_suite(_Config) ->
    true = gsm_coder:utf8_check_gsm7(<<"abcdef">>),
    1 = gsm_coder:sms_text_parts_number(<<"abcdef">>),
    <<97,241,152,92,54,3>> = gsm_coder:utf8_to_gsm7(<<"abcdef">>),
    <<"abcdef">> = gsm_coder:utf8_from_gsm7(<<97,241,152,92,54,3>>),
    <<"abcdef">> = gsm_coder:utf8_to_gsm8(<<"abcdef">>),
    <<"abcdef">> = gsm_coder:utf8_from_gsm8(<<"abcdef">>).
