# MERGE SORT VS COUNTING SORT
Merge Sort is a sorting algorithm based on the divide and conquer paradigm. This type of approach involves between steps at each level of recursion:
a. Divide: the problem is divided into a number of subproblems
b. Impera: Subproblems are solved recursively.
c. Combine: The solutions of the subproblems are combined to generate the solution of the original problem.
The Merge Sort algorithm works as follows:
Divide: divides the sequence of the n elements to be sorted into two subsequences of n / 2 elements each.
Impera: sorts the two subsequences recursively using the merge sort algorithm
Combine: merges the two ordered subsequences to generate the ordered sequence.

The merge sort algorithm is a sorting algorithm based on the comparison between elements. For this type of algorithm, in the worst case, omega (nlgn) comparisons are required to order n elements. However, there are some algorithms, not based on comparison, which require linear time. An algorithm of this type is Counting Sort. It assumes that the elements to be sorted are integers between 0 and k.
• For each integer i between 0 and k, we count how many elements equal to i there are in the vector to be sorted
• For each integer i between 0 and k, determine how many elements less than or equal to i there are in the vector to be sorted
• This indicates which position each element should be in
Counting sort uses two support vectors: B, of length n, which keeps the ordered values; C, of length k + 1, which indicates the occurrences of each value between 0 and k.
The execution time is theta (n + k). In practice, counting sort is used when k = O (n). In this case, the execution time is theta (n). Furthermore, it is a stable algorithm, that is, elements of equal value occur in the result vector in the same order as they are in the starting vector.


