package main

import (
	"fmt"
	"sync"
)

type student struct {
	name  string
	score int
}

func main() {
	var wg sync.WaitGroup
	wg.Add(3)

	state1 := make(chan student)
	state2 := make(chan student)
	state3 := make(chan student)

	go func() {
		defer wg.Done()
		score := 0
		max := student{}

		for i := 0; i < 6; i++ {
			s := student{}
			fmt.Scanf("%s %d", &s.name, &s.score)
			score = score + s.score
			if s.score > max.score {
				max = s
			}
			state1 <- s
		}
		fmt.Println("In State1: Student", max.name, "has scored Maximum mark")
	}()

	go func() {
		defer wg.Done()
		score := 0
		avg := 0.0
		for i := 0; i < 6; i++ {
			s := <-state1
			score = score + s.score
		}
		avg = float64(score) / float64(6)
		fmt.Println("In State2: Average score is", avg)
	}()

	go func() {
		defer wg.Done()
		for i := 0; i < 6; i++ {
			s := <-state1
			if s.score < 120 {
				state3 <- s
			}
		}
		fmt.Println("In State3:", len(state3), "students have not taken retest")
	}()

	wg.Wait()
}
