#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "Tube.h"
#include "linalg.hpp"

namespace cie
{
	namespace pipenetwork
	{
		class PipeNetwork
		{
		public:
			PipeNetwork(const std::string& filename);
			std::vector<double> computeFluxes() const;
		private:
			const std::string filename_;
			std::vector<Node> Nodes;
			std::vector<Tube> Tubes;
			int Total_Nodes;
			int Total_Tubes;
		};
	}
}


