#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Task
    {
        int label;
        int enqueueTime;
        int processingTime;

        bool operator<(const Task& other) const {
            if (this->processingTime != other.processingTime) {
                    return this->processingTime > other.processingTime; 
            }
            // Secondary condition (Tie-breaker): Smaller label first
            return this->label > other.label;
        }
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // 1. Store tasks with their original indices
        vector<Task> allTasks(n);
        for (int i = 0; i < n; i++) {
            allTasks[i] = {i, tasks[i][0], tasks[i][1]};
        }

        // 2. Sort tasks by their enqueue (arrival) time
        sort(allTasks.begin(), allTasks.end(), [](const Task& a, const Task& b) {
            return a.enqueueTime < b.enqueueTime;
        });

        vector<int> res;
        priority_queue<Task> pq; // Min-heap for available tasks
        
        long long currentTime = 0; // Use long long to prevent potential overflow
        int taskIdx = 0;           // Pointer for sorted allTasks vector

        // Loop until all tasks are processed
        while (res.size() < n) {
            
            // Push all tasks that have arrived by the currentTime into the pool
            while (taskIdx < n && allTasks[taskIdx].enqueueTime <= currentTime) {
                pq.push(allTasks[taskIdx]);
                taskIdx++;
            }

            if (pq.empty()) {
                // If no tasks are available, fast-forward time to the next available task
                currentTime = allTasks[taskIdx].enqueueTime;
            } else {
                // Process the best task from the priority queue
                Task currentTask = pq.top();
                pq.pop();
                
                res.push_back(currentTask.label);
                // Advance the time by the duration of the processed task
                currentTime += currentTask.processingTime;
            }
        }
        
        return res;
    }
};