# Huffman Coding Assignment – Preorder Traversal

## Description
This program builds a "Huffman Tree" from a string of distinct characters and their corresponding frequencies entered by the user. It generates Huffman codes for each character using "preorder traversal" and prints the codes space-separated. Huffman coding is a "greedy algorithm" used for data compression.


## Algorithm
1. Create leaf nodes for each character with its frequency.
  
2. Insert all nodes into a min-heap (priority queue).
  
3. While more than one node remains in the heap:
   - Extract the two nodes with the lowest frequencies.  
   - Merge them into a new parent node (`freq = sum of two`) and insert it back.  
   - Assign "left child = first extracted", "right child = second extracted". 
 
4. Perform preorder traversal starting at the root:
   - Go "left = append '0'", "right = append '1'".  
   - Record the code when a leaf node is reached.  

5. Print the "character codes" and "preorder codes" in a single line.

 

## How to Run
1. Compile the program:
g++ -std=c++17 huffman_preorder.cpp -o Huffman

2. Run the program:
./Huffman

3. Enter the inputs as prompted:
Enter the number of distinct characters: 6
Enter the characters (without spaces): abcdef
Enter the frequencies separated by spaces: 5 9 12 13 16 45

4. Sample Output:
Character codes:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111

Preorder codes (space-separated):
0   100   101   1100   1101   111

