NNUE_EXTRACT

This tool only extracts the data from the commented PGNs.
It uses PGN-EXTRACT to convert PGN files into TXT files.
The extracted data will be stored into PLAIN TEXT format.

example :

=> From a commented PGN file like this (fishtest-like)

[Event "EVENT"]
[Site "SITE"]
[Date "2021.01.24"]
[Round "1"]
[White "engine1"]
[Black "engine2"]
[Result "1-0"]
[FEN "rnbqkbnr/ppppp1p1/8/5p1p/8/P4N2/1PPPPPPP/RNBQKB1R w KQkq -"]

1. d4 { +1.86/18 3.3s } 1... e6 { -1.41/19 3.2s } 2. c4 { +1.88/19 2.8s } 2... c5 { -1.35/18 0.75s } ...

=> pgn-extract will produce a TXT file like this

[Event "EVENT"]
[Site "SITE"]
[Date "2021.01.24"]
[Round "1"]
[White "engine1"]
[Black "engine2"]
[Result "1-0"]
[FEN "rnbqkbnr/ppppp1p1/8/5p1p/8/P4N2/1PPPPPPP/RNBQKB1R w KQkq -"]

d2d4 { +1.86/18 3.3s } { rnbqkbnr/ppppp1p1/8/5p1p/3P4/P4N2/1PP1PPPP/RNBQKB1R b KQkq - 0 1 } e7e6 { -1.41/19 3.2s } { rnbqkbnr/pppp2p1/4p3/5p1p/3P4/P4N2/1PP1PPPP/RNBQKB1R w KQkq - 0 2 } c2c4 { +1.88/19 2.8s } { rnbqkbnr/pppp2p1/4p3/5p1p/2PP4/P4N2/1P2PPPP/RNBQKB1R b KQkq - 0 2 } c7c5 { -1.35/18 0.75s } { rnbqkbnr/pp1p2p1/4p3/2p2p1p/2PP4/P4N2/1P2PPPP/RNBQKB1R w KQkq - 0 3 } ...

=> each extracted data will be stored into a PLAIN TEXT file like this

fen rnbqkbnr/ppppp1p1/8/5p1p/3P4/P4N2/1PP1PPPP/RNBQKB1R b KQkq - 0 1
move e7e6
score 293
ply 1
result -1
e
fen rnbqkbnr/pppp2p1/4p3/5p1p/3P4/P4N2/1PP1PPPP/RNBQKB1R w KQkq - 0 2
move c2c4
score 391
ply 2
result 1
e
fen rnbqkbnr/pppp2p1/4p3/5p1p/2PP4/P4N2/1P2PPPP/RNBQKB1R b KQkq - 0 2
move c7c5
score 281
ply 3
result -1
e
...

The scores are multiplied by 208 to match the pawn's value in NNUE/SHOGI.
This tool keeps only the extracted data where the data's depth is >= min_depth.
This tool always avoid the duplicated EPDs.

=> At the end, you will obtain some files : 
- extraction.log contains all the showed lines into the console
- pieces.txt contains the percents of the piece numbers of the EPDs
- profondeurs.txt contains the percents of the depths of the data

=> then we can convert this PLAIN TEXT file into a BIN file in order to train a NNUE net

Before to proceed, there are some prerequisites...

In the parent directory of your nnue_eval.exe file :

- create a new TXT file and rename it as <your_computer_name>.ini (ex : USER-PC.ini)
- edit it and set your preferences like these
pgnextract = pgn-extract.exe //path to your pgn-extract command
mindepth = 14 //the fixed depth which will be used to evaluate the EPDs
priorite = 64 //32 normal, 64 idle, 128 high, 256 realtime, 16384 below normal, 32768 above normal

- you should put all your PGN files into a subdirectory

ps : some PGNs files contain scores from "side to move" and others from "white pov".
At the beginning, this tool will ask you about it.
