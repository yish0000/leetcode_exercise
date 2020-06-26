#include "TestCase.h"
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

class AStarOpenList
{
	enum
	{
		MAX_OPENLIST_SIZE = 30,
	};

public:
	struct Node
	{
		int x, y;
		int pre_x = -1, pre_y = -1;
		int g, h;

		Node() {}
		Node(int _x, int _y, int _g, int _h) : x(_x), y(_y), g(_g), h(_h) {}

		bool operator < (const Node& rhs) const
		{
			return (g + h) < (rhs.g + rhs.h);
		}

		bool operator > (const Node& rhs) const
		{
			return (g + h) > (rhs.g + rhs.h);
		}
	};

protected:
	vector<Node> _queue;

public:
	void PushNode(const Node& node)
	{
		if (_queue.size() >= MAX_OPENLIST_SIZE)
		{
			int iMax = 0;
			for (int i = 1; i < _queue.size(); i++)
			{
				if (_queue[i].g + _queue[i].h > _queue[iMax].g + _queue[iMax].h)
					iMax = i;
			}
			_queue[iMax] = node;
			std::make_heap(_queue.begin(), _queue.end(), std::greater<Node>());
		}
		else
		{
			_queue.push_back(node);
			std::push_heap(_queue.begin(), _queue.end(), std::greater<Node>());
		}
	}

	void PopNode(Node& node)
	{
		std::pop_heap(_queue.begin(), _queue.end(), std::greater<Node>());
		node = _queue.back();
		_queue.pop_back();
	}

	void ReSort()
	{
		std::make_heap(_queue.begin(), _queue.end(), std::greater<Node>());
	}

	void Clear()
	{
		_queue.clear();
	}

	Node* Find(int x, int y)
	{
		for (auto& node : _queue)
		{
			if (node.x == x && node.y == y)
				return &node;
		}

		return nullptr;
	}

	size_t Size() const
	{
		return _queue.size();
	}
};

class AStarCloseList
{
public:
	struct Node
	{
		int x, y;
		int pre_x = -1, pre_y = -1;

		Node() {}
		Node(int _x, int _y) : x(_x), y(_y) {}
		Node(int _x, int _y, int _pre_x, int _pre_y) : x(_x), y(_y), pre_x(_pre_x), pre_y(_pre_y) {}
		Node(AStarOpenList::Node& _node) : x(_node.x), y(_node.y), pre_x(_node.pre_x), pre_y(_node.pre_y) {}

		bool operator < (const Node& rhs) const
		{
			return x < rhs.x || (x == rhs.x && y < rhs.y);
		}

		bool operator == (const Node& rhs) const
		{
			return x == rhs.x && y == rhs.y;
		}
	};

protected:
	set<Node> _set;

public:
	void AddNode(const Node& node)
	{
		_set.insert(node);
	}

	bool Find(int x, int y)
	{
		return _set.find(Node(x, y)) != _set.end();
	}

	bool GetPre(int x, int y, int& pre_x, int& pre_y)
	{
		set<Node>::iterator it = _set.find(Node(x, y));
		if (it != _set.end())
		{
			pre_x = it->pre_x;
			pre_y = it->pre_y;
			return true;
		}

		return false;
	}
};

class SolutionAStar
{
	const int dir[8][2] = {
		{-1,0},
		{-1,1},
		{0,1},
		{1,1},
		{1,0},
		{1,-1},
		{0,-1},
		{-1,-1},
	};

public:
	vector<pair<int, int>> find_path(vector<vector<char>>& map, pair<int, int> start, pair<int, int> end)
	{
		if (map.empty() || map[0].empty())
			return vector<pair<int, int>>();

		_start = start;
		_end = end;

		bool bFound = false;
		_open_list.PushNode(AStarOpenList::Node(start.first, start.second, 0, 0));
		
		while (_open_list.Size() > 0)
		{
			AStarOpenList::Node curNode;
			_open_list.PopNode(curNode);
			_close_list.AddNode(curNode);
			if (curNode.x == end.first && curNode.y == end.second)
			{
				bFound = true;
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int new_x = curNode.x + dir[i][0];
				int new_y = curNode.y + dir[i][1];
				if (new_y < 0 || new_y >= map.size() || new_x < 0 || new_x >= map[0].size())
					continue;

				if (map[new_y][new_x] || _close_list.Find(new_x, new_y))
					continue;

				AStarOpenList::Node* node = _open_list.Find(new_x, new_y);
				if (!node)
				{
					AStarOpenList::Node newNode;
					newNode.x = new_x;
					newNode.y = new_y;
					newNode.pre_x = curNode.x;
					newNode.pre_y = curNode.y;
					newNode.g = G(curNode, i);
					newNode.h = H(new_x, new_y);
					_open_list.PushNode(newNode);
				}
				else
				{
					int g = G(curNode, i);
					int h = H(new_x, new_y);
					if (g + h < node->g + node->h)
					{
						node->g = g;
						node->h = h;
						_open_list.ReSort();
					}
				}
			}
		}

		vector<pair<int, int>> path;
		if (bFound)
		{
			int x = end.first;
			int y = end.second;
			while (x != start.first || y != start.second)
			{
				path.push_back(make_pair(x, y));

				int pre_x, pre_y;
				if (_close_list.GetPre(x, y, pre_x, pre_y))
				{
					x = pre_x;
					y = pre_y;
				}
				else
					break;
			}
			path.push_back(make_pair(start.first, start.second));
			std::reverse(path.begin(), path.end());
		}

		return path;
	}

	int G(AStarOpenList::Node& lastNode, int i)
	{
		return lastNode.g + (dir[i][0] == 0 || dir[i][1] == 0) ? 10 : 14;
	}

	int H(int x, int y)
	{
		// Manhattan distance
		return (abs(x - _end.first) + abs(y - _end.second)) * 10;
	}

protected:
	pair<int, int> _start;
	pair<int, int> _end;
	AStarOpenList _open_list;
	AStarCloseList _close_list;
};

RUN_TESTCASE(AStar)
{
	SolutionAStar sln;

	vector<vector<char>> map =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	pair<int, int> start = { 10, 12 };
	pair<int, int> end = { 20, 15 };
	vector<pair<int, int>> path = sln.find_path(map, start, end);
	if (path.size() > 0)
	{
		for (auto& p : path)
			map[p.second][p.first] = 2;

		for (auto line : map)
		{
			for (auto ch : line)
			{
				if (ch == 0)
					cout << " .";
				else
					cout << char(ch + '0') << '.';
			}

			cout << endl;
		}
	}
	else
	{
		cout << "Cannot find the path!" << endl;
	}
}