long tripleSteps(int, unordered_map<int,long> &memo);
long tripleSteps(int steps);
int main() {
    unordered_map<int,long> memo;
    //long result_Re = tripleSteps(30);
    //cout<< result_Re <<endl;

    long result = tripleSteps(50, memo );    

    cout<< result <<endl;
}
//using dynamic programming.
long tripleSteps(int steps, unordered_map<int,long> &memo){
    if(memo.find(steps) == memo.end()){
        long numOfSteps = 0;
        if(steps <= 1){
            return 1;
        }else if(steps == 2){
            return 2;
        }
        numOfSteps += tripleSteps(steps-3, memo)+tripleSteps(steps-2, memo)+tripleSteps(steps-1, memo);
        memo[steps] = numOfSteps;
        return numOfSteps;
    }else{
        return memo[steps];
    }
}

//using recursion.
long tripleSteps(int steps){
        long numOfSteps = 0;
        if(steps <= 1){
            return 1;
        }else if(steps == 2){
            return 2;
        }
        numOfSteps += tripleSteps(steps-3)+tripleSteps(steps-2)+tripleSteps(steps-1);
        return numOfSteps;
}
