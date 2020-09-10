package main

import (
	"fmt"
)

func heapify(nums []int, low, high int) {
	i := low
	j := 2 * i
	tmp := nums[i]
	for j <= high {
		if j < high && nums[j] < nums[j+1] {
			j++
		}
		if tmp < nums[j] {
			nums[i] = nums[j]
			i = j
			j = 2 * i
		} else {
			break
		}
	}
	nums[i] = tmp
}

func sort(nums []int, n int) {
	var i int
	for i := n / 2; i >= 1; i-- {
		heapify(nums, i, n)
	}
	for i = n - 1; i >= 1; i-- {
		nums[i], nums[1] = nums[1], nums[i]
		heapify(nums, 1, i-1)
	}
}

func main() {
	nums := []int{3, 5, 7, 2, 6, 1, 0, 9, 8}
	sort(nums, len(nums))
	fmt.Print(nums)
}
