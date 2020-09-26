class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
      for(int i = 0; i<points.size() - 1 ; i++){
        int diffx = abs(points[i][0] - points[i+1][0]);
        int diffy = abs(points[i][1] - points[i+1][1]);
        time += diffx > diffy ? diffx: diffy;
      }
      return time;
      
    }
};