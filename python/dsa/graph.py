# The below code is for undirected graph

class Graph:
    """Represents a graph, uses python dict
        data structure.
    """

    def __init__(self, graph_dict={}):
        """Initializes the graph, has
            a default value as an empty dict
        """
        self.graph_dict = graph_dict

    def vertices(self):
        """Returns all the vertices of the graph"""
        return list(self.graph_dict.keys())

    def edges(self):
        """Returns all the edges of the graph,
            uses the generate edge method
        """
        return self.generate_edges()

    def add_vertex(self, vertex):
        """Adds a vertex to the graph"""
        
        #here if the vertex is not present,
        #then it is initialized with an empty list
        #and is added as a key to the graph dict
        #and thus gets added to the graph
        if vertex not in self.graph_dict:
            self.graph_dict[vertex] = []

    def add_edge(self, edge):
        """Add an edge to the graph"""

        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)

        #if the edge has to be entered,
        #considering it is undirected graph,
        #the entry has to be done for both
        #the vertices as the key
        if vertex1 in self.graph_dict:
            self.graph_dict[vertex1].append(vertex2)
        else:
            self.graph_dict[vertex1] = [vertex2]

        if vertex2 in self.graph_dict:
            self.graph_dict[vertex2].append(vertex1)
        else:
            self.graph_dict[vertex2] = [vertex1]

    def generate_edges(self):
        """Generate all the edge of the graph,
            It is a helper function for edges()
        """
        
        #every pair of key and value in the
        #list of all the values for the keys
        #will make for the edge. Iterate over
        #all the keys and you have all the edges
        edges = []
        for key, values in self.graph_dict.iteritems():
            for value in values:
                if (value, key) not in edges:
                        edges.append((key, value))
        return edges

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

    print "Vertices of the graph #1:"
    print graph.vertices()

    print "Edges of the graph #1: "
    print graph.edges()

    print
    print "Adding a new vertex"
    graph.add_vertex(str(10))
    print

    print "Vertices of the graph #2"
    print graph.vertices()

    print "Edges of the graph #2"
    print graph.edges()

    print
    print "Add an edge {\"11\", \"12\"} with new vertices"
    graph.add_edge({"11", "12"})
    print

    print "Vertices of the graph #3: "
    print graph.vertices()

    print "Edges of the graph #3: "
    print graph.edges()

if __name__ == '__main__':
    main()
