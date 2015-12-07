#ifndef NETWORK_H
#define NETWORK_H
#include "PA4.h"
#include "Message.h"
#include "Graph.h"
class Network
{
private:
	Graph graph{};
	int tickcount = 0;
	Message message{};
public:
	void onetick()
	{
		tickcount++;
	}
	void setgraph(Graph a)
	{
		graph = a;
	}
	void settick(int b)
	{
		tickcount = b;
	}
	void setmessage(Message c)
	{
		message = c;
	}
	Graph getgraph()
	{
		return graph;
	}
	int gettick()
	{
		return tickcount;
	}
	Message getmessage()
	{
		return message;
	}



};
#endif
