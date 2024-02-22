package main

import "fmt"

func twoSum(nums []int, target int) []int {
	res := []int{-1, -1}
	m := make(map[int]int)

	for i, v := range nums {
		comp := target - v

		if _, ok := m[comp]; ok {
			res[0] = m[comp]
			res[1] = i
			break
		}

		m[v] = i
	}

	return res
}

func main() {
	nums := []int{1, 32, 9, -5, 8}

	fmt.Println(twoSum(nums, 17))
	fmt.Println(twoSum(nums, 3))
	fmt.Println(twoSum(nums, -4))
	fmt.Println(twoSum(nums, 8))

}
