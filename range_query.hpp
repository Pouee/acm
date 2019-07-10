/*
	FN comparator
	ROW the size of array's row
	COLUMN the size of array's column,log(ROW)+1 is recommanded
	T the type of operation
*/
template<typename FN, int ROW,int COLUMN, typename T = long long int>
struct range_query{
	range_query(){
		zero();
	}
	// clear all data
	void zero(){
		// 
		length = 0;
	}
	// 
	void push_back(const T &t){
		dp[length++][0] = t;
	}
	void initRMQ(){
		for (int j = 1; 1 << j <= ROW; ++j){
			for (int i = 0; i + (1 << j) - 1 < ROW; ++i){
				dp[i][j] = f(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	T RMQ(int L, int R)
	{
		int k = 0;
		while ((1 << (k + 1)) <= R - L + 1)++k;
		return f(dp[L][k], dp[R - (1 << k) + 1][k]);
	}
	T dp[ROW][COLUMN];
	int length;
private:
	FN f;
};