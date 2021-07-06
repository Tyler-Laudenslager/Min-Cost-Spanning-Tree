/*! \file Edge.h
    \brief creates Edge objects

    \author Tyler Laudenslager
*/


#ifndef EDGE_H
#define EDGE_H

/*! \class Edge
    \brief builds Edge objects
*/
class Edge {
     

     public:

     /*! \brief Constructor
         \param vertex1 character of vertex1
         \param vertex2 character of vertex2
         \param edge_weight weight of the edge

         Constructs a new edge object using both vertices
         and a weight.

    */

     Edge(char vertex1, int edge_weight, char vertex2) {
         vertexA = vertex1;
         vertexB = vertex2;
         weight = edge_weight;
     }

     /*! \brief Default Constructor
     */
     Edge() {
         vertexA = '?';
         vertexB = '?';
         weight = 0;
     }
     
     /*! \brief less than operator
         \param edge2 right hand side of operator
     */
     bool operator<(Edge edge2) {
            return (this->weight) < edge2.weight;
     }
     /*! \brief greater than operator
         \param edge2 right hand side of operator
     */
     bool operator>(Edge edge2) {
            return (this->weight) > edge2.weight;
     }

     char vertexA;
     char vertexB;
     int weight;
};

#endif
