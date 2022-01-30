NNUE_EVAL

This tool drives an UCI engine in order to evaluate at fixed depth the EPDs extracted from the uncommented PGNs.
It uses PGN-EXTRACT to convert PGN files into TXT files.
The evaluated EPDs will be stored into PLAIN TEXT format.

example :

=> From an uncommented PGN file like this

[Event "EVENT"]
[Site "SITE"]
[Date "2021.01.23"]
[Round "1"]
[White "engine1"]
[Black "engine2"]
[Result "1/2-1/2"]

1. a2-a3 a7-a5 2. e2-e4 e7-e5 ...

=> pgn-extract will produce a TXT file like this

[Event "EVENT"]
[Site "SITE"]
[Date "2021.01.23"]
[Round "1"]
[White "engine1"]
[Black "engine2"]
[Result "1/2-1/2"]

a2a3 { rnbqkbnr/pppppppp/8/8/8/P7/1PPPPPPP/RNBQKBNR b KQkq - 0 1 } a7a5 { rnbqkbnr/1ppppppp/8/p7/8/P7/1PPPPPPP/RNBQKBNR w KQkq - 0 2 } e2e4 { rnbqkbnr/1ppppppp/8/p7/4P3/P7/1PPP1PPP/RNBQKBNR b KQkq - 0 2 } e7e5 { rnbqkbnr/1ppp1ppp/8/p3p3/4P3/P7/1PPP1PPP/RNBQKBNR w KQkq - 0 3 } ...

=> each evaluated EPD will be stored into a PLAIN TEXT file like this

fen rnbqkbnr/pppppppp/8/8/8/P7/1PPPPPPP/RNBQKBNR b KQkq - 0 1
move g8f6
score 10
ply 1
result 0
e
fen rnbqkbnr/1ppppppp/8/p7/8/P7/1PPPPPPP/RNBQKBNR w KQkq - 0 2
move e2e4
score 245
ply 2
result 0
e
fen rnbqkbnr/1ppppppp/8/p7/4P3/P7/1PPP1PPP/RNBQKBNR b KQkq - 0 2
move e7e5
score -123
ply 3
result 0
e
fen rnbqkbnr/1ppp1ppp/8/p3p3/4P3/P7/1PPP1PPP/RNBQKBNR w KQkq - 0 3
move g1f3
score 189
ply 4
result 0
e
...

=> At the end, you will obtain some files : 
- evaluation.log contains all the showed lines into the console
- pieces.txt contains the percents of the piece numbers of the EPDs

=> then we can convert this PLAIN TEXT file into a BIN file in order to train a NNUE net

Before to proceed, there are some prerequisites...

In the parent directory of your nnue_eval.exe file :

- create a new TXT file and rename it as <your_computer_name>.ini (ex : USER-PC.ini)
- edit it and set your preferences like these
engine = stockfish_pcnt.exe //name of your engine
pgnextract = pgn-extract.exe //path to your pgn-extract command
fixed_depth = 14 //the fixed depth which will be used to evaluate the EPDs
priorite = 64 //32 normal, 64 idle, 128 high, 256 realtime, 16384 below normal, 32768 above normal
detection = False //False if you want to evaluate all EPDs, True if you want to avoid duplicated EPDs

- create a new TXT file and rename it as <your_engine>.ini (ex : stockfish_pcnt.txt)
- edit it and set your engine's commands like these
setoption name Contempt value 0
setoption name SkipLoadingEval value true

- you should put all your PGN files into a subdirectory

ENJOY !

ps : if you want to avoid the duplicated EPDs inside the same game or between 2 or more games or even between several PGN files, you have to set detection = True.
In this case, all the EPDs will be hashed by a MD5 algorithm and the hashes will be stored in four MD5 files at the end.
Next time you will run this tool, it will reload the hashes from the four MD5 files and they will be updated at the end.
After 480 millions of evaluated EPDs with detection = True, these four MD5 files weigh about 12 GB.