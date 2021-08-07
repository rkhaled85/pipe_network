#pragma once
#include <Node.h>

namespace cie
{
	namespace pipenetwork
	{
		class Tube
		{
		public:
			Tube(Node* node1, Node* node2, double diameter);
			double length() const;
			double permeability() const;
			const Node* node1() const;
			const Node* node2() const;

		private:
			double d;
			const Node* node_1;
			const Node* node_2;
		};
	}
}

