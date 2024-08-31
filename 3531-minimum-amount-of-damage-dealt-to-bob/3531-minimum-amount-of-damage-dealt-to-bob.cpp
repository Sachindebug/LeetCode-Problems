class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, int>> enemies;

        for(int i=0;i<n;i++)
        {
            enemies.push_back({damage[i], health[i]});
        }

        sort(enemies.begin(), enemies.end(), [power](pair<int, int>& a, pair<int, int>& b)
        {
            double ratioA = (double)a.first / (double)((a.second + power - 1) / power);
            double ratioB = (double)b.first / (double)((b.second + power - 1) / power);
            return ratioA > ratioB;
        });

        long long totalDamage = 0;
        long long currDamage = 0;

        for(auto& enemy : enemies)
        {
            currDamage += enemy.first;
        }

        for(auto& enemy : enemies)
        {
            int count = (enemy.second + power - 1) / power;
            totalDamage += count * currDamage;
            currDamage -= enemy.first;
        }

        return totalDamage;
    }
};