class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        low, high = float(inf), float(-inf)
        totalArea = 0

        for x,y,l in squares:
            totalArea += l*l
            low = min(low,y)
            high = max(high, y+l)

        target = totalArea / 2.0
        
        for i in range(60):
            mid = low + (high - low)/2.0
            currentArea = 0
            
            for x,y,l in squares:
                currentY = max(0,min(l,mid-y))
                currentArea += l * currentY

            if currentArea < target:
                low = mid
            else:
                high = mid

        return mid