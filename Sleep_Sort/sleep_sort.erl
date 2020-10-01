-module(sleep_sort).
-compile(export_all).

sorter(Num) ->
   timer:sleep(Num * 1000),
   io:format("~p~n", [Num]).

sort(Num_list) ->
   lists:foreach(fun (N) -> spawn_link(?MODULE, sorter, [N]) end, Num_list).


% Input:
%Eshell V5.10.4  (abort with ^G)
%1> c(sleep_sort).
%{ok,sleep_sort}
%2> sleep_sort:sort([2,35,56,32,44,43,5,6]).

% Output:
%ok
%2
%5
%6
%32
%35
%43
%44
%56
%3>
