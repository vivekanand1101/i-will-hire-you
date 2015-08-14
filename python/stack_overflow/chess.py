# http://stackoverflow.com/questions/31997436/python-classes-and-for-loop-error/31997843#31997843

#python 3
class Chess:
    def __init__ (self):
        self.board = self.create_board ()

    def create_board (self):
        board_x = []
        for x in range (8):
            board_y = []
            for y in range (8):
                board_y.append ('.')
            board_x.append (board_y)

        return board_x

    def display_board (self):
        for i in range (8):
            for j in range (8):
                print (self.board[i][j], end="")
            print()

game = Chess()
game.display_board()
