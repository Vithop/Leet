def maximalSquare(self, matrix):
        if not matrix:
            return 0
        r_len = len(matrix)
        c_len = len(matrix[0]) if r_len > 0 else 0
        
        counted_matrix = [0] * (c_len+1)
        max_sqr = 0
        temp = 0
        prev = 0
        
        for i in range(r_len):
            for j in range(c_len):
                temp = counted_matrix[j+1]
                if matrix[i][j] == '1':
                    counted_matrix[j+1] = min(prev, counted_matrix[j], counted_matrix[j+1]) + 1
                    max_sqr = max(max_sqr, counted_matrix[j+1])
                else:
                    counted_matrix[j+1] = 0
                prev = temp        
        return max_sqr * max_sqr