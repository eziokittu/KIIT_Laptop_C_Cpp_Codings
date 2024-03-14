// LeetCode Problem 2402 - Meeting Rooms 3
// https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2024-02-18

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// int getRoomAvailable(int start, unordered_map<int, int> occupied){
//     for (auto m : meetings){
        
//     }
// }

// void delayMeetings(vector<vector<int>>& meetings, int delay){
    
// }

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++){
        v.push_back({i,0});
        // cout << v[i].first<<endl;
    }
    

    // unordered_map<int, int> occupied;
    for (auto m : meetings){
        // for (int i=0; i<v.size(); i++){
        //     if (v[i].second <= m[0]){
        //         v[i].second += (m[1]-m[0]);
        //         occupied[v[i].first]++;
        //         cout << "DEBUG "<<v[i].first<<"\n";
        //         break;
        //     }
        // }
    }

    // int room=n, max = -1;
    // for (auto i : occupied){
    //     cout << "Room "<<i.first<<" occupied "<<i.second<<" times.\n";
    //     if (i.second > max){
    //         max = i.second;
    //         if (room > i.first){
    //             room = i.first;
    //         }
    //     }
    // }
    // return room;
}

int main()
{
    vector<vector<int>> meetings1 = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    vector<vector<int>> meetings2 = {{0,10},{1,5},{2,7},{3,4}}; 
    cout << mostBooked(2, meetings1);

    return 0;
}
// 0  0
// 20 0
// 20 10
// 20 12
// 20 21
// 28 21