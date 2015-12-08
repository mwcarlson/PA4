#ifndef MESSAGE_H
#define MESSAGE_H
#include "PA4.h"
#include "Packet.h"
#include "Vertex.h"
class Message
{
private:
	Vertex *startingvertex;
	Vertex *endingvertex;
	queue<Packet> packets;
public:
	queue<Packet> c;
	Message()
	{
		startingvertex = &Vertex(0);
		endingvertex = &Vertex(0);
	
		packets = c;
	}
	Message(Vertex *a, Vertex *b, queue<Packet> c)
	{
		startingvertex = a;
		endingvertex = b;
		packets = c;
	}
	Vertex* getstart()
	{
		return startingvertex;
	}
	Vertex* getend()
	{
		return endingvertex;
	}
	
	queue<Packet> getqueue()
	{
		return packets;
	}
	
	void setstart(Vertex* a)
	{
		startingvertex = a;
	}
	void setend(Vertex* b)
	{
		endingvertex = b;
	}
	
	void setqueue(queue<Packet> c)
	{
		packets=c;
	}
	
};


#endif
