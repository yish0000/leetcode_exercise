#include "TestCase.h"
#include "GraphCommon.h"

using namespace std;

class SolutionCloneGraph : public GraphCommon
{
public:
	Node* cloneGraph(Node* node) {
		if (!node)
			return nullptr;

		vector<Node*> allNodes;
		cloneGraphHelper(node, allNodes);
		return allNodes[0];
	}

	void cloneGraphHelper(Node* node, vector<Node*>& allNodes)
	{
		bool existed = false;
		if (node->val > allNodes.size())
		{
			allNodes.resize(node->val, nullptr);
			allNodes[node->val - 1] = new Node(node->val);
		}
		else
		{
			if (allNodes[node->val - 1])
				existed = true;
			else
				allNodes[node->val - 1] = new Node(node->val);
		}

		if (!existed)
		{
			for (auto neighbor : node->neighbors)
			{
				cloneGraphHelper(neighbor, allNodes);
				allNodes[node->val - 1]->neighbors.push_back(allNodes[neighbor->val - 1]);
			}
		}
	}
};

RUN_TESTCASE(CloneGraph)
{
	SolutionCloneGraph sln;

	vector<vector<int>> arr1 = { {2,4},{1,3},{2,4},{1,3} };
	SolutionCloneGraph::Node* g1 = sln.BuildGraph(arr1);
	SolutionCloneGraph::Node* g2 = sln.cloneGraph(g1);
	TESTCASE_ASSERT(sln.GraphEqual(g1, g2));
	sln.FreeGraph(g1);
	sln.FreeGraph(g2);

	vector<vector<int>> arr2 = { {} };
	SolutionCloneGraph::Node* g3 = sln.BuildGraph(arr2);
	SolutionCloneGraph::Node* g4 = sln.cloneGraph(g3);
	TESTCASE_ASSERT(sln.GraphEqual(g3, g4));
	sln.FreeGraph(g3);
	sln.FreeGraph(g4);

	vector<vector<int>> arr3 = { {2,3,4},{1,7},{1},{1,5,6,8},{4},{4},{2},{4} };
	SolutionCloneGraph::Node* g5 = sln.BuildGraph(arr3);
	SolutionCloneGraph::Node* g6 = sln.cloneGraph(g5);
	TESTCASE_ASSERT(sln.GraphEqual(g5, g6));
	sln.FreeGraph(g5);
	sln.FreeGraph(g6);

	vector<vector<int>> arr4 = { {2},{1} };
	SolutionCloneGraph::Node* g7 = sln.BuildGraph(arr4);
	SolutionCloneGraph::Node* g8 = sln.cloneGraph(g7);
	TESTCASE_ASSERT(sln.GraphEqual(g7, g8));
	sln.FreeGraph(g7);
	sln.FreeGraph(g8);
}