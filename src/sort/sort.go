package main

import (
	"fmt"
	"math/rand"
)

func qsort(nums []int, left, right int, ifrandom bool) {
	if left < right {
		i, j := left, right
		if ifrandom {
			randidx := rand.Intn(right-left+1) + left
			nums[left], nums[randidx] = nums[randidx], nums[left]
		}
		anchor := nums[left]
		for i < j {
			for i < j && nums[j] > anchor {
				j--
			}
			if i < j {
				nums[i] = nums[j]
				i++
			}
			for i < j && nums[i] < anchor {
				i++
			}
			if i < j {
				nums[j] = nums[i]
				j--
			}
		}
		nums[i] = anchor
		qsort(nums, left, i-1, ifrandom)
		qsort(nums, i+1, right, ifrandom)
		
	}
}

func main() {
	nums := []int{1, 5, 7, 3, 9, 4, 0}
	qsort(nums, 0, len(nums)-1, true)
	fmt.Println(nums)
}
