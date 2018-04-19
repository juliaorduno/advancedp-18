# Kata6: Shadows of the Knight - Episode 1

## Contexto
Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

## Input
- flight_length (minutes), integer.
- movie_lengths (minutes), array of integers

## Output
- Returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

## Constraints
- Assume your users will watch exactly two movies
- Don't make your users watch the same movie twice
- Optimize for runtime over memory

## Breakdown
It's not necessary to process the entire array, knowing if there are two movies equal to the flight_length. Hence, storing the numbers and the difference in a hash table (movie_length i, fligh_length - movie_length i). While processing the array, you need to see if the hash table contains the correct value or not.

## Solution
I read the array, on each loop, using the hash table implemented in class, first I check if the hash table contains the key pairValue (fligh_length - movie_length i), if it does, the loop breaks and returns true. Otherwise, it checks if the table contains the key movie_length i, if it doesn't have it, it stores the pair (movie_length i, fligh_length - movie_length i).

If n equals the number of movie_lengths, the runtime is O(n) in the worst case. The best case can reach a complexity of O(2).
The complexity in memory is O(n).

