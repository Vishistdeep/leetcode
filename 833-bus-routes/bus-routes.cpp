class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int max_stop = -1;
        for (auto route: routes) {
            for (auto stop: route) {
                max_stop = max(max_stop, stop);
            }
        }

        if (max_stop < target || max_stop < source) return -1;

        int n = routes.size();
        vector<int> dist(max_stop + 1, INT_MAX);
        dist[source] = 0;

        bool flag = true;
        while (flag) {
            flag = false;
            for (auto route: routes) {
                int min_dist = n + 1;
                for (auto stop: route) min_dist = min(min_dist, dist[stop]);
                min_dist++;

                for (auto stop: route) {
                    if (min_dist < dist[stop]) {
                        dist[stop] = min_dist;
                        flag = true;
                    }
                }
            }
        }

        return dist[target] < n + 1 ? dist[target] : -1;
    }
};