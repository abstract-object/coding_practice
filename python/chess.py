def setup():
  board = []
  board.append([" "] + [chr(i) for i in range (ord("A"), ord("H") + 1)])
  for i in range (1, 9):
    board.append([str(9 - i)] + ["_"] * 8)

  board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8] = "r", "n", "b", "q", "k", "b", "n", "r"
  board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8] = "R", "N", "B", "Q", "K", "B", "N", "R"
  for i in range (1, 9):
    board[2][i] = "p"
    board[7][i] = "P"

  cboard = []
  cboard.append([" "] + [chr(i) for i in range(ord("A"), ord("H") + 1)])
  for i in range (1, 9):
    cboard.append([str(9 - i)] + [""] * 8)

  for i in range(1, 9):
    for j in range(1, 9):
      cboard[i][j] = [board[i][j]] + [False, False]

  pieces = {}
  for i in range (1, 9):
    for j in range (1, 9):
      pieces[str(i) + str(j)] = []

  pieces = checkthreat(cboard, pieces)

  for i in range (1, 9):
    for j in range (1, 9):
      for o in range (0, len(pieces[str(i) + str(j)])):
        if len(pieces[str(i) + str(j)]) != 0:
          if cboard[i][j][0].isupper():
            cboard[int(pieces[str(i)+ str(j)][o][0])][int(pieces[str(i)+ str(j)][o][1])][1] = True
          elif cboard[i][j][0].islower():
            cboard[int(pieces[str(i)+ str(j)][o][0])][int(pieces[str(i)+ str(j)][o][1])][2] = True

  special = [False, False, ""]
  return board, cboard, pieces, special

def checkthreat(cboard, pieces):
  for i in range (1, 9):
    for j in range (1, 9):
      if cboard[i][j][0].upper() == "N":
        mindist = -2
        maxdist = 3
      elif cboard[i][j][0].upper() == "K" or cboard[i][j][0].upper() == "P":
        mindist = -1
        maxdist = 2
      else:
        mindist = -7
        maxdist = 8

      for k in range (mindist, maxdist):
          for l in range (mindist, maxdist):
            threat = False
            blocked = False
            if i + k >= 1 and i + k <= 8 and j + l >= 1 and j + l <= 8:
              if cboard[i + k][j + l][0] == "_" or not cboard[i][j][0].isupper() == cboard[i + k][j + l][0].isupper():
                if cboard[i][j][0].upper() == "N":
                  if max(k, l) ** 2 - min(k, l) ** 2 == 3:
                    threat = True
                elif cboard[i][j][0].upper() == "K":
                    threat = True
                elif cboard[i][j][0].upper() == "P":
                  if l ** 2 == 1:
                    if cboard[i][j][0].isupper():
                      if k == -1:
                        threat = True
                    elif cboard[i][j][0].islower():
                      if k == 1:
                        threat = True
                elif cboard[i][j][0].upper() == "B":
                  if k ** 2 == l ** 2:
                    threat = True
                elif cboard[i][j][0].upper() == "R":
                  if k == 0 or l == 0:
                    threat = True
                elif cboard[i][j][0].upper() == "Q":
                  if k ** 2 == l ** 2 or k == 0 or l == 0:
                    threat = True
                if cboard[i][j][0].upper() == "Q" or cboard[i][j][0].upper() == "B":
                  for m in range(0, max(i, i + k) - min(i, i + k)):
                    if m != 0 and i - m >= 1 and i + m < 9:
                      if k < -1 and l < -1:
                        if cboard[i - m][j - m][0] != "_":
                          blocked = True
                      elif k < -1 and l > 1:
                        if cboard[i - m][j + m][0] != "_":
                          blocked = True
                      elif k > 1 and l < -1:
                        if cboard[i + m][j - m][0] != "_":
                          blocked = True
                      elif k > 1 and l > 1:
                        if cboard[i + m][j + m][0] != "_":
                          blocked = True
                if cboard[i][j][0].upper() == "Q" or cboard[i][j][0].upper() == "R":
                  for m in range(0, max(i, i + k) - min(i, i + k)):
                    if m != 0 and i - m >= 1 and i + m < 9:
                      if k < -1:
                        if cboard[i - m][j][0] != "_":
                          blocked = True
                      elif k > 1:
                        if cboard[i + m][j][0] != "_":
                          blocked = True
                  for n in range(0, max(j, j + l) - min(j, j + l)):
                    if n != 0 and j - n >= 1 and j + n < 9:
                      if l < -1:
                        if cboard[i][j - n][0] != "_":
                          blocked = True
                      elif l > 1:
                        if cboard[i][j + n][0] != "_":
                          blocked = True

            if threat and not blocked:
              pieces[str(i) + str(j)].append([str(i + k), str(j + l)])
  return pieces

def move(board, cboard, pieces, special):


def showboard(board):
  for row in board:
    print "|".join(row) + "|"

board, cboard, pieces, special = setup()
showboard(board)
