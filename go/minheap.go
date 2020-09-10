package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type MinHeap struct {
	Element []int
}

func NewMinHeap() *MinHeap {
	h := &MinHeap{
		Element: []int{math.MinInt64},
	}
	return h
}

func (H *MinHeap) Insert(v int) {
	H.Element = append(H.Element, v)
	i := len(H.Element) - 1
	for ; H.Element[i/2] > v; i /= 2 {
		H.Element[i] = H.Element[i/2]
	}
	H.Element[i] = v
}

// 删除并返回最小值
func (H *MinHeap) DeleteMin() (int, error) {
	if len(H.Element) <= 1 {
		return 0, fmt.Errorf("MinHeap is empty")
	}
	minElement := H.Element[1]
	lastElement := H.Element[len(H.Element)-1]
	var i, child int
	for i = 1; i*2 < len(H.Element); i = child {
		child = i * 2
		if child < len(H.Element)-1 && H.Element[child+1] < H.Element[child] {
			child++
		}
		// 下滤一层
		if lastElement > H.Element[child] {
			H.Element[i] = H.Element[child]
		} else {
			break
		}
	}
	H.Element[i] = lastElement
	H.Element = H.Element[:len(H.Element)-1]
	return minElement, nil
}

// 堆的大小
func (H *MinHeap) Length() int {
	return len(H.Element) - 1
}

// 获取最小堆的最小值
func (H *MinHeap) Min() (int, error) {
	if len(H.Element) > 1 {
		return H.Element[1], nil
	}
	return 0, fmt.Errorf("heap is empty")
}

// MinHeap格式化输出
func (H *MinHeap) String() string {
	return fmt.Sprintf("%v", H.Element[1:])
}

func main() {
	H := NewMinHeap()
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)
	for i := 0; i < 20; i++ {
		H.Insert(r1.Intn(20))
	}
	for H.Length() > 0 {
		v, _ := H.DeleteMin()
		fmt.Println(v)
	}

}
