# Programming Abstractions in C++

## Exercises from the book "Programming Abstractions in C++" by Eric S Roberts (2012)

**Programming Abstractions in C++* has been the reader for Stanford CS106B since 2002.**

- Classic [YouTube lectures](https://www.youtube.com/playlist?list=PLFE6E58F856038C69) with [Julie Zelinski](https://github.com/zelenski).
- More modern [2018 playlist](https://www.youtube.com/playlist?list=PLoCMsyE1cvdWiqgyzwAz_uGLSHsuYZlMX) is also available on YouTube.
- The 2016 class website has a lot of [links](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1168/links.shtml) to previous years that can be bit difficult to Google. The course reader (*Programming Abstractions in C++*) can be easily obtained from most of the class sites.
- The StanfordCPPLib can be obtained directly from [this website](https://cs.stanford.edu/people/eroberts/StanfordCPPLib/).
- To build an exercise that includes a StanfordCPPLib header be sure the library is built and then include the library.
  - e.g. from inside an exercise folder run `g++ main.cpp -L ../../StanfordCPPLib/lib -lStanfordCPPLib -I ../../StanfordCPPLib/include`.
  - To include additional `.cpp` files to build just add them to the above command after `main.cpp`.
  - For exercises that use graphics libraries like "gwindow.h" either use the Makefile-Example as a guide for building or run the above command and copy the `./StanfordCPPLib/java/spl.jar` into the exercise folder.
  - Actually this is solved by making sure `<iomanip>` is above the StanfordCPPLib includes in the file. ~~I'm getting an error when I use `<iomanip>` with most of the StanfordCPPLib collection classes. For now I'm just removing `<iomanip>` from the exercises and living with poor formatting. I'll investigate this later or maybe swap them to use STL collections instead.~~
