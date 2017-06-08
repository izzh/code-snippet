package main

import (
    "sync"
    "time"
    "fmt"
)

func main() {
    var wg sync.WaitGroup

    for i:=0; i<10; i++ {
        wg.Add(1)

        go func(id int) {
            defer wg.Done()

            time.Sleep(time.Second)
            fmt.Printf("goroutine %d done\n", id)
        } (i)
    }

    fmt.Printf("main\n")
    wg.Wait()
    fmt.Printf("main...\n")
}
