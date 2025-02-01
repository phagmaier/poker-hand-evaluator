# POKER HAND EVALUATOR

## DESCRIPTION
Takes in 7 cards (5 community and 2 of the players hand) and gives the hand strength. 
This wasn't meant to be a stand alone project it's written for my poker solver
but it works pretty well and is fast and simple enough that I figured I'd upload it. 
It's functionally a implimentation of the [Cactus Kev](http://suffe.cool/poker/evaluator.html) algo.
If you want to learn about the algorithm I'd read the link.



## File Table

| File | Descripton |
| --------- | --------------------- |
| [Card.cpp](hand_rank/src/Card.cpp) | Card logic |
| [main.cpp](hand_rank/src/main.cpp) | Shows a basic test of how to use the program |
| [Card.h](hand_rank/src/Card.h) | |
| [hand_evaluator.h](hand_rank/src/hand_evaluator.h) | |
| [make_dics.cpp](hand_rank/src/make_dics.cpp) | Turns the precomputed hand rankings in the data file into hash maps|
| [make_hands.cpp](make/hands/src/make_hands.cpp) | actually computes all the unique hands and stores them in data folder |
| [hand_evaluator.cpp](hand_rank/src/hand_evaluator.cpp) | evaluates the hand determines rank and can tell you which players hand is strongest |
| [make_dics.h](hand_rank/src/make_dics.h) |  |
| [Data](data) | where all the unique combos are stored in txt files |

## RESULTS/PERFORMANCE
When lazily checking the speed it appears that my evaluator can
evaluate 100k cards in around 0.0368641 seconds on my machine
(results may cary)

## HOW IT WORKS
I wanted to do everything from scratch so I very lazily 
wrote all unique 5 card combination of cards 
Once we have those we seperate them in to three files:
flushes.txt, straights.txt, pairs.txt
 the first two are self explanitory but the third contains all non flushes/straights (high cards-four of a kind) 
 Once we have our data we then use make_dics to generate hashmaps or dictionaries of all the combinations as 
well as all the possible configurations our 7 card poker hand can be in since storing all unique combos of 
7 cards hands would have probably been too big. This means we have to check all 21 possible combinations of 
our hands which is the most inefficient part of the algo but I couldn't think of a better way around it.
When evaluating we store our current best score and we update when iterating through the combos and getting each 
of their ranks. We first must check flush and straight since the highest possible ranking is a straight flush
and because our fluhses data contains straight flushes so when we hash into it we would have no way of determining 
what the best flush was (we check flushes by anding bits since each suit sets a single bit)
we then hash our flushes straights and pairs hash_map if we didn't get a straight flush and then compare scores
we use a constant which is the size of the number of unique values (for pairs it accumulates from high card up) and we 
deliniate what scores beat a flush/straight and then get our rank (this part is also inneficient and can be improved).
Also i forgot to mention we hash using a hash function where each of the 13 cards has a unique prime number associated 
with it and that's how we get the hash of our cards and are able to search our dictionaries

## IMPROVMENT
1. Could make it parallel with a few tweaks (not sure if that's best for my solver at the moment though)
2. More efficient comparisons 
3. Find a way to not have to do all 21 combos
4. Faster way to get the Rank of a pair


## HOW TO RUN
No dependies and I included a cmake file so all you have to do is:
1. Go into the build directory in the root directory 
2. type cmake .. && make && ./runme

## HELP
If you somehow stumble upon this and you want to contribute feel free to do so or 
just take the code and do whatever you want to it
