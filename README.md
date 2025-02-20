
# List vs Vector: Performance Benchmark

This program benchmarks the performance of inserting and removing elements in two different containers: `std::vector` and `std::list`. It compares the total time taken to insert and remove `N` elements into/from each container, and calculates the difference in performance between the two containers.

## Description

The program performs the following operations:

1. **Vector Insertion and Removal**: Measures the time to insert and remove `N` elements in a `std::vector`.
2. **List Insertion and Removal**: Measures the time to insert and remove `N` elements in a `std::list`.
3. **Time Comparison**: Calculates and displays the difference in total durations between the insertion and removal operations for both containers.

### Time Metrics

- The program uses `std::chrono::high_resolution_clock` to measure the time taken for each operation (insertion and removal).
- The durations are displayed in seconds.

### Benchmark Output

The program will output:

- The time taken for vector insertion and removal for `N` elements.
- The time taken for list insertion and removal for `N` elements.
- The difference in total time between the list and vector operations in seconds.


### Functions Used:
- `vectorInsert(v, N, gen)`: Inserts `N` elements into the `std::vector` container `v`.
- `vectorRemove(v, N, gen)`: Removes `N` elements from the `std::vector` container `v`.
- `listInsert(l, N, gen)`: Inserts `N` elements into the `std::list` container `l`.
- `listRemove(l, N, gen)`: Removes `N` elements from the `std::list` container `l`.

## Requirements

- C++11 or later is required for compiling due to the use of `std::chrono`.
- A C++ compiler such as GCC or Clang is needed to compile the program.
- The code assumes the `vectorInsert`, `vectorRemove`, `listInsert`, and `listRemove` functions are defined elsewhere and handle the actual insertion and removal of elements.

## Compilation and Execution

### Build & Run

Clone the repository:

```bash
git clone https://github.com/marybadalyan/listvsvector.git
```

Navigate to the directory:

```bash
cd listvsvector
```

### Compilation Command

To compile the program, use the following command (ensure you replace `listvsvector.cpp` with your actual source file name, if different):

```bash
g++ -std=c++17 -O2 linearSearchInsertRemove.cpp -o main
```

- `-std=c++17` ensures that you're using the C++17 standard (or use `-std=c++11` for C++11).
- `-O2` enables optimization to improve the performance of the program.

### Run the Program

After compiling, you can run the program with:

```bash
./main
```
## Performance Benchmark


```
Performance Difference for 50000 elements in vector and list:
-------------
Vector:
-------------
Insertion:                | 223 ms
Deletion:                 | 730 ms
Total:                    | 953 ms

List:
-------------
Insertion:                | 4116 ms
Deletion:                 | 3836 ms
Total:                    | 7952 ms

Performance Difference:   | 6999 ms
```
**Conclusion:**  
The Vector implementation is significantly faster than the List implementation, with a performance difference of **6999 ms**.




## Conclusion

This program allows for a quick performance comparison between two commonly used containers, `std::vector` and `std::list`. You can adjust the value of `N` to test with different amounts of data and observe how each container performs in terms of insertion and removal operations.
