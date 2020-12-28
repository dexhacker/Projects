package main

import (
	"Projects/Go/Parallelism2/workerpool"
	"fmt"
	"time"
)

func main() {
	var allTask []*workerpool.Task
	for i := 1; i <= 100; i++ {
		task := workerpool.NewTask(func(data interface{}) error {
			taskID := data.(int)
			time.Sleep(100 * time.Millisecond)
			fmt.Printf("Task %d processed\n", taskID)
			return nil
		}, i)
		allTask = append(allTask, task)
	}

	pool := workerpool.NewPool(allTask, 5)
	pool.Run()
}

// https://proglib.io/p/parallelizm-v-golang-i-workerpool-chast-2-2020-12-26
