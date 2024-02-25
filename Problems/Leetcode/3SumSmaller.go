package main

import (
  "fmt"
  "slices"
)

func searchTriplets(arr []int, target int) int {
  slices.Sort(arr)

  count := 0
  n := len(arr)

  for l := 0; l < n-2; l++ {
    m := l+1
    r := n-1

    for m < r {
      currentSum := arr[l] + arr[m] + arr[r]

      if currentSum >= target {
        r--
      } else {
        count += r - m
        m++
      }
    }
  }

  return count
}

func main() {
  nums := []int{-1, 4, 2, 1, 3}
  target := 5
  triplets := searchTriplets(nums, target)
  fmt.Printf("- triplets: %d\n", triplets)
}

