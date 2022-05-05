#include "InputManager.h"

int InputManager::getInt()
{
    int num;

    if (fp >> num)
        return num;
    
    throw InputMismatch();
}

void InputManager::start()
{
	int n;
	int v, u;

	PrimPair* primPair;
	std::vector<Edge*>* kruskalArr;

	try {
		n = getInt();

		G.makeEmptyGraph(n);

		getEdges();

		kruskalArr = MST::Kruskal(G);
		primPair = MST::Prim(G);

		std::cout << "Kruskal <" << MST::sumMST(kruskalArr) << '>' << std::endl;
		
		std::cout << "Prim <" << MST::sumMST(primPair, n) << '>' << std::endl;

		u = getInt();
		v = getInt();

		G.removeEdge(u - 1, v - 1);

		kruskalArr = MST::KruskalIteration(G);

		std::cout << "Kruskal <" << MST::sumMST(kruskalArr) << '>' << std::endl;

		//TODO: delete memory

		delete kruskalArr;
		delete primPair;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

void InputManager::getEdges()
{
	int u, v, c, m, n;

	m = getInt();
	n = G.getSize();

	for (int i = 0; i < m; i++) {

		u = getInt();
		v = getInt();

		if (u > n || v > n || u <= 0 || v <= 0) // check for vertex's validity
			throw InputMismatch();

		c = getInt();

		G.addEdge(u - 1, v - 1, WeightKey(c));
	}
}
