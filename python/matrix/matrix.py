"""
row(index) -> Returns a list with the data for specified raw.

Input example: "1 2\n10 20")
matrix.row(2) => [10, 20]

"""


class Matrix:
    def __init__(self, matrix_string):
        self.rows = [[int(element) for element in row.split(" ")]
                     for row in matrix_string.split("\n")]

    def row(self, index):
        return self.rows[index - 1]

    def column(self, index):
        column = []
        for row in self.rows:
            column.append(row[index - 1])
        return column
