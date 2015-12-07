#ifndef PATH_H
#define PATH_H

#include "PA4.h"
#include "Graph.h"

class Path
{
private:
	stack <Vertex *> _vertices;
	int _distance_traveled;

public:
	Path(void)
	{
		_vertices = stack <Vertex *> ();
		_distance_traveled = 0;
	}

	Path(stack <Vertex *> vertices, int distance_traveled)
	{
		_vertices = vertices;
		_distance_traveled = distance_traveled;
	}

	stack <Vertex *> getVertices(void)
	{
		return _vertices;
	}

	void setVertices(stack <Vertex *> vertices)
	{
		_vertices = vertices;
	}

	int getDistanceTraveled(void)
	{
		return _distance_traveled;
	}

	void setDistanceTraveled(int distance_traveled)
	{
		_distance_traveled = distance_traveled;
	}
};

#endif
