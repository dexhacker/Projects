package main

import (
	"fmt"
	"sync"
	"time"
)

type SimpleData struct {
	ID int
}

func Work(allData []SimpleData) {
	start := time.Now()
	for _, data := range allData {
		Process(data)
	}
	elapsed := time.Since(start)
	fmt.Printf("Took ===============> %s\n", elapsed)
}

func NotPooledWork(allData []SimpleData) {
	start := time.Now()

	var wg sync.WaitGroup

	dataCh := make(chan SimpleData, 100)

	wg.Add(1)

	go func() {
		defer wg.Done()

		for data := range dataCh {
			wg.Add(1)

			go func(data SimpleData) {
				defer wg.Done()
				Process(data)
			}(data)
		}
	}()

	for _, data := range allData {
		dataCh <- data
	}

	close(dataCh)
	wg.Wait()
	elapsed := time.Since(start)
	fmt.Printf("Took ===============> %s\n", elapsed)
}

func PolledWork(allData []SimpleData) {
	start := time.Now()

	var wg sync.WaitGroup
	workedPoolSize := 100

	dataCh := make(chan SimpleData, workedPoolSize)

	for i := 0; i < workedPoolSize; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()

			for data := range dataCh {
				Process(data)
			}
		}()
	}

	for _, data := range allData {
		dataCh <- data
	}

	close(dataCh)
	wg.Wait()

	elapsed := time.Since(start)
	fmt.Printf("Took ===============> %s\n", elapsed)
}

func Process(data SimpleData) {
	//fmt.Printf("Start processing %d\n", data.ID)
	time.Sleep(100 * time.Millisecond)
	//fmt.Printf("Finish processing %d\n", data.ID)
}

func main() {
	var allData []SimpleData
	for i := 0; i < 1000; i++ {
		data := SimpleData{ID: i}
		allData = append(allData, data)
	}
	fmt.Printf("Start processing all work \n")

	//Work(allData)
	//NotPooledWork(allData)
	PolledWork(allData)
}
