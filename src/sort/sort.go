package main

import "fmt"

func qsort(nums []int, left, right int) {
	if left < right {
		i, j := left, right
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
		qsort(nums, left, i-1)
		qsort(nums, i+1, right)
	}
}
func main() {
	nums := []int{1, 5, 7, 3, 9, 4, 0}
	qsort(nums, 0, len(nums)-1)
	fmt.Println(nums)
	a := []int{1, 3, 4, 5}
	b := a
	fmt.Println(type b)
	b[0] = 0
	fmt.Println(copy(b, a))
	fmt.Println(a[0])
}
