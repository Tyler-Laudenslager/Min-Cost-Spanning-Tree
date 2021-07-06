#Authors
#Tyler Laudenslager
#Phil Thomas


import random
import itertools
import os
import sys

def char_range(start, num_vertices):
        for c in range(start,start+num_vertices):
            yield chr(c)

def get_even_edges(vertices,degree):
	graph = list(char_range(97,vertices))
	return [(graph[i%vertices],graph[((k+i)%vertices)])
                for k in range(1,(degree//2)+1)
                for i in range(vertices)]

def get_even_degree_edges(vertices, degree):
        graph = list(char_range(97,vertices))
        edges = list()
        for k in range(1, (degree//2)+1):
                for i in range(vertices):
                        edges.append((graph[i%vertices],graph[(k+i)%vertices]))
                                              
        return edges

def get_edges(vertices, degree):
        
        if degree==vertices-1:
                return list(itertools.combinations(
                       list(char_range(97,vertices)),2))
        elif degree==2:
                graph = list(char_range(97,vertices))
                graph_2 = graph[1:]
                graph_2.append(graph[0])
                final_edges = list(zip(graph,graph_2))
                return final_edges

        elif vertices % 2 == 0:
                
                if degree % 2 == 0:
                        edge_list = get_even_degree_edges(vertices=vertices, degree=degree)
                        return edge_list
                elif degree % 2 == 1:
                        graph = list(char_range(97,vertices))
                        edge_list = get_even_degree_edges(vertices=vertices, degree=degree-1)
                        for i in range(vertices//2):
                                edge_list.append((graph[i%(len(graph))],graph[((i+(vertices//2))%(len(graph)))]))
                        return edge_list
        elif vertices % 2 == 1:
                if degree % 2 == 0:
                        edge_list = get_even_degree_edges(vertices=vertices, degree=degree)
                        return edge_list
                else:
                        raise ValueError
                
                

def generate_graph(opened_file, vertices, degree, max_cost=3):

    try:
            edges = get_edges(vertices,degree)
      

            print(vertices,file=opened_file)
            
            for vertex1, vertex2 in get_edges(vertices,degree):
        
                print(vertex1, vertex2, random.randint(1,max_cost),file=opened_file)

            #print("Graph file generated", vertices, degree, max_cost)

    except ValueError:
            print("Odd number of vertices have to have an even degree")
        

    opened_file.close()

def correct_input(vertices, degree):
        edges = (vertices * degree) // 2
        if edges % 2 == 0:
            return True
        else:
            return False

def get_number():
    for number in open("next_number.txt"):
        return int(number)

def increment_number():
    print(str(get_number() + 1), file=open("next_number.txt", 'w'))

def create_file():
    print(str(1), file=open("next_number.txt", 'w'))

if __name__ == "__main__":


    try:
            if not os.path.isfile("next_number.txt"):
                create_file()

            if len(sys.argv) == 4:
                    vertices = int(sys.argv[1])
                    degree = int(sys.argv[2])
                    max_cost = int(sys.argv[3])
            else:
 
                    vertices = int(input("How many vertices: "))
                    degree = int(input("enter degree: "))
                    max_cost = int(input("Enter max cost: "))

            file = open("gen_graph_" + str(vertices) + "_" + str(degree) + "_" + str(max_cost)
                         + "_" + str(get_number())+ ".txt", 'w')
            increment_number()

            generate_graph(file, vertices, degree, max_cost)
            
    except FileNotFoundError as e:
        print(e)

    finally:
        file.close()

