#pragma once

#include <vector>
#include <set>
#include <sstream>

class GraphCommon
{
public:
	struct Node {
		int val;
		std::vector<Node*> neighbors;

		Node()
			: val(0), neighbors()
		{
		}

		Node(int _val)
			: val(_val), neighbors()
		{
		}

		Node(int _val, const std::vector<Node*>& _neighbors)
			: val(_val), neighbors(_neighbors)
		{
		}
	};

public:
	Node* BuildGraph(std::vector<std::vector<int>>& adjList)
	{
		std::vector<Node*> arr(adjList.size(), nullptr);

		for (int i = 0; i < adjList.size(); i++)
		{
			if (arr[i] == nullptr)
				arr[i] = new Node(i + 1);

			for (auto index : adjList[i])
			{
				if (arr[index - 1] == nullptr)
					arr[index - 1] = new Node(index);

				arr[i]->neighbors.push_back(arr[index - 1]);
			}
		}

		return arr.size() ? arr[0] : nullptr;
	}

	void FreeGraph(Node* node)
	{
		std::vector<Node*> allNodes;
		CollectAllNodes(node, allNodes);
		for (auto p : allNodes)
			delete p;
	}

	bool GraphEqual(Node* a, Node* b)
	{
		if (a == b)
			return true;

		std::string adjList1 = GetAdjencyList(a);
		std::string adjList2 = GetAdjencyList(b);
		return adjList1 == adjList2;
	}

protected:
	std::string GetAdjencyList(Node* node)
	{
		std::vector<Node*> allNodes;
		CollectAllNodes(node, allNodes);
		std::string str = "[";
		for (int i = 0; i < allNodes.size(); i++)
		{
			std::stringstream cur;
			cur << "[";
			for (int n = 0; n < allNodes[i]->neighbors.size(); n++)
			{
				cur << allNodes[i]->neighbors[n]->val;
				if (n != allNodes[i]->neighbors.size() - 1)
					cur << ",";
			}
			cur << "]";
			if (i != allNodes.size() - 1)
				cur << ",";
			str += cur.str();
		}
		str += "]";
		return str;
	}

	void CollectAllNodes(Node* node, std::vector<Node*>& allNodes)
	{
		if (!node)
			return;

		bool existed = false;
		if (node->val > allNodes.size())
		{
			allNodes.resize(node->val, nullptr);
			allNodes[node->val - 1] = node;
		}
		else
		{
			if (allNodes[node->val - 1])
				existed = true;
			else
				allNodes[node->val - 1] = node;
		}

		if (!existed)
		{
			for (auto neighbor : node->neighbors)
				CollectAllNodes(neighbor, allNodes);
		}
	}
};