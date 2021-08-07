#include<iostream>
#include<string>
#include "Pipenetwork.h"
#include <fstream>

namespace cie
{
	namespace pipenetwork
	{

		PipeNetwork::PipeNetwork(const std::string& filename) :
			filename_(filename)
		{
			std::ifstream infile(filename_);

			infile >> Total_Nodes;

			infile >> Total_Tubes;

			Nodes.reserve(Total_Nodes);
			Tubes.reserve(Total_Tubes);

			for (int i = 0; i < Total_Nodes; i++)
			{
				double x, y, flow;

				infile >> x;
				infile >> y;
				infile >> flow;

				Nodes.push_back(Node(x, y, flow, i));
			}

			for (int i = 0; i < Total_Tubes; i++)
			{
				int node1, node2;
				double diameter;

				infile >> node1;
				infile >> node2;
				infile >> diameter;

				Tubes.push_back(Tube(Nodes.data() + node1, Nodes.data() + node2, diameter));
			}
		}

		std::vector<double> PipeNetwork::computeFluxes() const
		{
			cie::linalg::Matrix B(Total_Nodes, 0.0);
			for (int i = 0; i < Total_Tubes; i++)
			{
				size_t id1 = Tubes[i].node1()->id();
				size_t id2 = Tubes[i].node2()->id();
				double B_i = Tubes[i].permeability();

				B(id1, id1) += B_i;
				B(id2, id2) += B_i;
				B(id1, id2) -= B_i;
				B(id2, id1) -= B_i;
			}

			for (int i = 0; i < Total_Nodes; i++)
			{
				B(0, i) = 0;
				B(i, 0) = 0;
			}

			B(0, 0) = 1;


			std::vector<double> Q;
			for (int i = 0; i < Total_Nodes; i++)
			{
				Q.push_back((-1) * Nodes[i].flow());

			}

			Q[0] = 0;
		
			std::vector<double> heads = cie::linalg::solve(B, Q);

			std::vector<double> fluxes;

			for (int i = 0; i < Total_Tubes; i++)
			{
				fluxes.push_back(Tubes[i].permeability() * (heads[Tubes[i].node1()->id()] - heads[Tubes[i].node2()->id()]));
			}

			return fluxes;
		}
	}
}

