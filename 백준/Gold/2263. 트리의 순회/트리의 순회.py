import sys

sys.setrecursionlimit(10 ** 6)


def solution(in_order_start, in_order_end, post_order_start, post_order_end):
	if in_order_start > in_order_end or post_order_start > post_order_end:
		return

	root = post_order[post_order_end]
	root_index = root_index_dict[root]
	print(root, end=" ")

	in_order_len = root_index - in_order_start
	# left
	solution(in_order_start, root_index - 1, post_order_start, post_order_start + in_order_len - 1)

	# right
	solution(root_index + 1, in_order_end, post_order_start + in_order_len, post_order_end - 1)


if __name__ == '__main__':
	n = int(input())
	in_order = list(map(int, sys.stdin.readline().rsplit()))
	post_order = list(map(int, sys.stdin.readline().rsplit()))
	root_index_dict = dict()
	for i in range(n):
		root_index_dict[in_order[i]] = i

	solution(0, n - 1, 0, n - 1)