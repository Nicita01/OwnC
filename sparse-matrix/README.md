# sparse matrix simulator

This program implements an optimal way of storing data from a sparse matrix. 

### How it works
If the numbers in the matrix are staggered, starting with the first one, and there are zeros at the neighboring positions, there is no sense in storing the data in the usual matrix. Because there will be significant redundancy in the data. Therefore, in this program, the data is stored in an array. The user thinks that he is working with the matrix. However, this array intercept all calls, the results of which are similar to the operation of the array.

### How uou can use it
To get started, run the index.c. You will immediately be asked to enter the vertical dimension of the matrix, that is, the number of columns. The number of rows can be unlimited. You can add data to any position whose indices are simultaneously paired, or simultaneously unpaired. /
To add an element to a position (i, j), write **/put**, then follow the directions. This command also replaces already existing values ​​with new ones. If you add an element to a string that does not exist, it will be created, and all elements from the last nonzero to the current one will be filled with zeros.Since you can not add data to positions whose indices have different pairs, then when you try, for example, to write a number in position (3, 2), you get an error and the data will not be written.
To display the values ​​of a particular item, type **/get** and follow the instructions. To print the entire array, type **/print**.
To exit the application, type **/exit**