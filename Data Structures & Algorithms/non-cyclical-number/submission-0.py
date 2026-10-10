class Solution:
    def isHappy(self, n: int) -> bool:
        def compute_sum_of_squares(current_number: int) -> int:
            total_sum = 0
            while current_number > 0:
                current_number, remainder = divmod(current_number, 10)
                total_sum += remainder * remainder
            return total_sum

        slow_runner = n
        fast_runner = compute_sum_of_squares(n)

        while fast_runner != 1 and slow_runner != fast_runner:
            slow_runner = compute_sum_of_squares(slow_runner)
            fast_runner = compute_sum_of_squares(compute_sum_of_squares(fast_runner))

        return fast_runner == 1