package main

import (
	"errors"
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type Result struct {
	index  int
	result string
	retry int
}
type Job = func() (string, error)

func main() {
	var tasks []func() (string, error)
	for i := 0; i < 200; i++ {
		tasks = append(tasks, coding)
	}
	results := ConcurrentRetry(tasks, 20, 2)

	for r := range(results) {
		fmt.Println("Result received from thread: ", r)
	}
}

func coding() (string, error) {
	x := rand.Intn(100)
	duration := time.Duration(rand.Intn(1e3)) * time.Millisecond
	time.Sleep(duration)
	if x >= 50 {
		return "Error", errors.New("Error")
	}
	return "Passed", nil
}

func worker(ID int, threads <-chan Job, results chan<- Result, Retry int, waitingFor *sync.WaitGroup) {
	//code here
	for job := range threads{
		var r Result
		for i:=0; i < Retry; i++{
			str, e := job()

			r = Result{
				index: ID,
				result: str,
				retry: i+1,
			}

			if e == nil{
				break
			}
		}
		results <- r
	}
	waitingFor.Done()
}

func ConcurrentRetry(tasks []func() (string, error), concurrent int, retry int) <-chan Result {
	threads := make(chan Job, len(tasks))
	results := make(chan Result, len(tasks))

	var waitingFor sync.WaitGroup
	//Concurrent Workers
	for x := 1; x <= concurrent; x++ {
		go worker(x, threads, results, len(tasks), &waitingFor)
	}
	for _, job := range tasks { 
		threads <- job
	}
	for { 
		if len(threads) == 0 {
				close(threads)
				break
		}
	}

	return results
}
