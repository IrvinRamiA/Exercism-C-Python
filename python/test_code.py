matrix_string = "1 2 3\n4 5 6"

rows = [row for row in matrix_string.split("\n")]
print(rows)

rows = [int(element) for element in rows.split(" ")]

