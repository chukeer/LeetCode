package main

import "fmt"

func uniquePaths(m int, n int) int {
	if m <= 0 || n <= 0 {
		return 0
	}

	numArr := make([][]int, m)
	for i := 0; i < m; i++ {
		numArr[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		numArr[i][0] = 1
	}
	for i := 0; i < n; i++ {
		numArr[0][i] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			numArr[i][j] = numArr[i-1][j] + numArr[i][j-1]
		}
	}

	return numArr[m-1][n-1]
}

func main() {
	fmt.Print(3, 4, uniquePaths(3, 4))
}
