class Pair(object):
	def __init__(self, a, b):
		self.l = a
		self.r = b

	def can_union(self, other):
		if other.r == self.r + 1 or other.l == self.r + 1:
			return True
		return False

	def union(self, right):
		self.l = min(self.l, right.l)
		self.r = max(self.r, right.r)

class Solution(object):
	def longestValidParentheses(self, s):
		cur_stack = []
		pair_stack = []
		idx = 0
		max_v = 0
		cur_len = 0
		pair_len = 0
		for i in s:
			if i == '(':
				cur_stack.append(idx)
				cur_len += 1
			else:
				if cur_len:
					cur_pair = Pair(cur_stack.pop(), idx)
					cur_len -= 1
					while pair_len:
						near_pair = pair_stack[-1]
						if near_pair.can_union(cur_pair):
							pair_len -= 1
							cur_pair.union(pair_stack.pop())
						else:
							break
					max_v = max(max_v, cur_pair.r - cur_pair.l + 1)
					pair_stack.append(cur_pair)
					pair_len += 1
			idx += 1
		return max_v
