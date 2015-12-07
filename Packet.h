#ifndef PACKET_H
#define PACKET_H

#include "PA4.h"

class Packet
{
private:
	char _value;
	int _order;
	int _current_wait;
	Vertex *_destination;
	Vertex *_previous_location;
	Vertex *_next_hop;

public:
	Packet(void)
	{
		_value = NULL;
		_order = 0;
		_current_wait = 0;
		_destination = &Vertex(0);
		_previous_location = &Vertex(0);
		_next_hop = &Vertex(0);
	}

	Packet(char value, int order, int current_wait, Vertex *destination, Vertex *previous_location, Vertex *next_hop)
	{
		_value = value;
		_order = order;
		_current_wait = current_wait;
		_destination = destination;
		_previous_location = previous_location;
		_next_hop = next_hop;
	}

	char getValue(void)
	{
		return _value;
	}

	void setValue(char value)
	{
		_value = value;
	}

	int getOrder(void)
	{
		return _order;
	}

	void setOrder(int order)
	{
		_order = order;
	}

	int getCurrentWait(void)
	{
		return _current_wait;
	}

	void setCurrentWait(int current_wait)
	{
		_current_wait = current_wait;
	}

	Vertex* getDestination(void)
	{
		return _destination;
	}

	void setDestination(Vertex* destination)
	{
		_destination = destination;
	}

	Vertex* getPreviousLocation(void)
	{
		return _previous_location;
	}

	void setPreviousLocation(Vertex* previous_location)
	{
		_previous_location = previous_location;
	}

	Vertex* getNextHop(void)
	{
		return _next_hop;
	}

	void setNextHop(Vertex* next_hop)
	{
		_next_hop = next_hop;
	}
};

#endif
