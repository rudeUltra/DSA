class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
              sort(clips.begin(), clips.end());
              int n = clips.size();
              
              int start = 0, reach = 0, clips_req = 0;
        
              while(reach < time){
                  for(auto clip : clips){
                      if(start >= clip[0] && start <= clip[1]) reach = max(reach, clip[1]);
                  }
                  if(start == reach) return -1;
                  clips_req++;
                  start = reach;
              }
            return clips_req;
              
    }
};