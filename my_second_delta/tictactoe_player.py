import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray


class ticTacToePlayerNode(Node):

    def __init__(self):
        super().__init__('plc_writer_node')
        self.publisher_ = self.create_publisher(Float64MultiArray, 'pre_plc_tags_write', 10)
        self.subscription = self.create_subscription(
            Float64MultiArray,
            'plc_tags_read',
            self.listener_callback,
            10)
        self.subscription  # prevent unused subscription warning
        self.last_known_enemy_position = None
        self.game_board = [['-' for _ in range(3)] for _ in range(3)]  # Initialize the game board
        self.start_game = 0  # Initialize start_game to 0
        self.game_ended = 0
        self.game_won = 0


    def update_game_board(self, row, col, player):
        self.game_board[row][col] = player

    def determine_best_move(self, grid):
        # Count the number of 'X's and 'O's on the board
        count_X = sum(row.count('X') for row in grid)
        count_O = sum(row.count('O') for row in grid)

        # If there's already an 'X' and no 'O's, don't place another 'X'
        if count_X >= (count_O+1):
            return None, None  # Return None to indicate no move should be made under these conditions

        # Proceed with the existing logic to determine the best move
        # Check for winning moves
        for row in range(3):
            for col in range(3):
                if grid[row][col] == '-':
                    temp_grid = [list(row) for row in grid]  # Copy the grid
                    temp_grid[row][col] = 'X'  # Temporarily place our move
                    if self.is_winning_move(temp_grid) == 'X':
                        self.game_ended = 1
                        self.game_won = 1
                        return row, col  # Return the winning move

        # Block opponent's winning moves
        for row in range(3):
            for col in range(3):
                if grid[row][col] == '-':
                    temp_grid = [list(row) for row in grid]  # Copy the grid
                    temp_grid[row][col] = 'O'  # Temporarily place opponent's move
                    if self.is_winning_move(temp_grid) == 'O':
                        return row, col  # Return the blocking move

        # Center control
        if grid[1][1] == '-':
            return 1, 1  # Center square

        # Corner control
        corners = [(0, 0), (0, 2), (2, 0), (2, 2)]
        for corner in corners:
            if grid[corner[0]][corner[1]] == '-':
                return corner  # Return the first available corner

        # Edge control
        edges = [(0, 1), (1, 0), (1, 2), (2, 1)]
        for edge in edges:
            if grid[edge[0]][edge[1]] == '-':
                return edge  # Return the first available edge


    def is_winning_move(self, grid):
        # Check rows and columns
        for i in range(3):
            if grid[i][0] == grid[i][1] == grid[i][2] != '-':
                return grid[i][0]  # Return the winner (X or O)
            if grid[0][i] == grid[1][i] == grid[2][i] != '-':
                return grid[0][i]  # Return the winner (X or O)

        # Check diagonals
        if grid[0][0] == grid[1][1] == grid[2][2] != '-':
            return grid[0][0]  # Return the winner (X or O)
        if grid[0][2] == grid[1][1] == grid[2][0] != '-':
            return grid[0][2]  # Return the winner (X or O)

        return None  # No winner yet
    
    def reset_game(self):
        self.game_board = [['-' for _ in range(3)] for _ in range(3)]
        self.game_state = False
        self.get_logger().info("Game has been reset.")



    def listener_callback(self, msg):
        # Extract relevant data from the message
        enemy_row = int(msg.data[3])
        enemy_col = int(msg.data[4])
        starting_player = int(msg.data[5])  # 0 if our player starts, 1 otherwise
        start_game = int(msg.data[6])

        self.start_game = start_game

        # Initialize the message to be published
        msg = Float64MultiArray()

        if start_game == 1:
            # If we start and there's no enemy move yet, make the initial move
            if starting_player == 0 and enemy_row == -1 and enemy_col == -1:
                best_play_row, best_play_col = self.determine_best_move(self.game_board)
                if best_play_row is not None and best_play_col is not None:
                    self.update_game_board(best_play_row, best_play_col, 'X')  # Update the board with our move
                    msg.data = [float(best_play_row), float(best_play_col), float(self.game_ended), float(self.game_won)]
                    self.publisher_.publish(msg)
                    self.last_known_enemy_position = (-1, -1)
                    
            # If it's the enemy's turn and the position has changed, update the game board
            elif (enemy_row, enemy_col)!= self.last_known_enemy_position:
                self.last_known_enemy_position = (enemy_row, enemy_col)
                self.update_game_board(enemy_row, enemy_col, 'O')  # Update the board with the enemy's move

                # Check for a win after the enemy's move
                winner = self.is_winning_move(self.game_board)
                if winner:
                    self.get_logger().info(f"Game Over Winner: {winner}")
                    self.game_ended = 1  # Set game ended flag
                    if winner == 'X':  # If 'X' wins
                        self.game_won = 1  # Set game won flag for 'X'
                    return  # Exit early if the game is over

                # Determine and publish the best play coordinates
                best_play_row, best_play_col = self.determine_best_move(self.game_board)
                if best_play_row is not None and best_play_col is not None:
                    self.update_game_board(best_play_row, best_play_col, 'X')  # Update the board with our move
                    msg.data = [float(best_play_row), float(best_play_col), float(self.game_ended), float(self.game_won)]
                    self.publisher_.publish(msg)

                    # Check for a win after our move
                    winner = self.is_winning_move(self.game_board)
                    if winner:
                        self.get_logger().info(f"Game Over Winner: {winner}")
                        self.game_ended = 1  # Set game ended flag
                        if winner == 'X':  # If 'X' wins
                            self.game_won = 1  # Set game won flag for 'X'
                        
                        return  # Exit early if the game is over

            # Log the entire game board
            self.get_logger().info("Current Game Board:")
            for row in self.game_board:
                self.get_logger().info(' '.join(row))
        
        else:
            self.last_known_enemy_position = None
            msg.data = [float(0), float(0), float(0), float(0)]
            self.publisher_.publish(msg)
            self.reset_game()



        




def main(args=None):
    rclpy.init(args=args)

    tic_tac_toe_node = ticTacToePlayerNode()

    rclpy.spin(tic_tac_toe_node)

    # Destroy the node explicitly
    tic_tac_toe_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
