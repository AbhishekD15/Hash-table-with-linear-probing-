## Hash-table-with-linear-probing

We will implement a hastable wheere the keys are lower-case English words (e.g., apple,pear). The length of a key is at most 10. The hash function is "last character”. That is, the hash value of apple should be e, and the hash value of pear should be r. Our hash table contains exactly 26 slots (hash value a to hash value z). The total number of English words/keys you need to deal with is at most 26, so the table is never too small.

**Searching** 
Given a key, we will take its last character as the hash value. First try the corre- sponding table slot, if the objective key is there, then you have found it. If the corresponding slot is never used, terminate because we are certain that the objective is not in the table. If the slot is occupied but it’s not the objective,then we move on to the next slot (may need to wrap around the table if the current slot is the last one). We will keep trying until we either find the key or are certain that the key does not exist in the table.

**Insertion**
We will first perform searching to ensure that the key does not exist. If it already exists, then we will do nothing. If it does not, we will take the last character of a key as the hash value. If the corresponding table slot is not occupied , we will put the key there (the slot is now occupied). If the corresponding slot is already occupied,we will try the next slot and repeat trying until we find an unoccupied slot.

**Deletion** 
Given a key,we will use the searching process to locate its slot. (If the key is not in the table, then we will do nothing.) Once we find the key, we will change the slot status. We will start our program by initializing an empty hash table. Our program takes one line as input. The input line contains n “modification moves” separated by spaces (1 ≤ n ≤ 26). 

The available modification moves are:

- **AWord** (Character A followed by a lower-case English word of length at most 10): Aapple means insert key apple into the hash table. If apple is already in the table, do nothing.
- **DWord** (Character D followed by a lower-case English word of length at most 10): Dapple means delete key apple from the hash table. If apple is not in the tree, do nothing.

**Compile**

>g++ -std=c11 -o main.out -O2 -Wall main1.cpp.
