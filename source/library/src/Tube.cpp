#include "Tube.h"
#include "Node.h"
#include<iostream>
#include <cmath> 

namespace cie
{
	namespace pipenetwork
	{
		Tube::Tube(Node* node1, Node* node2, double diameter) : node_1(node1), node_2(node2), d(diameter)
		{}

		double Tube::length() const
		{
			return sqrt(pow(node_1->x() - node_2->x(), 2) + pow(node_1->y() - node_2->y(), 2));
		}

		double Tube::permeability() const
		{
			return 3.14159265358979323846 * 9.81 * pow(d, 4) / (128 * pow(10, -6) * length());
		}

		const Node* Tube::node1() const 
		{
			return node_1;
		}

		const Node* Tube::node2() const 
		{
			return node_2;
		}
	}
}