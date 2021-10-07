#include "TestCase.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		_twitters[userId].insert(tweetId);

		int curSize = (int)_sort_index.size();
		_sort_index[tweetId] = curSize;

		_userDirty[userId] = true;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		if (isDirty(userId))
			updateNewsFeed(userId);

		vector<int> ret;
		vector<int> h = _newsFeed[userId];
		while (h.size() > 0 && ret.size() < 10)
		{
			std::pop_heap(h.begin(), h.end(), [&](int a, int b) -> bool {
				return _sort_index[a] < _sort_index[b];
			});

			ret.push_back(h.back());
			h.pop_back();
		}
		return ret;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
		{
			_followMap[followerId].insert(followeeId);
			_userDirty[followerId] = true;
		}
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		auto it = _followMap.find(followerId);
		if (it != _followMap.end())
		{
			it->second.erase(followeeId);
			if (it->second.empty())
				_followMap.erase(it);
			_userDirty[followerId] = true;
		}
	}

protected:
	unordered_map<int, int> _sort_index;
	unordered_map<int, unordered_set<int>> _twitters;
	unordered_map<int, unordered_set<int>> _followMap;
	unordered_map<int, vector<int>> _newsFeed;
	unordered_map<int, bool> _userDirty;

	void updateNewsFeed(int userId)
	{
		vector<int>& result = _newsFeed[userId];
		result.clear();

		collectNews(result, userId);
		for (auto followId : _followMap[userId])
		{
			collectNews(result, followId);
		}
	}

	void collectNews(vector<int>& result, int userId)
	{
		auto sorter_func = [&](int a, int b) -> bool {
			return _sort_index[a] < _sort_index[b];
		};

		auto it = _twitters.find(userId);
		if (it != _twitters.end())
		{
			for (auto n : it->second)
			{
				result.push_back(n);
				std::push_heap(result.begin(), result.end(), sorter_func);
			}
		}
	}

	bool isDirty(int userId)
	{
		if (_userDirty[userId])
			return true;

		for (int follow : _followMap[userId])
		{
			if (_userDirty[follow])
				return true;
		}

		return false;
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
RUN_TESTCASE(DesignTwitter)
{
	Twitter twitter;

	// User 1 posts a new tweet (id = 5).
	twitter.postTweet(1, 5);
	twitter.postTweet(1, 3);
	twitter.postTweet(1, 101);
	twitter.postTweet(1, 13);
	twitter.postTweet(1, 10);
	twitter.postTweet(1, 2);
	twitter.postTweet(1, 94);
	twitter.postTweet(1, 505);
	twitter.postTweet(1, 333);
	twitter.postTweet(1, 22);
	twitter.postTweet(1, 11);

	// User 1's news feed should return a list with 1 tweet id -> [5].
	printVector(twitter.getNewsFeed(1));
}