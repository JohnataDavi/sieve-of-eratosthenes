<div align="center">

## Sieve of Eratosthenes

---

C++ implementation of the eratosthenes sieve using **control and data parallelism**.
<br/>
</div>

<div style="text-align: justify; text-justify: inter-word;">
Sieve of Eratosthenes is a simple and ancient algorithm used to find the prime numbers up to any given limit. It is one of the most efficient ways to find small prime numbers.

For a given upper limit nn the algorithm works by iteratively marking the multiples of primes as composite, starting from 2. Once all multiples of 2 have been marked composite, the muliples of next prime, ie 3 are marked composite. This process continues until p ≤ √n where p is a prime number.
</div>

<p align="center"> 
  <a href="https://github.com/JohnataDavi/binary-tree" target="_blank"><img alt="sieve-of-eratosthenes" height=300" src="https://user-images.githubusercontent.com/26368939/122655031-c7bd5000-d125-11eb-82ec-9a4eb3781087.gif"></a><br>
  
  Algorithm steps for primes below 121.

</p>

<div align="center">

## Requirements
</div>

* C++ 14 or later
* OpenMp
* Optional:
  * Linux

```PowerShell
## CMakeLists 
cmake_minimum_required(VERSION 3.17)
project(SieveEratosthenes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")
add_executable(SieveEratosthenes your_file.cpp)
```

<div align="center">

## Contributing
</div>
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.


<div align="center">
<br>

## [License](https://choosealicense.com/licenses/mit/)
</div>
