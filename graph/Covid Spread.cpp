/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

 


Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
Example 2:

Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a 2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.


Constraints:
1 ≤ R,C ≤ 1000
0 ≤ mat[i][j] ≤ 2
*/


class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int rows=hospital.size();
        int cols=hospital[0].size();
        
        queue<pair<int,int>> infected;
        int unInfected=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(hospital[i][j]==2){
                    infected.push({i,j});
                }else if(hospital[i][j]==1){
                    unInfected++;
                }
            }
        }
        if(unInfected==0){
            return 0;
        }else if(infected.size()==0){
            return -1;
        }
        
        int time=0;
        while(!infected.empty()){
            int sz=infected.size();
            while(sz>0){
                sz--;
                auto pos=infected.front();
                infected.pop();
                
                int x[4]={0,0,1,-1};
                int y[4]={1,-1,0,0};
                for(int i=0;i<4;i++){
                    int xi=pos.first+x[i];
                    int yj=pos.second+y[i];
                    
                    if(xi>=0 && xi<rows && yj>=0 && yj<cols && hospital[xi][yj]==1){
                        hospital[xi][yj]=2;
                        unInfected--;
                        infected.push({xi,yj});
                    }
                }
            }
            time++;
            if(unInfected==0){
                return time;
            }
        }
        return  -1;
    }
};