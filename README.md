[![Build Status](https://travis-ci.com/silviucpp/gsm_coder.svg?branch=master)](https://travis-ci.com/github/silviucpp/gsm_coder)
[![GitHub](https://img.shields.io/github/license/silviucpp/gsm_coder)](https://github.com/silviucpp/gsm_coder/blob/master/LICENSE)
[![Hex.pm](https://img.shields.io/hexpm/v/gsm_coder)](https://hex.pm/packages/gsm_coder)

A GSM 7/8 character strings encoder/decoder for Erlang based on the implementation from [Android Open Source Project][1].

### Getting started:

##### Integration

The application is compatible with both `rebar` or `rebar3`. Add `gsm_coder` as a rebar dependency to your project:

```
{deps, [
  {gsm_coder, ".*", {git, "https://github.com/silviucpp/gsm_coder.git", "master"}},
}.
```

##### API
```erl
application:start(gsm_coder).
ok

gsm_coder:utf8_check_gsm7(<<"abcdef">>).
true

gsm_coder:sms_text_parts_number(<<"abcdef">>).
1

gsm_coder:utf8_to_gsm7(<<"abcdef">>).
<<97,241,152,92,54,3>>

gsm_coder:utf8_from_gsm7(<<97,241,152,92,54,3>>).
<<"abcdef">>

gsm_coder:utf8_to_gsm8(<<"abcdef">>).            
<<"abcdef">>

gsm_coder:utf8_from_gsm8(<<"abcdef">>).
<<"abcdef">>
```

### Tests

In order to run the tests just use `rebar3 ct` from project root.

[1]: https://android.googlesource.com/platform/external/qemu.git/+/refs/heads/master/telephony/gsm.h