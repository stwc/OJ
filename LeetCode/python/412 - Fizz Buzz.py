class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        for num in range(1, n + 1):
            answer = ""
            if num % 3 == 0:
                answer += "Fizz"
            if num % 5 == 0:
                answer += "Buzz"
            if num % 3 != 0 and num % 5 != 0:
                answer += str(num)
            result.append(answer)
        return result
