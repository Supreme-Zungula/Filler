# Filler
Filler is a 42 or WeThinkCode_(RSA) that requires you to create a program competes against another program in placing given pieces or token on maps of varying sizes. The program that places the most pieces on the map before terminating is considered the winner.

Compiling the program
---------------------
Clone the repository
Run the make the command.
After running Make the should an executed name filler

Running the program
-------------------
write the following command on the same directory where the filler program is:
./filler_vm -p1 ./filler -p2 players/playername.filler -v -f maps/mapname
NOTE: Replace playername.filler and mapname with appropriate names respectively.
example:
./filler_vm -p1 ./filler -p2 players/abanlin.filler -v -f maps/map00

This will run the match between two players.
The flags -p1 and -p2 indicate which player your are.
-p1 means player 1 and you are represented by O on the map.
-p2 means player 2 and you are represented by X on the map.

At the end of the game X and O will have the number of pieces placed by each player.
The player with the highest number means you are the winner
