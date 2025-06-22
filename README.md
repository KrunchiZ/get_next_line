# get_next_line

### Method 1: Fixed Length 2D Buffer Array
In method 1, a static fixed length 2D array is allocated to buffer to hold the string read from the file descriptors. It stores the leftover strings to be used again in subsequent get next line call. This method allows the user to not worry about having memory leaks if get next line was not called until EOF. However, it caps the maximum limits of readable bytes (BUFFER_SIZE).

### Method 2: Heap Buffer String Array
In method 2, buffer memory is allocated from the heap, allowing dynamic and flexible memory management. This method can take an arbitrary amount of BUFFER_SIZE because this method allocates memory only when necessary. However, this method mandates the user to call get next line until the EOF just so get next line can properly free all the malloc'ed strings properly to prevent memory leaks.
