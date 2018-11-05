All you need is a C++14 compatible C++ compiler like GCC 4.9 (or newer) or Clang 3.6 (or newer). Additionally this course uses the FunctionalPlus library. You can find it (including install instructions) on [github/Dobiasd/FunctionalPlus](https://github.com/Dobiasd/FunctionalPlus). After a successful install you are ready to go.

If you do not encounter any problems with this, you can skip the rest of this lecture. Otherwise: here is a step-by-step guide to install everything you need on Ubuntu (or Linux Mint).

First, install c++, clang and cmake.

```
sudo apt install build-essential g++ clang cmake
```

You can check the version numbers on your system like so:

```
gcc --version
clang --version
```

```
git clone https://github.com/Dobiasd/FunctionalPlus
cd FunctionalPlus
mkdir build
cd build
cmake ..
sudo make install
```

To verify that everything went fine, copy this hello-world code into a new file named `fplus_test.cpp`

```
#include <fplus/fplus.hpp>
int main()
{
    std::cout << fplus::show(42) << endl;
}
```

compile it:
```
clang++ -std=c++14 fplus_test.cpp -o fplus_test
```

and run it:
```
./fplus_test
```

If there are no errors and you see a `42` in your terminal, fplus was installed correctly.