/* 

   Tyler Laudenslager
   CSC 402 Data Structures 2
   Spring 2021

*/

/*! \file primLib.cpp
    \brief Finds a minimum spanning tree of a graph

    \authors Aakash Prabhu
    \authors Tyler Laudenslager
*/

/*!
     \mainpage Finding Minimum Cost Spanning Trees
     \n
     The purpose of Project 2 is to perform a performance analysis on Prim's algorithm that is \n
     implemented in two different ways to find the minimum cost spanning tree of a connected graph. \n
     One implementation using a standard library priority queue that simulates a binary heap. The other \n
     using a non standard library priority queue that simulates a binary heap. Both implementations are \n
     the same except for the differences already mentioned above. \n

     @image html graph_final_pic_1.svg
     \n
     @image html graph_final_pic_2.svg

     \n
     \n
     primLib.cpp -> Implementation that uses standard library priority queue. \n
     primDS.cpp -> Implementation that uses does not use a standard library priority queue. \n
     Edge.h -> builds Edge objects \n
     Heap_ADT.cpp -> priority queue implemented as a binary heap \n

     \n
     
     Graph Image was generated using an Open Source tool located\n
     at this URL: https://graphonline.ru/en/
     
     \n

     This project was adapted from URL: https://github.com/aakash1104/Graph-Algorithms/blob/master/PrimsAlgorithm.cpp

     Adapted binary heap example from URL: http://faculty.kutztown.edu/spiegel/CSc237/Examples/HeapADT/VectorImplementation/


     \authors Dr.Spiegel
     \authors Aakash Prabhu
     \authors Tyler Laudenslager
  */

// Original Author: Aakash Prabhu
// From https://github.com/aakash1104/Graph-Algorithms/blob/master/PrimsAlgorithm.cpp

/* Adapted By: Tyler Laudenslager for Project 2 */

#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <map>
#include <fstream>
#include <sstream>
#include <chrono>
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

/* Program that uses Prims Algorithm to generate a Minimum Spanning Tree
 * and hence find the minimum cost to connect all the vertices
 */

/*! \struct STL_Edge
    \brief Builds STL_Edge objects
*/

struct STL_Edge {
     /*! 
         \brief Constructor

         Constructor for edge_weight object
         initializes the two vertices that are incident to
         the edge and the corresponding weight of the edge.
      */
     STL_Edge(char vertex1, int edge_weight, char vertex2) {
         vertexA = vertex1;
         vertexB = vertex2;
         weight = edge_weight;
     }

     /*!
         \brief Default Constructor
     */
     STL_Edge() {
         vertexA = '?';
         vertexB = '?';
         weight = 0;
     }
     char vertexA;
     char vertexB;
     int weight;
};

/*! \struct min_weight
    \brief Comparsion struct for priority queue
*/
struct min_weight {
     /*! 
        \brief greater than operator

        returns true if the left edge has greater weight than the
        right edge.
    */
     bool operator()(STL_Edge p1, STL_Edge p2) {
         return p1.weight > p2.weight;
     }
};

/*! \brief Creates and adds the edge to the adjacency list
    \param adjList reference to a array that has holds vector<STL_Edge>
    \param vertex1 number that corresponds to an ascii character
    \param weight weight of the edge
    \param vertex2 number that corresponds to an ascii character
    \returns N/A
    
*/

void createAndAddEdge(vector <STL_Edge> adjList[], int vertex1, int weight, int vertex2){
  adjList[vertex1-97].push_back(STL_Edge(vertex1, weight, vertex2));
  adjList[vertex2-97].push_back(STL_Edge(vertex2, weight, vertex1)); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v, int weight)

/*! \brief Finds the minimum weight.
    \param adjList reference to an adjancency list.
    \param source vertex to start at
    \param edge_list map structure in which the key is the cost of the edge
    \param vertices total number of vertices
    \returns (int) cost of the minimum weight spanning tree.

    Finds the minimum weight spanning tree in an adjacency list structure.

    
*/

int PrimsAlgorithm(vector <STL_Edge> adjList[], map<int,vector<STL_Edge> > &edge_list, int source, int vertices){
  vector <bool> visitedVertex(vertices, false);
  priority_queue<STL_Edge, vector<STL_Edge>, min_weight > PQ; // Set up priority queue
  STL_Edge edge;
  int minCost = 0;
  PQ.push(STL_Edge(source,0,source)); // Source has weight 0;
  while (!PQ.empty()){
    edge = PQ.top(); // Use to get minimum weight
    source = ((int) (edge.vertexB))-97; // get the vertex
    PQ.pop(); // Pop before checking for cycles
    if (visitedVertex.at(source)) // Check for cycle
      continue; // Already accounted for it, move on
    visitedVertex.at(source) = true; // Else, mark the vertex so that we won't have to visit it again
    if (edge.weight != 0) {
        edge_list[edge.weight].push_back(edge);
    }
    minCost += edge.weight; // Add to minCost
    for (vector<STL_Edge>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++) {
      int index = (int) (it->vertexB) - 97;// Visit all children
      if (!visitedVertex.at(index)) // If vertex hasn't been visited already
        PQ.push(STL_Edge(it->vertexA, it->weight, it->vertexB)); // Push vertex and weight onto Priority Queue
    }
  } // While Priority Queue is not empty
  return minCost;
} // PrimsAlgorithm

/*! \brief Opens file for reading
    \param argc number of command line arguments
    \param argv array of command line arguments
    \param infile reference to a ifstream object
    \returns true if file was opened successfully for reading false otherwise.

    Tries to open file for reading before we try to get input from
    the file.

*/

bool open_file_to_read(int argc, char *argv[], ifstream &infile) {
    if(argc > 1) {
        infile.open(argv[1], ios::in);
        if (infile.fail()) {
           cerr << "Failed to open file." << endl;
           return false;
        }
        return true;
     }
    else {
       string file_name;
       cout << "Enter graph filename: ";
       getline(cin, file_name);
       infile.open(file_name, ios::in);
       if (infile.fail()) {
          cerr << "Failed to open file." << endl;
          return false;
       }
       return true;
     }
}

/*! \brief Prints the minimum cost spanning tree
    \param edge_list map structure in which the key is the cost of the edge
    \param cost minimum cost of spanning tree
    \param source (char) starting vertex
    \returns N/A

    
    Prints the starting vertex and all the edges with weights. At
    the end prints the total cost of the edges.

*/

void print_spanning_tree(const map<int,vector<STL_Edge> > &edge_list, int cost, char source) {
  cout << endl;
  cout << "minimum spanning tree -> start " << (char) (source) << endl;
  for(auto edge_struct : edge_list) {
      for(auto edge : edge_struct.second) {
        cout << "edge (" << edge.vertexA << "," << edge.vertexB << ") weight : " << edge.weight << endl;
      }
  }
  cout << "spanning tree total cost : " << cost << endl;
}

/*! \brief Ensures valid input from user (helper function)
    \param option character from user
    \param total_vertices total number of vertices
    \returns true if given valid input false otherwise.
 
    Helper function for get_user_input(). Checks to see if the given \n
    character is within the proper range of values. We subtract 97 to \n
    account for lower case characters. Also we subtract 65 to account \n
    for upper case characters. Since the option will be within \n
    0 - total vertices-1 range after we subtract both 97 and 65 from \n
    the input we can test if the input is valid.
*/

bool is_valid(char option, int total_vertices) {
    int int_of_char_lower = (int) option - 97;
    int int_of_char_upper = (int) option - 65;
    if(int_of_char_lower >= 0 && int_of_char_lower < total_vertices) {
        return true;
    }
    else if (int_of_char_upper >= 0 && int_of_char_upper < total_vertices) {
        return true;
    }
    else if (((int) option) == 63) {
        //question mark
        return true;
    }
    else {
        return false;
    }
}

/*! \brief Prints valid choices
    \param num_vertices total number of vertices
    \returns N/A

    Prints valid character choices by adding 97 to the 
    start which is 0 and printing all the characters up \n
    to and including 97 + number_vertices-1.
*/

void output_valid_choices(int num_vertices) {
     
     cout << "Choices: ";
     for(int start = 0; start < num_vertices; ++start) {
        cout << (char) (start+97) << " ";
     }
     cout << endl;
}

/*! \brief Ensures valid user input from standard input
    \param total_vertices total number of vertices
    \returns (char) valid user option

   Adapted from my CSC_237 Data Structures class \n
   Project 2 program \n
   documented here \n
   URL: https://acad.kutztown.edu/~tlaud746/CSC237/Project2/testLL_8cpp.html

*/

/* adapted the function below from my CSC_237 Data Structures class
   Project 2 program
   documented here 
   https://acad.kutztown.edu/~tlaud746/CSC237/Project2/testLL_8cpp.html
*/

char get_user_input(int total_vertices) {
  string input;
  string option;
  while(true) {
    output_valid_choices(total_vertices);
    cout << "Enter valid choice (Press ? to exit): ";
    cout.flush();
    getline(cin, input);

    stringstream stream(input);

    if((stream >> option) && (option.length() == 1) && is_valid(option[0], total_vertices)) {
        break;
    }
    else {
      cout << "Error: Enter a valid choice" << endl;
    }

  }
  return tolower(option[0]);
}

/*! \brief Parses the contents from an opened file.
    \param infile reference to a file opened for reading.
    \param adj_list reference to an array that contains vector<STL_Edge> as elements
    \returns N/A

    Pre-condition - file was successfully opened. \n
    Post-condition - file was successfully closed. \n \n
    
    Parses the contents from an opened file into a adjancency list data \n
    structure. Proper file format is displayed below. \n \n
    
    4     <---- number of vertices \n
    a b 6  <--- Edge a = vertex1 b = vertex2 6 = weight \n
    a c 2 \n
    a d 7 \n
    b c 5 \n
    b d 1 \n
    c d 5 \n
*/
void get_info_from_file(ifstream &infile, vector<STL_Edge> adj_list[]) {
     
     char vertexA, vertexB;
     int weight;

     while(infile >> vertexA >> vertexB >> weight) {
         int intVertexA = (int) vertexA;
         int intVertexB = (int) vertexB;
         createAndAddEdge(adj_list,intVertexA,weight,intVertexB);
     }
    
     infile.close();
}

/*!
    \brief Entry point of the program.
    \param argc (int) number of command line arguments.
    \param argv c-string array of the command line arguments.
    \returns (int) 0 if clean exit else -1.

    Entry point of the program. Asks the user for a starting vertex \n
    then prints the minimum cost spanning of the graph from an file \n
    that was specified has a command line argument or a file that \n
    has been given once the program is running. 

*/

int main (int argc, char *argv[]) {

     ifstream infile;
     int num_vertices;
     char source;

     if (open_file_to_read(argc, argv, infile)) {

       auto begin = chrono::high_resolution_clock::now();

       infile >> num_vertices;

       vector<STL_Edge> adjList[num_vertices];

       get_info_from_file(infile, adjList);

       auto end = chrono::high_resolution_clock::now();
       auto first_time = chrono::duration_cast<chrono::microseconds>(end-begin);

       while (true) {
         cout << endl;
         source = get_user_input(num_vertices);
         if(source == '?') break;

         int int_source = (int) source;
         map<int,vector<STL_Edge> > edge_list;

         begin = chrono::high_resolution_clock::now();
         int cost = PrimsAlgorithm(adjList, edge_list, int_source, num_vertices);
         end = chrono::high_resolution_clock::now();

         auto second_time = chrono::duration_cast<chrono::microseconds>(end-begin);
         auto total_ticks = first_time + second_time;

         print_spanning_tree(edge_list, cost, source);
         cout << "standard library algorithm took " << total_ticks.count() << " microseconds." << endl;
        }
        return 0;
     }
     else {
      return -1;
     }

} // main()