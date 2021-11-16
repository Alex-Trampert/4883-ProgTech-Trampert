# ***TREE SUMMING - 112***

               *empty tree ::= ()* <br>
               *tree ::= empty tree | (integer tree tree)*<br>
The tree diagrammed above is represented by the expression<br>
               *(5 (4 (11 (7 () ()) (2 () ()) ) ()) (8 (13 () ()) (4 () (1 () ()) ) ) )*<br>
Note that with this formulation all leaves of a tree are of the form<br>
               *(integer () () )*<br>
Since an empty tree has no root-to-leaf paths, any query as to whether a path exists whose sum is<br>
a specified integer in an empty tree must be answered negatively.<br>

### ***Input*** <br>
The input consists of a sequence of test cases in the form of integer/tree pairs. Each test case consists<br>
of an integer followed by one or more spaces followed by a binary tree formatted as an S-expression<br>
as described above. All binary tree S-expressions will be valid, but expressions may be spread over<br>
several lines and may contain spaces. There will be one or more test cases in an input file, and input<br>
is terminated by end-of-file.<br>

### ***Output*** <br>
There should be one line of output for each test case (integer/tree pair) in the input file. For each<br>
pair I, T (I represents the integer, T represents the tree) the output is the string ‘yes’ if there is a<br>
root-to-leaf path in T whose sum is I and ‘no’ if there is no path in T whose sum is I.<br>

--------------------

*This folder contains all source files, input files, display banners, and informational PDF's<br>
that were used to solve and complete P112 on the Online Judge website.*
