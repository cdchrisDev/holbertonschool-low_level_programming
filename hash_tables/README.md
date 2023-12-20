# This is the hash tables project

**What is a Hash Function?**<br />
a **hash function** is any function that can be used to map data of arbitrary size to fixed-size values, though there are some hash functions that support variable length output. The values returned by a hash function are called *Hash Values*, *Hash Codes*, *digest* or simply *hashes* the values are usually used to index a fixed-storage addressing.

**What is a Hash table?**<br />
Is a data structure that implements an associative array, also called a dictionary which is an abstract data type that maps keys to values. A Hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.
<br/>

**What makes a good hash function?**<br />
* The complexity of the hash tables depends on the different mathematical outputs that a function can return, so. The harder the equation, the better the hash table

* when hashing strings it's important to consider all characters – except when it's known in advance that the first three characters of all strings will be the same; considering these then is a waste.

* it is also important to generate a good spread over the problem space, i.e. all possible objects. *This means that when hashing numbers between 100 and 1050 it's no good to let the most significant digit play a big part in the hash because for ~ 90% of the objects, this digit will be 0. It's far more important to let the last three digits determine the hash.*
<br />

**What is a hast table, how do they work and how to use them?**<br />
A hash table is a *data structure* that is used to store keys/value pairs. It uses a hash function to compute an index into an array in which an element will be inserted or searched. By using a good hash function, hashing can work well.<br/>


**What is a collision and what are the main ways of dealing with collisions in the context of a hash table**<br />
When one or more hash values compete with a single hash table slot, collisions occur. To resolve this, the next available empty slot is assigned to the current hash value. The most common methods are open addressing, chaining, probabilistic hashing, perfect hashing and coalesced hashing technique.<br />

**What are the advantages and drawbacks of using hash tables**<br />
Hash tables offer efficient data storage and retrieval, but they come with some drawbacks. These include collision resolution, variable performance, space overhead, lack of ordered data, and dependency on a quality hash function. They are not ideal for range queries, and resizing can introduce overhead.<br />

**What are the advantages and drawbacks of using hash tables**
Hash tables offer efficient data storage and retrieval, but they come with some drawbacks. These include collision resolution, variable performance, space overhead, lack of ordered data, and dependency on a quality hash function. They are not ideal for range queries, and resizing can introduce overhead.<br />

**What are the most use cases?**<br />
Probably the most common use for hash tables is databases. To retrieve and increment through data in a database in a performant way, we need some way to identify it uniquely, and we need some way to index it<br />

