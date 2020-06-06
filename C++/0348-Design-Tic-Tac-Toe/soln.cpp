class TicTacToe {
    int n;
    map<pair<int, int>, int> player1;
    map<pair<int, int>, int> player2;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        map<pair<int, int>, int> * ptr;
        if (player == 1) {
            ptr = & player1;
        } else {
            ptr = & player2;
        }
        vector<pair<int, int>> conditions = {{1, row}, {2, col}, {3, row + col}, {4, row - col}};
        for(auto condition : conditions) {
            ++(*ptr)[condition];
            if ((*ptr)[condition] == n) return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
