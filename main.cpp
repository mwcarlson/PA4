//this project is a collaboration between Michael Carlson (11424987, Section 2) and Martijn Oostrom (11420033, Section 1)



#include "PA4.h"
#include "Graph.h"
#include "Vertex.h"
#include "Message.h"
#include "Packet.h"
#include "Network.h"
//using namespace std;
vector<Vertex> VerticesTest(void)
{
	//populate graph
	int i = 0, maxsize = 0, focusmod = 0, fromvec = 0, tovec = 0, weightedge = 0;
	string curstring, modstring;
	Graph graph{};
	vector<Vertex> vertices{};
	/*cout << "Enter a name to read graph info from: " << endl;
	getline(cin, curstring);
	ifstream input(curstring);*/
	ifstream input("input.txt");
	//I used http://www.cplusplus.com/forum/general/109435/ to help me with this next line (with some modification)
	string curspot((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
	//curspot now has entire input file as 1 massive string
	maxsize = curspot.size();
	cout << curspot << endl;

	while (curspot[i + 1] != ' ')
	{
		//still going through list of vertices
		if (curspot[i] != '\n')
		{
			//We need to add a edge
			vertices.push_back(Vertex{});

		}

		i++;
	}

	while (i < maxsize)
	{
		//Still have pieces of the edge info to process
		if (curspot[i] == ' ')
		{
			if (focusmod == 0)
			{
				//modstring now represents the originating node of the vector

				fromvec = stoi(modstring);
			}
			else if (focusmod == 1)
			{
				//modstring now represents the ending node of the vector
				tovec = stoi(modstring);
			}
			//Change what it is we're reading (from, to, weight), and clean string
			focusmod = (focusmod + 1) % 3;
			modstring.clear();
		}
		else if (curspot[i] == '\n')
		{
			//modstring now represents the weight of the edge 
			weightedge = stoi(modstring);
			//smash on the new edge
			vertices[fromvec].addEdge(&vertices[tovec], weightedge);
			modstring.clear();
			focusmod = (focusmod + 1) % 3;
		}
		else
		{
			//Need to add value to modstring
			modstring += curspot[i];
		}
		i++;
	}
	//V I had a slight off-by 1 error, so these next few lines just does what my case '\n' does.
	weightedge = stoi(modstring);
	//cout << "From vec: " << fromvec << " to vec: " << tovec << " with weight " << weightedge << endl;

	vertices[fromvec].addEdge(&vertices[tovec], weightedge);
	modstring.clear();
	//V  Adds all of the vertices to the graph
	for (auto vertex : vertices)
	{
		graph.addVertex(vertex);

	}
	
	return vertices;
}
Graph graphTest()
{
	//populate graph
	int i = 0,maxsize=0, focusmod=0, fromvec=0, tovec=0, weightedge=0;
	string curstring, modstring;
	Graph graph{};
	vector<Vertex> vertices{};
	/*cout << "Enter a name to read graph info from: " << endl;
	getline(cin, curstring);
	ifstream input(curstring);*/
	ifstream input("input.txt");
	//I used http://www.cplusplus.com/forum/general/109435/ to help me with this next line (with some modification)
	string curspot((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
	//curspot now has entire input file as 1 massive string
	maxsize = curspot.size();
	cout << curspot << endl;
	
	while (curspot[i+1] != ' ')
	{
		//still going through list of vertices
		if (curspot[i]!='\n')
		{
			//We need to add a edge
			vertices.push_back(Vertex{});
			
		}
		
		i++;
	}
	
	while (i < maxsize)
	{
		//Still have pieces of the edge info to process
		if (curspot[i] == ' ')
		{
			if (focusmod == 0)
			{
				//modstring now represents the originating node of the vector
				
				fromvec = stoi(modstring);
			}
			else if (focusmod == 1)
			{
				//modstring now represents the ending node of the vector
				tovec = stoi(modstring);
			}
			//Change what it is we're reading (from, to, weight), and clean string
			focusmod = (focusmod + 1) % 3;
			modstring.clear();
		}
		else if (curspot[i] == '\n')
		{
			//modstring now represents the weight of the edge 
			weightedge = stoi(modstring);
			//smash on the new edge
			vertices[fromvec].addEdge(&vertices[tovec], weightedge);
			modstring.clear();
			focusmod = (focusmod + 1) % 3;
		}
		else
		{
			//Need to add value to modstring
			modstring += curspot[i];
		}
		i++;
	}
	//V I had a slight off-by 1 error, so these next few lines just does what my case '\n' does.
	weightedge = stoi(modstring);
	//cout << "From vec: " << fromvec << " to vec: " << tovec << " with weight " << weightedge << endl;
	
	vertices[fromvec].addEdge(&vertices[tovec], weightedge);
	modstring.clear();
	//V  Adds all of the vertices to the graph
	for (auto vertex : vertices)
	{
		graph.addVertex(vertex);
		
	}
	//return graph;
	
	//The below code is just a bunch of testing statements that aren't entirely related to the code. Feel free to ignore
	unordered_map<Vertex, int> distances = graph.computeShortestPath(&vertices[0]);

	cout << "Distance from 0 to 0: " << distances[vertices[0]] << " (expected: 0)" << endl;
	cout << "Distance from 0 to 1: " << distances[vertices[1]] << " (expected: 4)" << endl;
	cout << "Distance from 0 to 2: " << distances[vertices[2]] << " (expected: 8)" << endl;
	cout << "Distance from 0 to 3: " << distances[vertices[3]] << " (expected: 12)" << endl;
	return graph;
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
	char curchar = '\0';
	int startvertex = 0, endvertex = 0,i=0;
	string strmess;
	Graph maingraph{};
	Packet packet{};
	Network network{};
	queue<Packet> quepack;
	Message message{};
	maingraph=graphTest();
	network.setgraph(maingraph);
	vector<Vertex> vertices{};
	vertices = VerticesTest();
	//maingraph now has the graph with vertices and edges that we'll use for the rest of this PA
	
	cout << "What vertex do you want to start the message from?" << endl;
	cin >> startvertex;
	cout << "What vertex do you want to send the message to?" << endl;
	cin >> endvertex;
	cout << "What string message do you want to send?" << endl;
	ws(cin);
	getline(cin, strmess);

	Vertex vertexs{ startvertex };
	
	Vertex vertexe{ endvertex };
	
	packet.setPreviousLocation(&vertexs);

	
	packet.setDestination(&vertexe);
	packet.setCurrentWait(0);
	packet.setDestination(0);
	packet.setNextHop(&vertexe);
	packet.setOrder(0);
	cout << strmess<< endl;
	cout << strmess.size() << endl;
	while (i < strmess.size())
	{
		curchar = strmess[i];
		cout << curchar << endl;
		packet.setValue(curchar);
		quepack.push(packet);
		i++;
		maingraph = network.getgraph();
		
	}

	i = 0;
	message.setqueue(quepack);
	message.setstart(&vertexs);
	message.setend(&vertexe);
	network.setmessage(message);
	unordered_map<Vertex, int> distances;
	int edgelength = 0;
	
	while (i<quepack.size())
	{
		quepack = message.getqueue();
		packet=quepack.front();
		
		vertexs = *packet.getPreviousLocation();
		
		maingraph=network.getgraph();
		cout << "hi5" << endl;
		distances = maingraph.computeShortestPath(&vertices[0]);
		cout << "hi4" << endl;
		edgelength=distances[vertices[1]];
		packet.setCurrentWait(edgelength*vertices[1].getload());
		packet.setDestination(&vertices[1]);
		packet.setPreviousLocation(&vertices[0]);
		vertices[1].plusload();
		i++;
		
		
	}
	
	
}
