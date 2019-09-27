%%%-------------------------------------------------------------------
%%% @author Danil Onishchenko <onishchenko@svyazcom.ru>
%%% @doc
%%%
%%% @end
%%% Created : 11 Apr 2019 by Danil Onishchenko <onishchenko@svyazcom.ru>
%%%-------------------------------------------------------------------
-module(gsm_coder).

%% API
-export([utf8_check_gsm7/1, sms_text_parts_number/1,
    utf8_to_gsm7/1, utf8_from_gsm7/1,
    utf8_to_gsm8/1, utf8_from_gsm8/1]).
-on_load(init/0).

%%%===================================================================
%%% API
%%%===================================================================
utf8_check_gsm7(_) ->
    exit(nif_library_not_loaded).

sms_text_parts_number(_) ->
    exit(nif_library_not_loaded).

utf8_to_gsm7(_) ->
    exit(nif_library_not_loaded).

utf8_from_gsm7(_) ->
    exit(nif_library_not_loaded).

utf8_to_gsm8(_) ->
    exit(nif_library_not_loaded).

utf8_from_gsm8(_) ->
    exit(nif_library_not_loaded).

init() ->
    PrivDir = case code:priv_dir(?MODULE) of
    		  {error, _} ->
    		      EbinDir = filename:dirname(code:which(?MODULE)),
    		      AppPath = filename:dirname(EbinDir),
    		      filename:join(AppPath, "priv");
    		  Path ->
    		      Path
    	      end,
    ok = erlang:load_nif(filename:join(PrivDir, "gsm_coder"), 0).
    %% ok = erlang:load_nif("./gsm_coder", 0).

%%--------------------------------------------------------------------
%% @doc
%% @spec
%% @end
%%--------------------------------------------------------------------

%%%===================================================================
%%% Internal functions
%%%===================================================================
