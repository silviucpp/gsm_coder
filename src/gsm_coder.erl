%%% Created : 11 Apr 2019 by Danil Onishchenko <onishchenko@svyazcom.ru>
%%% Improvements - Silviu Caragea <silviu.cpp@gmail.com>

-module(gsm_coder).

-define(NOT_LOADED, not_loaded(?LINE)).

-type reason() :: any().

-on_load(load_nif/0).

-export([
    utf8_check_gsm7/1,
    sms_text_parts_number/1,
    utf8_to_gsm7/1,
    utf8_from_gsm7/1,
    utf8_to_gsm8/1,
    utf8_from_gsm8/1
]).

-spec utf8_check_gsm7(binary()) ->
    boolean() | {error, reason()}.

utf8_check_gsm7(_Bin) ->
    ?NOT_LOADED.

-spec sms_text_parts_number(binary()) ->
    integer() | {error, reason()}.

sms_text_parts_number(_Bin) ->
    ?NOT_LOADED.

-spec utf8_to_gsm7(binary()) ->
    binary() | {error, reason()}.

utf8_to_gsm7(_Bin) ->
    ?NOT_LOADED.

-spec utf8_from_gsm7(binary()) ->
    binary() | {error, reason()}.

utf8_from_gsm7(_Bin) ->
    ?NOT_LOADED.

-spec utf8_to_gsm8(binary()) ->
    binary() | {error, reason()}.

utf8_to_gsm8(_Bin) ->
    ?NOT_LOADED.

-spec utf8_from_gsm8(binary()) ->
    binary() | {error, reason()}.

utf8_from_gsm8(_Bin) ->
    ?NOT_LOADED.

% internals

load_nif() ->
    ok = erlang:load_nif(get_priv_path(?MODULE), 0).

get_priv_path(File) ->
    case code:priv_dir(gsm_coder) of
        {error, bad_name} ->
            Ebin = filename:dirname(code:which(?MODULE)),
            filename:join([filename:dirname(Ebin), "priv", File]);
        Dir ->
            filename:join(Dir, File)
    end.

not_loaded(Line) ->
    erlang:nif_error({not_loaded, [{module, ?MODULE}, {line, Line}]}).
