class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,vector<string>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int x,y,flg = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                {
                    x = i;
                    y = j;
                    flg = 1;
                    break;
                }
            }
            if(flg)
            break;
        }
        for(int i=0;i<n;i++)
        {
            for(auto &j:grid[i])
            {
                if(j>='a' && j<='f')
                cnt++;
            }
        }
        set<char> key;
        map<pair<set<char>,pair<int,int>>,int> vis;
        queue<pair<set<char>,pair<int,int>>> q;
        vis[{key,{x,y}}] = 1;
        q.push({key,{x,y}});
        int ans = 0;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                key = q.front().first;
                x = q.front().second.first;
                y = q.front().second.second;
                q.pop();
                char c = grid[x][y];
                if(c>='a' && c<='f')
                key.insert(c);
                if(key.size()==cnt)
                return ans;
                for(int j=0;j<4;j++)
                {
                    int newx = x+dx[j];
                    int newy = y+dy[j];
                    if(isValid(newx,newy,grid))
                    {
                        c = grid[newx][newy];
                        
                        if(c=='#')
                        continue;
                        if(c>='A' && c<='F' && key.find(tolower(c))==key.end())
                        continue;
                        
                        if(vis.find({key,{newx,newy}})==vis.end())
                        {
                            vis[{key,{newx,newy}}] = 1;
                            q.push({key,{newx,newy}});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};