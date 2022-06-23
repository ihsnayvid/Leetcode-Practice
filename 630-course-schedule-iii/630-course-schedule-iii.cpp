class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        //for(auto i: courses) cout<<i[0] <<" "<<i[1]<<endl;
        
        int day = 0;
        priority_queue<int> pq;
        for(int i=0; i<courses.size(); i++){
            if(day + courses[i][0] <= courses[i][1]){
                day += courses[i][0];
                pq.push(courses[i][0]);
            }
            else{
                if(pq.size() > 0 and pq.top() > courses[i][0]){
                    day -= pq.top();
                    pq.pop();
                    day += courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
                
        }
        return pq.size();
    }
};