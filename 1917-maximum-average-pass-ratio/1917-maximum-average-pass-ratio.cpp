class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

         auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max-heap to prioritize classes with the greatest improvement potential
        priority_queue<pair<double, pair<int, int>>> pq;

        int n = classes.size();

        // Add initial class ratios to the priority queue
        for (auto elem : classes) {
            int pass = elem[0];
            int total = elem[1];
           
            // The improvement for adding one student
            pq.push({calculateGain(pass, total),
                          {pass, total}});
            
        }

        // Distribute extra students to maximize the average ratio
        while (extraStudents--) {
            // Get the class with the highest potential improvement
            auto curr = pq.top();
            pq.pop();
            int pass = curr.second.first;
            int total = curr.second.second;

            // Update the class by adding one student
            int newPass = pass + 1;
            int newTotal = total + 1;

            // Calculate the new improvement after adding one student
           pq.push({calculateGain(newPass, newTotal),
                          {newPass, newTotal}});
        }

        // Sum up the final average ratios
        double sum = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int pass = curr.second.first;
            int total = curr.second.second;
            sum += (double) pass / total;
        }

        // Return the average with precision
        return sum / n;
    }
};
