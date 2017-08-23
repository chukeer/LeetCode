package main

import "fmt"

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if len(obstacleGrid) <= 0 || len(obstacleGrid[0]) <= 0 {
		return 0
	}

	numArr := make([][]int, len(obstacleGrid))
	for i := 0; i < len(numArr); i++ {
		numArr[i] = make([]int, len(obstacleGrid[0]))
	}

	if obstacleGrid[0][0] == 0 {
		numArr[0][0] = 1
	}
	for i := 1; i < len(numArr); i++ {
		if obstacleGrid[i][0] == 0 {
			numArr[i][0] = numArr[i-1][0]
		}
	}
	for i := 1; i < len(numArr[0]); i++ {
		if obstacleGrid[0][i] == 0 {
			numArr[0][i] = numArr[0][i-1]
		}
	}

	for i := 1; i < len(numArr); i++ {
		for j := 1; j < len(numArr[0]); j++ {
			if obstacleGrid[i][j] == 1 {
				continue
			}
			if obstacleGrid[i-1][j] == 1 {
				if obstacleGrid[i][j-1] != 1 {
					numArr[i][j] = numArr[i][j-1]
				}
			} else if obstacleGrid[i][j-1] == 1 {
				if obstacleGrid[i-1][j] != 1 {
					numArr[i][j] = numArr[i-1][j]
				}
			} else {
				numArr[i][j] = numArr[i-1][j] + numArr[i][j-1]
			}
		}
	}

	return numArr[len(numArr)-1][len(numArr[0])-1]
}

func main() {
	//num := make([][]int, 3)
	//num[0] = []int{0, 0, 0}
	//num[1] = []int{0, 1, 0}
	//num[2] = []int{0, 0, 0}
	num := make([][]int, 1)
	num[0] = []int{1, 0}

	fmt.Println(uniquePathsWithObstacles(num))
}
