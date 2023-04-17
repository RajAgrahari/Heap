//https://practice.geeksforgeeks.org/problems/00ae30d0e0f6d8877c68f8b8558c5b0138fdb4b7/1
priority_queue<pair<pair<int,int>,int>> pq;

        int vis[n+1] = {0};

        

        for(int i = 0;i<n;i++){

            pq.push({{arr[i].profit, arr[i].dead}, arr[i].id});

        }

        

        int ans = 0;

        int jobs = 0;

        while(!pq.empty()){

            int profit = pq.top().first.first;

            int dead = pq.top().first.second;

            int id = pq.top().second;

            pq.pop();

            

            for(int i = dead;i>=1;i--){

                if(vis[i] == 0){

                    vis[i] = 1;

                    jobs++;

                    ans += profit;

                    break;

                }

            }

        }

        return {jobs, ans};
