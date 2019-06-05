#include "TestCase.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
	struct Data
	{
		int timestamp;
		string value;

		Data() {}
		Data(int t, const string& v) : timestamp(t), value(v) {}
	};
	using DataMap = unordered_map<string, vector<Data>>;

public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		time_map[key].push_back(Data(timestamp, value));
	}

	string get(string key, int timestamp) {
		DataMap::const_iterator it = time_map.find(key);
		if (it != time_map.end())
		{
			const vector<Data>& arr = it->second;
			int index = BinarySearch(arr, timestamp, 0, (int)arr.size() - 1);
			if (index >= 0 && index < (int)arr.size())
				return arr[index].value;
		}
		return "";
	}

protected:
	DataMap time_map;

	int BinarySearch(const vector<Data>& arr, int timestamp, int low, int high)
	{
		if (low > high)
        {
            if (low - 1 < 0)
                return -1;
            else
                return low - 1;
        }
		int mid = low + (high - low) / 2;
		if (timestamp == arr[mid].timestamp)
			return mid;
		else if (timestamp > arr[mid].timestamp)
		{
            return BinarySearch(arr, timestamp, mid+1, high);
		}
		else
		{
            return BinarySearch(arr, timestamp, low, mid-1);
		}
	}
};

/**
* Your TimeMap object will be instantiated and called as such:
* TimeMap* obj = new TimeMap();
* obj->set(key,value,timestamp);
* string param_2 = obj->get(key,timestamp);
*/

RUN_TESTCASE(TimeBasedKVStore)
{
	TimeMap kv;
	kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
	TESTCASE_ASSERT(kv.get("foo", 1) == "bar");  // output "bar"   
	TESTCASE_ASSERT(kv.get("foo", 3) == "bar"); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
	kv.set("foo", "bar2", 4);
	TESTCASE_ASSERT(kv.get("foo", 4) == "bar2"); // output "bar2"   
	TESTCASE_ASSERT(kv.get("foo", 5) == "bar2"); //output "bar2"  
}
