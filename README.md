# Min-Cost-Spanning-Tree

Purpose: Project 2 performs a performance analysis
on two different algorithms that find the minimum
cost spanning tree of a fully connected graph. 
One algorithm using a standard library priority 
queue that implements a binary heap. The other 
using a non standard library priority queue that 
simulates a binary heap. Both algorithms are the 
same except for the differences already mentioned above.

Doxygen Site:
https://acad.kutztown.edu/~tlaud746/CSC402/Project2/index.html

build program:
  make - creates pLib and pDs executables
  make clean - removes object files and both executables
  
  (note the clean option for make does not destroy necessary files.)

  pLib - program that uses standary library for priority queue.
  pDs  - program that uses custom data structure for priority
         queue.

execute options:
./pLib graph_filename
./pLib
./pDs graph_filename
./pDs

If a filename is not provided as a command line argument
the program will ask for one when the program executes.

Attribution:

This project was adapted from a project Aakash Prabhu
created. The full project can be found at the URL
below.

https://github.com/aakash1104/Graph-Algorithms/blob/master/PrimsAlgorithm.cpp

The HeapADT data structure was adapted from an example
created by Dr.Spiegel. The example can be found at the 
URL below.

http://faculty.kutztown.edu/spiegel/CSc237/Examples/HeapADT/VectorImplementation/

Design Decisions:

Making a Edge object in which contains all the appropriate
info for an Edge made the implementation a lot easier. If
I needed a certain value I could access it using the Edge
object. I also needed to implement a greater than function
for the comparsion field of the priority queue. I learned
how to do this from a C++ Data Structures course I took at
Lehigh Carbon Community College. In which the class had to 
simulate a computer's job scheduling using a priority
queue for a course project.

When I thought about how I could accurately time the program's
execution without including the time it takes for a user to provide
input. I thought the easiest way would to be to separate the times 
into two sections. One section would record the time it takes to 
parse the file into the adjacency list data structure. The other 
section would record the time it takes to execute Prim's algorithm 
before output occurs.

For testing purposes only I decided to implement the following feature
below. However, I removed the feature to get an accurate result of the
time it takes to run the algorithm.

I decided to display the total number of vertices and each edge that
was added to the adjancency list at the start of the program. 
This assures the user that edges have been added from top to bottom 
from the inputted file. This way if the user would like to confirm 
the answer they can do so easily, because all the edges are displayed 
right away in a understood format. I also thought that displaying 
the number of vertices and edges right away looks clean.

I decided to display all the valid choices a user has available to
them depending on which graph file they provide. This makes it very
clear which choices are available and which are invalid options. If
a user enters a invalid option an error message gets displayed along
with the list of valid choices below. The user does not have to know
much about how the program works internally in order to be able 
to effectively operate it.

I decided to use integer values of characters, because integers work
perfectly with array indexing. I can then easily convert from integers
to characters when I need the corresponding character value. I accidently
came across the implicit conversion that happens in the createAndAddEdge
function. I was experimenting with the program and when I executed the 
program I seen two smilely faces and a heart. I found out these characters
specifically corresponded to Alt-code characters. Then I added 97 to all
numbers where appropriate and the next time I ran the program I had the
correct ouput with the appropriate characters corresponding to the provided
graph file.

The Edge.h file does not have a corresponding implementation file, because the
implementations are very short. I decided one file was better than two when
the second file would be unecessary.

Project Timeline:

3/7/2021:

10:00 AM 3/7/2021:

At this time I had a bunch of programs I was going
to test out, but the program that made the most sense
was the Prim's algorithm program Aakash Prabhu created.

3:00 PM 3/7/2021:

Around this time I accidently found the implicit
character conversion. In which a short amount of time
later I had a working implementation. I tested the program
by drawing out the graph myself on a whiteboard and performing
Prim's algorithm on the drawn graph. I checked the cost as well
as each individual edge that was chosen.

6:00 PM 3/9/2021:

Adapted the Heap_ADT example created by Dr.Spiegel from a largest
element heap to a smallest element heap. Also fixed some minor
syntax issues.

12:00 AM 3/10/2021:

Realized that the smallest element heap had a bug that would not
return the elements smallest to largest. Fixed it and now the program
works correctly. I implemented the Heap_ADT into my second program 
and tested it on a 9 vertex fully connected graph file that was 
generated using a Python 3 program. All of the edges were displayed
in ascending weight order.

3/11/2021:

Created the documenation Doxygen site for the project. I also created 
the Makefile that creates both executables pLib and pDs. I had to make
sure I was implementing the Makefile properly so that I did not have
to make all the files everytime I ran it. I added a compile argument
so I can easily change the complier if I wanted to in the future.

3/12/2021:

Added substansive input validation to both programs. I modified a
input validation function I used in CSC 237 for project 2. The
full documentation can be found at the URL below.
https://www.acad.kutztown.edu/~tlaud746/CSC237/Project2/testLL_8cpp.html

I also decided to add all the available choices a user has available
depending on which graph file is provided to the program.
