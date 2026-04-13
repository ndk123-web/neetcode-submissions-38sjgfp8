class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        # Objective function: f(x) = x^2
        # Derivative:         f'(x) = 2x
        # Update rule:        x = x - learning_rate * f'(x)
        # Round final answer to 5 decimal places

        w = init  
        for i in range(iterations):
            loss = w ** 2
            dLoss_by_dw = 2 * w

            w = w - (learning_rate * dLoss_by_dw)
        
        return round(w, 5) 