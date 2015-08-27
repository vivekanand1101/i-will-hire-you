from graph import Graph

def check_if_cyclic(graph, root):
    """Print the graph in depth first manner"""

    #its same but, use stack instead
    #"Push your children(neighbours here :P) and take them
    #out at the end"
    stack = []
    stack.append(root)
    visited = []

    while stack:
        node = stack.pop()
        if node in visited:
            return True

        for vertex in graph.neighbours(node):
            if vertex not in visited:
                stack.extend(vertex)
        visited.extend(node)

def main():

    print "Enter the number of vertices: "
    v = int(raw_input())

    print "Enter the binary adjacency matrix: "

    #we represent the graph with the
    #help of dict, key represents the
    #vertices while, corresponding values
    #represent the elements with which the
    #key vertex is connected
    g = {}
    for i in range (v):

        #preparing a row of input
        row = raw_input()
        row = row.split(' ')

        #converting the row into
        #a list, the index of the element
        #enter if the element is 1
        #remember, the vertices are index
        #and whether connected or not is
        #decided by the element (0 or 1)
        l = []
        for j in range(v):
            if int(row[j]) == 1:
                l.append(str(j))

        #adding the list as a value
        #for the corresponding key in
        #the graph dict
        g[str(i)] = l

    graph = Graph(g)
    if check_if_cyclic(graph, '0'):
        print "Cyclic"
    else:
        print "Acyclic"


main()
