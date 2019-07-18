#include "TestCase.h"
#include <set>

using namespace std;

class SolutionKeysAndRooms
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> entered(rooms.size());
        enterRoom(rooms, entered, 0);
        for (size_t i=0;i<rooms.size(); i++)
        {
            if (!entered[i])
                return false;
        }
        return true;
    }
    
    void enterRoom(vector<vector<int>>& rooms, std::vector<bool>& entered, int idx)
    {
        if (entered[idx])
            return;
        
        entered[idx] = true;
        
        vector<int>& room = rooms[idx];
        for (size_t i=0;i<room.size(); i++)
        {
            int to = room[i];
            enterRoom(rooms, entered, to);
        }
    }
};

RUN_TESTCASE(KeysAndRooms)
{
    SolutionKeysAndRooms sln;
    vector<vector<int>> input1 = {{1},{2},{3},{}};
    TESTCASE_ASSERT(sln.canVisitAllRooms(input1));
    vector<vector<int>> input2 = {{1,3},{3,0,1},{2},{0}};
    TESTCASE_ASSERT(!sln.canVisitAllRooms(input2));
}
