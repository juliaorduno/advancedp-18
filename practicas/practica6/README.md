# 6th Practice Analysis

This practice will be about building a library that will contain a Hash Table with the following:
```
key string = char *
value "cualquier cosa" => void *
```
The `void *` will allow us to control any variable type in `value`. However, on each `value` we will control an array for each index. The key will take us to a position on the HashTable that contains an array with collitions that we let us search through the array for the key and then, we will find the real value.

Using realloc will let us resize the HashTable automatically. Every time that the array gets full, it wil increment the Hash size by two and then rehash all the elements. Each array in the hash is going to have a size and an index, that meand that each time the index and size are equal, it will be resized.

We will implement the next functions:
`init();` starts a new Hash Table with null values.
`insert()` inserts a new element with a key and a value.
`get()` searchs a value in the hash.

To be continued...