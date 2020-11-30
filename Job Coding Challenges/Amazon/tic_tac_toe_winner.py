
def tic_tac_toe_winner(board):
    # matrix will be 1d array of chars
    # chars will either 'X', 'O', ''
        
    win_path = [[0, 1, 2],[ 3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4,7], [2,5,8], [0,4,8], [2,4,6]]
    tie_count = 0
    
    for path in win_path:
        num_0 = 0
        num_X = 0
        for i in path:
            if board[i] == 'O':
                num_O += 1
                tie_count += 1
            elif board[i] == 'X':
                num_X += 1
                tie_count += 1
        if num_O == 3: 
            return 0
        if num_x == 3:
            return 1
        
    if tie_count == 9:
        return 'draw'
    else 
        return 'in progress'
        