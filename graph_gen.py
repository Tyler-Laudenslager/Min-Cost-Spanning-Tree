import itertools
import random
import os

def char_range(start, num_vertices):
        for c in range(start,start+num_vertices):
            yield chr(c)


def generate_graph(opened_file, vertices, max_cost=3):

    print(vertices,file=opened_file)
    
    for vertex1, vertex2 in list(itertools.combinations(
                            list(char_range(97,vertices)),2)):
        
        print(vertex1, vertex2, random.randint(1,max_cost),file=opened_file)
        

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

            vertices = int(input("How many vertices: "))
            max_cost = int(input("Enter max cost: "))

            file = open("gen_graph_" + str(vertices)
                         + "_" + str(get_number())+ ".txt", 'w')
            increment_number()

            generate_graph(file, vertices, max_cost)
            print("Graph file generated")
            
    except FileNotFoundError as e:
        print(e)

    finally:
        file.close()

