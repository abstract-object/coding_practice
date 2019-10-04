from random import randint

def getinput(board):
  validinput = False
  while not validinput:
    choice = raw_input("Choose your target (X##): ")
    choice = choice.upper()
    if len(choice) == 3:
      if ord(choice[0]) >= ord("A") and ord(choice[0]) <= ord("J"):
        if choice[1] == "0":
          if ord(choice[2]) >= ord("1") and ord(choice[2]) <= ord("9"):
            validinput = True
        elif choice[1] == "1" and choice[2] == "0":
            validinput = True
    if validinput == True:
      if board[int(choice[1:])][ord(choice[:1]) - 64] != "~":
        validinput = False
        print "You have previously selected that location."
      else:
        board[int(choice[1:])][ord(choice[:1]) - 64] = "*"
  return board

def play(board, ships):
  showboard(board)
  board = getinput(board)
  for i in range(len(ships)):
    for j in range(3, len(ships[str(i)])):
      if board[ships[str(i)][j][0]][ships[str(i)][j][1]] == "*":
        board[ships[str(i)][j][0]][ships[str(i)][j][1]] = "X"
        ships[str(i)][j] = [0, 0]
  won = True
  for i in range(len(ships)):
    ships[str(i)][2] = True
    for j in range(3, len(ships[str(i)])):
        if ships[str(i)][j][0] != 0:
          ships[str(i)][2] = False
    if ships[str(i)][2] == True:
      print "Enemy " + ships[str(i)][0] + " has been sunk."
    else:
      won = False
  return board, ships, won

def setup():
  board = [[], []]
  board[0].append(["  "] + [chr(num) for num in range (ord("A"), ord("J") + 1)])
  for i in range(9):
    board[0].append(["0" + str(i + 1)] + ["~"] * 10)
  board[0].append(["10"] + ["~"] * 10)

  ships = [{
  "0": ["Carrier", 5, False],
  "1": ["Battleship", 4, False],
  "2": ["Cruiser", 3, False],
  "3": ["Submarine", 3, False],
  "4": ["Destroyer", 2, False]
  }, {
  "0": ["Carrier", 5, False], "1": ["Battleship", 4, False], "2": ["Cruiser", 3, False], "3": ["Submarine", 3, False], "4": ["Destroyer", 2, False]}]

  for i in range(len(ships[0])):
    placeable = False
    shiplength = ships[0][str(i)][1]
    while not placeable:
      maxposition = randint(1, 11 - shiplength)
      orientation = randint(1, 2)
      if orientation == 1:
        row = maxposition
        col = randint(1, 10)
      else:
        row = randint(1, 10)
        col = maxposition
      if board[0][row][col] == "~":
        for j in range(1, shiplength):
          if orientation == 1:
            if board[0][row + j][col] != "~":
              placeable = False
              break
            else:
              placeable = True
          else:
            if board[0][row][col + j] != "~":
              placeable = False
              break
            else:
              placeable = True
    for k in range(0, shiplength):
      if orientation == 1:
        board[0][row + k][col] = "X"
        ships[0][str(i)].append([row + k, col])
      else:
        board[0][row][col + k] = "X"
        ships[0][str(i)].append([row, col + k])
  return board[1], ships

def showboard(board):
  for row in board[0]:
    print " ".join(row)

def startgame():
  board = [[], []]
  board[0].append(["  "] + [chr(num) for num in range(ord("A"), ord("J") + 1)])
  for i in range(9):
    board[0].append(["0" + str(i + 1)] + ["~"] * 10)
  board[0].append(["10"] + ["~"] * 10)
  board[1], ships = setup()
  return board, ships

print "Welcome to Battleship."
board, ships = startgame()
won = True
while 1 == 1:
  if won:
    dummy = raw_input("Press any key to start the game.")
    won = False
  else:
    board, ships, won = play(board, ships)
    if won:
      showboard(board)
      print "Congratulations. You have won the game."
