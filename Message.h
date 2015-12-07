#ifndef MESSAGE_H
#define MESSAGE_H
#include "Vertex.h"
class Message
{
private:
	Vertex *startingvertex;
	Vertex *endingvertex;
	//queue<Packet> packets;
public:
	Message()
	{
		startingvertex = &Vertex(0);
		endingvertex = &Vertex(0);
		//packets=Packet(0.....)
	}
	Message(Vertex *a, Vertex *b)//, Queue<Packet> c)
	{
		startingvertex = a;
		endingvertex = b;
		//packets = c;
	}
	Vertex* getstart()
	{
		return startingvertex;
	}
	Vertex* getend()
	{
		return endingvertex;
	}
	/*
	Queue<Packet> getqueue()
	{
		return packets;
	}
	*/
	void setstart(Vertex* a)
	{
		startingvertex = a;
	}
	void setend(Vertex* b)
	{
		endingvertex = b;
	}
	/*
	void setqueue(Queue<Packet> c)
	{
		packets=c;
	}
	*/
};


#endif
