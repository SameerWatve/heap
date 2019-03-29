# heap

K-ary heaps are a generalization of binary heap(K=2) in which each node have K children instead of 2. 

Implemented min-ordered heap, with functions for two of the typical heap operations, removeMin() and insertValue(). 

Each element of your heap will store a pair of integer values. The first value in each pair will be a
key that determines the heap ordering. The second will be an associated value that goes with that
key

Each input line represents a heap operation. If there are two integer values, that indicates an insertValue()
operation, with the key as the first value and the value that goes that key next. For inserts, the
program shouldn’t print anything.

If a line contains a -1, that indicates a removeMin() operation. For this, the program should remove
the minimum from the heap and print that pair to standard output.

Program maintains the count of heap key comparisons as it runs and returns this when terminates.
