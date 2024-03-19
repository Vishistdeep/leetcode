class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> f(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            f[tasks[i] - 'A']++;
        }
        
        sort(f.begin(), f.end(), greater<int>());

        int v = f[0] - 1;
        int idle = v * n;

        for (int i = 1; i < f.size() && idle > 0; i++) {
            idle -= min(v, f[i]);
        }

        idle = max(0, idle);

        return idle + tasks.size();
        
    }
};