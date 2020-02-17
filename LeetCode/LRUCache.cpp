#include "TestCase.h"
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
	struct LinkedNode
	{
		int key;
		int value;
		LinkedNode* prev;
		LinkedNode* next;

		LinkedNode(int _key, int _value)
			: key(_key), value(_value), prev(nullptr), next(nullptr)
		{
		}
	};

public:
	LRUCache(int capacity)
		: _capacity(capacity)
		, _headNode(nullptr)
		, _tailNode(nullptr)
	{
		_map.reserve(capacity);
	}

	~LRUCache()
	{
		while (_headNode)
		{
			LinkedNode* cur = _headNode;
			_headNode = _headNode->next;
			delete cur;
		}
	}

	int get(int key) {
		unordered_map<int, LinkedNode*>::iterator it = _map.find(key);
		if (it != _map.end())
		{
			removeNode(it->second);
			addNode(it->second);
			return it->second->value;
		}

		return -1;
	}

	void put(int key, int value) {
		unordered_map<int, LinkedNode*>::iterator it = _map.find(key);
		if (it != _map.end())
		{
			it->second->value = value;
			removeNode(it->second);
			addNode(it->second);
			return;
		}

		if (_map.size() < _capacity)
		{
			LinkedNode* newNode = new LinkedNode(key, value);
			_map[key] = newNode;
			addNode(newNode);
		}
		else
		{
			LinkedNode* oldNode = _headNode;
			removeNode(oldNode);
			_map.erase(oldNode->key);
			oldNode->key = key;
			oldNode->value = value;
			_map[key] = oldNode;
			addNode(oldNode);
		}
	}

private:
	int _capacity;
	unordered_map<int, LinkedNode*> _map;
	LinkedNode* _headNode;
	LinkedNode* _tailNode;

private:
	void addNode(LinkedNode* node)
	{
		if (!_headNode)
		{
			_headNode = node;
			_tailNode = node;
		}
		else
		{
			_tailNode->next = node;
			node->prev = _tailNode;
			_tailNode = node;
		}
	}

	void removeNode(LinkedNode* node)
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		if (node == _headNode)
			_headNode = node->next;
		if (node == _tailNode)
			_tailNode = node->prev;
		node->prev = node->next = nullptr;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
RUN_TESTCASE(LRUCache)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	TESTCASE_ASSERT(cache.get(1) == 1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	TESTCASE_ASSERT(cache.get(2) == -1);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	TESTCASE_ASSERT(cache.get(1) == -1);       // returns -1 (not found)
	TESTCASE_ASSERT(cache.get(3) == 3);       // returns 3
	TESTCASE_ASSERT(cache.get(4) == 4);       // returns 4
}