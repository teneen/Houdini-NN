NNUE_CLEAN

This tool loads the hashes from the four MD5 files (created by nnue_eval when detection = True).
Then it cleans the duplicated EPDs from the PLAIN TEXT files.
At the end, it updates the four MD5 files.

usual scenario :

step 1
we use nnue_eval with detection = true to evaluate a PGN file without duplicated EPDs
we get four MD5 files which contain the hashes of the evaluated EPDs and the PLAIN TEXT file

step 2
we use nnue_eval with detection = false to evaluate a new PGN file
the four MD5 files aren't updated and the new PLAIN TEXT file may contain duplicated EPDs

step 3
we use nnue_clean to clean the duplicated EPDs into the PLAIN TEXT file from step 2
we get four updated MD5 files which contain the hashes of the evaluated EPDs from step 1 + 2 and the PLAIN TEXT file from step 2 contains only "original" EPDs

ENJOY !

ps : the interest of using "nnue_eval with detection = false" is to share the time management of nnue_eval between several computers without copying/moving the four MD5 files each time.
Then, we only have to regroup all the PLAIN TEXT files and we can clean them in a row.
At the end, ours four MD5 files are updated.
