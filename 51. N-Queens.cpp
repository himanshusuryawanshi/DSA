class Solution {
    
private:
    bool check(vector<string>& board, int row, int col) {
	int n = size(board);
	for(int i = 0; i < n; i++) {
		if(board[i][col] == 'Q') return false;  
		// checking all diagonals-
		if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
		if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false;
	}
	return true;
}
// Recursive solver - 
void solve(vector<string>& board, int row) {
 
	if(row == size(board)) { 
		sols.push_back(board);
		return;
	}            
	 
	for(int col = 0; col < size(board); col++) 
		if(check(board, row, col)) {
			board[row][col] = 'Q';    // Queen placed on a valid cell
			solve(board, row + 1);    // exploring next row
			board[row][col] = '.';    // backtracking to get all possible solutions
		}            
}
    
public:
    vector<vector<string> > sols;
vector<vector<string>> solveNQueens(int n) {    
	vector<string> board(n, string(n, '.'));  // creating an empty board
	solve(board, 0);
	return sols;
}
};
