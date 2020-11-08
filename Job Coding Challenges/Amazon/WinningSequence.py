def winning_seq(size, low_end, high_end):
        delta = high_end - low_end
        if ((size < 3) or (high_end <= low_end) or (2*delta + 1 < size)):
            return -1

        end1 = high_end + 1
        start2 = high_end - 1

        if (size > delta + 1):
            end2 = low_end - 1
        else:
            end2 = high_end - size + 1

        if (size <= delta + 2):
            start1 = high_end - 1
        else:
            start1 = high_end - size + delta + 1

        return list(range(start1, end1)) + list(range(start2, end2, -1))


ans = winning_seq(5, 3, 10)

print('input 5, 3, 10: output', winning_seq(5, 3, 10), ' expected ans: [9,10,9,8,7]')
print('input 0, 3, 10: output', winning_seq(0, 3, 10), ' expected ans: -1')
print('input 5, 30, 10: output', winning_seq(5, 30, 10), ' expected ans: -1')
print('input 10, 3, 10: output', winning_seq(10, 3, 10), ' expected ans: [8,9,10,9,8,7,6,5,4,3]')
print('input 10, 3, 10: output', winning_seq(12, 3, 10), ' expected ans: [6,7,8,9,10,9,8,7,6,5,4,3]')
print('input 9, 3, 10: output', winning_seq(9, 3, 10), ' expected ans: [9,10,9,8,7,6,5,4,3]')
print('input 10, 3, 10: output', winning_seq(15, 3, 10), ' expected ans: [3,4,5,6,7,8,9,10,9,8,7,6,5,4,3]')