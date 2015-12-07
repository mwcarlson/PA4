//this project is a collaboration between Michael Carlson (11424987, Section 2) and Martijn Oostrom (11420033, Section 1)

#include "PA4.h"

using namespace std;

void graphTest()
{
	//populate graph
	int i = 0,maxsize=0;
	string curstring;
	Graph graph{};
	vector<Vertex> vertices{};
	cout << "Enter a name to read graph info from: " << endl;
	getline(cin, curstring);
	ifstream input(curstring);
	std::string curspot((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
	maxsize = curspot.size();
	cout << curspot << endl;
	while (curspot[i+1] != ' ')
	{
		
		if (curspot[i]!='\n')
		{
			vertices.push_back(Vertex{});
			cout << "Adding vertex number: " << curspot[i] << endl;
		}
		
		i++;
	}
	while (i < maxsize)
	{

	}
	/*
	Graph: 0 -> 1 (weight 4)
	       0 -> 3 (weight 10)
		   1 -> 2 (weight 4)
		   1 -> 3 (weight 8)
		   2 -> 3 (weight 15)
		   
	*/
	/*vertices[0].addEdge(&vertices[1], 4);
	vertices[0].addEdge(&vertices[3], 20);
	vertices[1].addEdge(&vertices[2], 4);
	vertices[1].addEdge(&vertices[3], 8);
	vertices[2].addEdge(&vertices[3], 15);

	//add vertices to graph
	for (auto vertex : vertices)
	{
		graph.addVertex(vertex);
	}

	unordered_map<Vertex, int> distances = graph.computeShortestPath(&vertices[0]);
	cout << "Distance from 0 to 0: " << distances[vertices[0]] << " (expected: 0)" << endl;
	cout << "Distance from 0 to 1: " << distances[vertices[1]] << " (expected: 4)" << endl;
	cout << "Distance from 0 to 2: " << distances[vertices[2]] << " (expected: 8)" << endl;
	cout << "Distance from 0 to 3: " << distances[vertices[3]] << " (expected: 12)" << endl;*/
}

int main(int argc, char* argv[])
{
	graphTest();
}
