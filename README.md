## Skip List

Skip list is a probabilistic data structure that is built upon the general idea of a linked list.  
It achieves all of the search, insert and delete with O(logn) time complexity.

This project includes search, insert and delete along with other utility functions like display, clear and reset. 

## Usage
I have made a make file for compiling. You can compile in command line:
~~~
$ make
$ ./a < sample.in 
~~~
To test the results. 

## Example

It accepts commands from stdin. For example:

```
p
```
At the start of the program would give:
~~~
-inf - inf
~~~
Where it indicates it starts from negative infinity (INT_MIN) to infinity (INT_MAX) 

&nbsp;

Commands such as inserting key-value pairs like:
~~~
i 30 11
i 5 11
i 1 0
i 71 14
i 90 18
i 201 22
p
~~~
Could give something like (Only keys will be displayed):
~~~
-inf ----------------------------- - inf
-inf - 1 ------------------------- - inf
-inf - 1 --------------- 90 ------ - inf
-inf - 1 - 5 ----------- 90 ------ - inf
-inf - 1 - 5 - 30 - 71 - 90 - 201  - inf
~~~
If the height is randomly chosen as 0, 1, 3, 0, 2, 0

&nbsp;

Deleting from the above object:
~~~
d 5
~~~
Would give:

~~~
-inf ------------------------- - inf
-inf - 1 --------------------- - inf
-inf - 1 ----------- 90 ------ - inf
-inf - 1 ----------- 90 ------ - inf
-inf - 1 - 30 - 71 - 90 - 201  - inf
~~~
