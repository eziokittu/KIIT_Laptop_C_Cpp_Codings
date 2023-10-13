A secure communication network has been compromised and the cyber security team must restore its security. The network, series, is represented as a series of nodes identified using lowercase English letters. The nodes must be disconnected in order to remove the threat. In a single operation, any number of adjacent nodes identified by the same character can be disconnected. Find the minimum number of operations required to disconnect all the nodes and secure the network.
Example
Suppose n=5 and series "aabbaa".
The minimum number of operations required to delete the entire series is 2.
Constraints

• 1 ≤ series ≤ 500

It is guaranteed that series contains. lowercase English letters only.

Function Description

Complete the function getMinOperations in the editor below.

getMinOperations has the following parameter:

string series: a series of nodes

Returns

int: the minimum number of operations required to delete the entire series 

Sample Input For Custom Testing



 series="abaca"


Sample Output

3

Explanation

It is optimal to delete the substrings "b" and "c" first in two operations to get the string "aaa" which can be deleted in the next operation.

Another Sample Test Case:-
Series: "abcddcba"
Sample Output: 4

Note : Function Signature is 
int getMinOperations(string series) 
Write the code in cpp