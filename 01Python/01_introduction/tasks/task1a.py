def count_fours(lst):
    count = 0
    for num in lst:
        if num == 4:
            count += 1
    return count

example_list = [1, 4, 6, 4, 7, 4, 9]
print(f"Number of 4's in the list: {count_fours(example_list)}")


